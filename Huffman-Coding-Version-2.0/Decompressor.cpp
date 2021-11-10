#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
using namespace std;

const unsigned char check=0b10000000;

struct translation{
    translation *zero,*one;
    unsigned char character;
};

bool this_is_a_file(unsigned char&,int&,FILE*);
long int read_file_size(unsigned char&,int,FILE*);
void write_file_name(char*,int,unsigned char&,int&,translation*,FILE*);
void translate_file(char*,long int,unsigned char&,int&,translation*,FILE*);
void translate_folder(string,unsigned char&,int&,FILE*,translation*);


unsigned char process_8_bits_NUMBER(unsigned char&,int,FILE*);
void process_n_bits_TO_STRING(unsigned char&,int,int&,FILE*,translation*,unsigned char);

bool file_exists(char*);
void change_name_if_exists(char*);

void burn_tree(translation*);



/*          CONTENT TABLE IN ORDER
    compressed file's composition is in order below
    that is why we re going to translate it part by part

.first (one byte)           ->  letter_count
.second (bit group)
    2.1 (one byte)          ->  password_length
    2.2 (bytes)             ->  password (if password exists)
.third (bit groups)
    3.1 (8 bits)            ->  current unique byte
    3.2 (8 bits)            ->  length of the transformation
    4.3 (bits)              ->  transformation code of that unique byte

.fourth (2 bytes)**         ->  file_count
    .fifth (1 bit)*         ->  file or folder information  ->  folder(0) file(1)
    .sixth (8 bytes)        ->  size of current file (IF FILE)
    .seventh (bit group)
        7.1 (8 bits)        ->  length of current file's or folder's name
        7.2 (bits)          ->  translate and write current file's or folder's name
    .eighth (a lot of bits) ->  translate and write current file (IF FILE)

*whenever we see a new folder we will write seventh then 
    start writing the files(and folders) inside the current folder from fourth to eighth
**groups from fifth to eighth will be written as much as the file count
*/







int main(int argc,char *argv[]){
    int letter_count=0,password_length=0;
    FILE *fp_compressed,*fp_new;    
    // Se asegura de que el archivo exista y que si se haya ingresado algun argumento
    if(argc==1){
        cout<<"Missing file name"<<endl<<"try './extract {{file_name}}'"<<endl;
        return 0;
    }
    fp_compressed=fopen(argv[1],"rb");
    if(!fp_compressed){
        cout<<argv[1]<<" does not exist"<<endl;
        return 0;
    }



    //---------reads .first-----------
    fread(&letter_count,1,1,fp_compressed);
    if(letter_count==0)letter_count=256;
    //-------------------------------



    //-----------------reads .second--------------------
        // Este bloque se encarga de analizar si la contraseña es la correcta
    fread(&password_length,1,1,fp_compressed);
    if(password_length){
        char real_password[password_length+1],password_input[257];
        fread(real_password,1,password_length,fp_compressed);
        real_password[password_length]=0;
        cout<<"Enter password:";
        cin>>password_input;
        char *rp=real_password,*pi=password_input;
        for(;*rp&&*pi;rp++,pi++){
            if(*rp!=*pi){          // Analiza cada parte de la contraseña ingresada para ver si es la correcta.
                cout<<"Wrong password"<<endl;
                fclose(fp_compressed);
                return 0;
            }
        }
        if(*rp!=*pi){
            cout<<"Wrong password"<<endl;
            fclose(fp_compressed);
            return 0;
        }
        cout<<"Correct Password"<<endl;
    }
    //--------------------------------------------------



    //----------------reads .third---------------------
        // Almacena la informacion de la transformacion en un arbol binario para usar despues
    unsigned char current_byte=0,current_character;
    int current_bit_count=0,len;
    translation *root=(translation*)malloc(sizeof(translation));  // La raíz
    root->zero=NULL; // Los hijos
    root->one=NULL;

    for(int i=0;i<letter_count;i++){
        current_character=process_8_bits_NUMBER(current_byte,current_bit_count,fp_compressed);
        len=process_8_bits_NUMBER(current_byte,current_bit_count,fp_compressed);
        if(len==0)len=256;
        process_n_bits_TO_STRING(current_byte,len,current_bit_count,fp_compressed,root,current_character);
    }
    //--------------------------------------------------













    // ---------reads .fourth----------
        // Lee cuantos archivos o folders el programa va a crear dentro del main folder
    int file_count;
    file_count=process_8_bits_NUMBER(current_byte,current_bit_count,fp_compressed);
    file_count+=256*process_8_bits_NUMBER(current_byte,current_bit_count,fp_compressed);
        // File count va a ser escrito en en el archivo comprimido desde el archivo menos significativo  
        // hasta el mas significativo para asegurar el endianness      
        // Esto no afecta el proceso y es por esto que se usa para procesar el tamaño del archivo
    // --------------------------------



    for(int current_file=0;current_file<file_count;current_file++){

        if(this_is_a_file(current_byte,current_bit_count,fp_compressed)){   // Lee .fifth e ingresa si es un archivo

            long int size=read_file_size(current_byte,current_bit_count,fp_compressed);  // Lee .sixth

            //---------------translates .seventh---------------------
            int file_name_length=process_8_bits_NUMBER(current_byte,current_bit_count,fp_compressed);
            char newfile[file_name_length+4];
            write_file_name(newfile,file_name_length,current_byte,current_bit_count,root,fp_compressed);
            change_name_if_exists(newfile);
            //--------------------------------------------------

            translate_file(newfile,size,current_byte,current_bit_count,root,fp_compressed); //Traduce .eighth
        }
        else{   //Si es una carpeta
            //---------------translates .seventh---------------------
            int file_name_length=process_8_bits_NUMBER(current_byte,current_bit_count,fp_compressed);
            char newfile[file_name_length+4];
            write_file_name(newfile,file_name_length,current_byte,current_bit_count,root,fp_compressed);
            change_name_if_exists(newfile);
            //--------------------------------------------------
            mkdir(newfile,0755);
            string folder_name=newfile;
            translate_folder(folder_name,current_byte,current_bit_count,fp_compressed,root);
        }
    }


    fclose(fp_compressed);
    burn_tree(root);
    cout<<"Decompression is complete"<<endl;
}



// Esta funcion sirve para crear archivos y carpetas dentro de una direccion dada
// usando informacion del archivo comprimido
    // Cuando crea otro archivo se va a llamar recursivamente con la direccion del nuevo camino
    // Y de esta forma traduce el archivo comprimido
void translate_folder(string path,unsigned char &current_byte,int &current_bit_count,FILE *fp_compressed,translation *root){
    path+='/';
    string new_path;
    
    // ---------reads .fourth----------
        //Lee cuantas carpetas/archivos el programa debe crear dentro de la carpeta actual
    int file_count;
    file_count=process_8_bits_NUMBER(current_byte,current_bit_count,fp_compressed);
    file_count+=256*process_8_bits_NUMBER(current_byte,current_bit_count,fp_compressed);
    // --------------------------------



    for(int current_file=0;current_file<file_count;current_file++){
        if(this_is_a_file(current_byte,current_bit_count,fp_compressed)){   //Revisa .fifth 
            long int size=read_file_size(current_byte,current_bit_count,fp_compressed);  // Lee .sixth

            //---------------translates .seventh---------------------
            int file_name_length=process_8_bits_NUMBER(current_byte,current_bit_count,fp_compressed);
            char newfile[file_name_length+4];
            write_file_name(newfile,file_name_length,current_byte,current_bit_count,root,fp_compressed);
            //--------------------------------------------------

            new_path=path+newfile;
            translate_file(&new_path[0],size,current_byte,current_bit_count,root,fp_compressed); //Traduce .eighth
        }
        else{   //Si es una carpeta
            //---------------translates .seventh---------------------
            int file_name_length=process_8_bits_NUMBER(current_byte,current_bit_count,fp_compressed);
            char newfile[file_name_length+4];
            write_file_name(newfile,file_name_length,current_byte,current_bit_count,root,fp_compressed);
            //--------------------------------------------------
            new_path=path+newfile;
            mkdir(&new_path[0],0755);
            translate_folder(new_path,current_byte,current_bit_count,fp_compressed,root);
        }
    }

}


// La funcion burn_tree es usado para desasignar el translation tree
void burn_tree(translation *node){
    if(node->zero)burn_tree(node->zero);
    if(node->one)burn_tree(node->one);
    free(node);
}



// la funcion process_n_bits_TO_STRING lee n bits sucesivos del archivo comprimido
// y los guarda en las hojas del translation tree
// Despues de crear las ojas y en algunos casos nodos que estan vinculados con las hojas del arbol
void process_n_bits_TO_STRING(unsigned char &current_byte,int n,int &current_bit_count,FILE *fp_read,translation *node,unsigned char uChar){
    for(int i=0;i<n;i++){
        if(current_bit_count==0){
            fread(&current_byte,1,1,fp_read);
            current_bit_count=8;
        }

        switch(current_byte&check){       // un and entre current_byte y check
            case 0:
            if(!(node->zero)){
                node->zero=(translation*)malloc(sizeof(translation));
                node->zero->zero=NULL;
                node->zero->one=NULL;
            }
            node=node->zero;
            break;
            case 128:
            if(!(node->one)){
                node->one=(translation*)malloc(sizeof(translation));
                node->one->zero=NULL;
                node->one->one=NULL;
            }
            node=node->one;
            break;
        }
        current_byte<<=1;     // Asignación con desplazamiento a la izquierda de uno
        current_bit_count--;
    }
    node->character=uChar;
}



//process_8_bits_NUMBER lee 8 bits sucesivos del archivo comprimido
    //(no tiene que estar en el mismo byte)
// Y retorna su forma unsigned char
unsigned char process_8_bits_NUMBER(unsigned char &current_byte,int current_bit_count,FILE *fp_read){
    unsigned char val,temp_byte;
    fread(&temp_byte,1,1,fp_read);
    val=current_byte|(temp_byte>>current_bit_count);    // Hace un or entre curreny_byte y el desplazamiento a la derecha temp_byte y current_bit_count
    current_byte=temp_byte<<8-current_bit_count;        // current_byte se convierte en el resultado de aplicar un desplazamiento de temp_byte y 8 - current_bit_count
    return val;
}



//Revisa si es un archivo o carperta
    // 1 Si es un archivo
    // 0 Si es una carpeta
bool this_is_a_file(unsigned char &current_byte,int &current_bit_count,FILE *fp_compressed){
    bool val;
    if(current_bit_count==0){
        fread(&current_byte,1,1,fp_compressed);
        current_bit_count=8;
    }
    val=current_byte&check;
    current_byte<<=1;
    current_bit_count--;
    return val;
}



void change_name_if_exists(char *name){
    char *i;
    int copy_count;
    if(file_exists(name)){
        char *dot_pointer=NULL;
        for(i=name;*i;i++){
            if(*i=='.')
            dot_pointer=i;
        }
        if(dot_pointer){
            string s=dot_pointer;
            strcpy(dot_pointer,"(1)");
            dot_pointer++;
            strcpy(dot_pointer+2,&s[0]);
        }
        else{
            dot_pointer=i;
            strcpy(dot_pointer,"(1)");
            dot_pointer++;
        }
        for(copy_count=1;copy_count<10;copy_count++){
            *dot_pointer=(char)('0'+copy_count);
            if(!file_exists(name)){
                break;
            }
        }
    }
}



// Revisa si el archivo o carpeta existe
bool file_exists(char *name){
    FILE *fp=fopen(name,"rb");
    if(fp){
        fclose(fp);
        return 1;
    }
    else{
        DIR *dir=opendir(name);
        if(dir){
            closedir(dir);
            return 1;
        }
    }
    return 0;
}

// retorna el tamaño del archivo
long int read_file_size(unsigned char &current_byte,int current_bit_count,FILE *fp_compressed){
    long int size=0;
    {
        long int multiplier=1;
        for(int i=0;i<8;i++){
            size+=process_8_bits_NUMBER(current_byte,current_bit_count,fp_compressed)*multiplier;
            multiplier*=256;
        }
    }
    return size;
    // El tamaño fue escrito en el archivo comprimido en el byte menos significativo
    // Al mas significativo para asegurar el endianness del sistema
    // Esto no afecta el proceso y es por esto que el tamaño se maneja de esta forma
}



// Desifra el nombre del archivo actual y lo escribe en el char array del nuevo archivo
void write_file_name(char *newfile,int file_name_length,unsigned char &current_byte,int &current_bit_count,translation *root,FILE *fp_compressed){
    translation *node;
    newfile[file_name_length]=0;
    for(int i=0;i<file_name_length;i++){
            node=root;
            while(node->zero||node->one){
                if(current_bit_count==0){
                    fread(&current_byte,1,1,fp_compressed);
                    current_bit_count=8;
                }
                if(current_byte&check){
                    node=node->one;
                }
                else{
                    node=node->zero;
                }
                current_byte<<=1;           
                current_bit_count--;
            }
            newfile[i]=node->character;
        }
}



// This function translates compressed file from info that is now stored in the translation tree                    Esta funcion traduce el archivo comprimido de informacion y ahora se guarda en un translation 
    // Despues escribe en un nuevo archivo
void translate_file(char *path,long int size,unsigned char &current_byte,int &current_bit_count,translation *root,FILE *fp_compressed){
    translation *node;
    FILE *fp_new=fopen(path,"wb");  // Abre el archivo solo para escritura (borra el contenido anterior si hay uno con el mismo nombre)
    for(long int i=0;i<size;i++){
        node=root;
        while(node->zero||node->one){     // un or logico entre los hijos del nodo
            if(current_bit_count==0){
                fread(&current_byte,1,1,fp_compressed);
                current_bit_count=8;
            }
            if(current_byte&check){           // and logico entre current_byte y check
                node=node->one;
            }
            else{
                node=node->zero;
            }
            current_byte<<=1;           
            current_bit_count--;
        }
        fwrite(&(node->character),1,1,fp_new);
    }
        fclose(fp_new);
}