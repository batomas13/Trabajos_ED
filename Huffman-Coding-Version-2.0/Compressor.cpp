#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>//
#include <cstdlib>
#include <cstring>
#include <dirent.h>//

/**
 *  The <dirent.h> header defines the following data type through typedef:
 *  DIR
 *  A type representing a directory stream. 
 *  It also defines the structure dirent which includes the following members: 
*/

using namespace std;


void write_from_uChar(unsigned char,unsigned char&,int,FILE*); 
int this_is_not_a_folder(char*);
long int size_of_the_file(char*);
void count_in_folder(string,long int*,long int&,long int&); 
void write_file_count(int,unsigned char&,int,FILE*);
void write_file_size(long int,unsigned char&,int,FILE*);
void write_file_name(char*,string*,unsigned char&,int&,FILE*); 
void write_the_file_content(FILE*,long int,string*,unsigned char&,int&,FILE*);
void write_the_folder(string,string*,unsigned char&,int&,FILE*);


/*          CONTENT TABLE IN ORDER
---------PART 1-CALCULATING TRANSLATION INFO----------
Important Note:4 and 5 are the most important parts of this algorithm
If you dont know how Huffman's algorithm works I really recommend you
to check this link before you continue:
https://en.wikipedia.org/wiki/Huffman_coding#Basic_technique

1-Size information
2-Counting usage frequency of unique bytes and unique byte count
3-Creating the base of the translation array
4-Creating the translation tree inside the translation array by weight distribution
5-adding strings from top to bottom to create translated versions of unique bytes

---------PART 2-CREATION OF COMPRESSED FILE-----------
    Compressed File's structure had been documented below

first (one byte)            ->  letter_count
second (bit group)
    2.1 (one byte)          ->  password_length
    2.2 (bytes)             ->  password (if password exists)
third (bit groups)
    3.1 (8 bits)            ->  current unique byte
    3.2 (8 bits)            ->  length of the transformation
    3.3 (bits)              ->  transformation code of that unique byte

fourth (2 bytes)**          ->  file_count (inside the current folder)
    fifth (1 bit)*          ->  file or folder information  ->  folder(0) file(1)
    sixth (8 bytes)         ->  size of current input_file (IF FILE)
    seventh (bit group)
        7.1 (8 bits)        ->  length of current input_file's or folder's name
        7.2 (bits)          ->  transformed version of current input_file's or folder's name
    eighth (a lot of bits)  ->  transformed version of current input_file (IF FILE)

*whenever we see a new folder we will write seventh then start writing from fourth to eighth
**groups from fifth to eighth will be written as much as file count in that folder
    (this is argument_count-1(argc-1) for the main folder)
*/


/**
 * Estructura se encarga para traducir el arbol que se genera con el codigo de huffman 
 * La estructura tiene 
 * 
*/

struct ersel{ 
    ersel *left,*right;
    long int number;
    unsigned char character;
    string bit;
};

//Este 

bool erselcompare0(ersel a,ersel b){
    return a.number<b.number;
}


int main(int argc,char *argv[]){
    long int number[256];
    long int total_bits=0;
    int letter_count=0;
    if(argc==1){
        cout<<"Missing file name"<<endl<<"try './archive {{file_name}}'"<<endl;
        return 0;
    }
    for(long int *i=number;i<number+256;i++){                       
        *i=0;
    }
    
    string scompressed;
    FILE *original_fp,*compressed_fp;

    for(int i=1;i<argc;i++){                    //Revisa si el archivo a ingresar es valido
        if(this_is_not_a_folder(argv[i])){
            original_fp=fopen(argv[i],"rb");
            if(!original_fp){
                cout<<argv[i]<<" file does not exist"<<endl<<"Process has been terminated"<<endl;
                return 0;
            }
            fclose(original_fp);
        }
    }

    scompressed=argv[1];
    scompressed+=".compressed";

/* **
 * ------------------1 and 2--------------------
 * Esta seccion de codigo cuenta el numero de veces que un unico byte es usado en los archivos,
 * nombres de archivos y carpetas, guarda la informacion en un arreglo number
 * El siguiente bloque de codigo, se revisar el arreglo y escribe el contador de bytes unicos en letter_count 
 * **/

    unsigned char *x_p,x;                  //Variables temporales para tomar la informacion desde el archivo
    x_p=&x;
    long int total_size=0,size;
    total_bits+=16+9*(argc-1);
    for(int current_file=1;current_file<argc;current_file++){

        for(char *c=argv[current_file];*c;c++){        //Cuenta la frecuencia de uso de bytes unicos en el nombre del archivo o carpeta
            number[(unsigned char)(*c)]++;
        }

        if(this_is_not_a_folder(argv[current_file])){
            total_size+=size=size_of_the_file(argv[current_file]);
            total_bits+=64;

            original_fp=fopen(argv[current_file],"rb");
            fread(x_p,1,1,original_fp);
            for(long int j=0;j<size;j++){    //Cuenta la frecuencia de uso de bytes unicos en el archivo
                number[x]++;
                fread(x_p,1,1,original_fp);
            }
            fclose(original_fp);

        }
        else{
            string temp=argv[current_file];
            count_in_folder(temp,number,total_size,total_bits);
        }        
    }
	for(long int *i=number;i<number+256;i++){                 
            if(*i){
			letter_count++;
			}
    }
    //---------------------------------------------
/* **
 * --------------------3------------------------
 * Crea la base de la traduccion y luego ordena las frecuencias en orden ascendente en el arreglo
 * este arreglo es del tipo "ersel" y no se va a usar despues de calcular las versiones transformadas para
 * byte unico, en su lugar la informacion es escrita en un nuevo arreglo string llamado str_arr
 * 
 * ***/
    ersel array[letter_count*2-1];
    ersel *e=array;
    for(long int *i=number;i<number+256;i++){                         
            if(*i){
                e->right=NULL;
                e->left=NULL;
                e->number=*i;
                e->character=i-number;
                e++;
            }
    }
    sort(array,array+letter_count,erselcompare0);
/***
 * ---------------------------------------------
 * min1 y min2 representa los nodos que tienen el menor peso
 * isleaf es un puntero que pasa por las hojas y notleaf
 * es el puntero que pasa por los nodos que no son hojas
 * Aca se comienza a crear el arbol
 * **/

    ersel *min1=array,*min2=array+1,*current=array+letter_count,*notleaf=array+letter_count,*isleaf=array+2;            
    for(int i=0;i<letter_count-1;i++){                           
        current->number=min1->number+min2->number;
        current->left=min1;
        current->right=min2;
        min1->bit="1";
        min2->bit="0";     
        current++;
        
        if(isleaf>=array+letter_count){
            min1=notleaf;
            notleaf++;
        }
        else{
            if(isleaf->number<notleaf->number){
                min1=isleaf;
                isleaf++;
            }
            else{
                min1=notleaf;
                notleaf++;
            }
        }
        
        if(isleaf>=array+letter_count){
            min2=notleaf;
            notleaf++;
        }
        else if(notleaf>=current){
            min2=isleaf;
            isleaf++;
        }
        else{
            if(isleaf->number<notleaf->number){
                min2=isleaf;
                isleaf++;
            }
            else{
                min2=notleaf;
                notleaf++;
            }
        }
        
    }

/**
 * Cada ciclo 2 de los nodos menos pesados se usaran para crear un nuevo nodo que 
 * va a guardar la suma de sus pesos combinados
 * ---------------------------------------------
 * **/
/***
 * -------------------5-------------------------
 * En este bloque se agregan los bytes desde las raiz a las hojas
 * una vez esto se ha acabado cada hoja se convertira en el string que corresponda
 */
    for(e=array+letter_count*2-2;e>array-1;e--){
        if(e->left){
            e->left->bit=e->bit+e->left->bit;
        }
        if(e->right){
            e->right->bit=e->bit+e->right->bit;
        }
        
    }
    //---------------------------------------------
    compressed_fp=fopen(&scompressed[0],"wb");
    int current_bit_count=0;
    unsigned char current_byte;
    //Obtenemos letter count:
    fwrite(&letter_count,1,1,compressed_fp);
    total_bits+=8;
    //----------------------------------------
    //Se le coloca una contraseña si se desea 
    {
        cout<<"If you want a password write any number other then 0"<<endl
            <<"If you do not, write 0"<<endl;
        int check_password;
        cin>>check_password;
        if(check_password){//si quiere contraseña
            string password;
            cout<<"Enter your password (Do not use whitespaces): ";
            cin>>password;
            int password_length=password.length();
            if(password_length==0){//si no ingreso contraseña
                cout<<"You did not enter a password"<<endl<<"Process has been terminated"<<endl;
                fclose(compressed_fp);
                remove(&scompressed[0]);
                return 0;
            }
            if(password_length>100){
                cout<<"Password cannot contain more then 100 characters"<<endl<<"Process has been terminated"<<endl;
                fclose(compressed_fp);
                remove(&scompressed[0]);
                return 0;
            }
            unsigned char password_length_unsigned=password_length;
            fwrite(&password_length_unsigned,1,1,compressed_fp);
            fwrite(&password[0],1,password_length,compressed_fp);
            total_bits+=8+8*password_length;
        }
        else{
            fwrite(&check_password,1,1,compressed_fp);
            total_bits+=8;
        }
    }
    //----------------------------------------
    /**
     * Se transforma el string en str_arr para que el proceso de comprimir sea más eficiente
     * 
     * */
    char *str_pointer; //Byte actual
    unsigned char len,current_character;
    string str_arr[256];
    for(e=array;e<array+letter_count;e++){
        str_arr[(e->character)]=e->bit;    //1
        len=e->bit.length();
        current_character=e->character;

        write_from_uChar(current_character,current_byte,current_bit_count,compressed_fp);
        write_from_uChar(len,current_byte,current_bit_count,compressed_fp);
        total_bits+=len+16;
        /**
         * Las lineas anteriores se usan para escribir el byte y el numero de bits que se van a necesitar
         * para representar los bytes de la nueva version 
         * */
        
        str_pointer=&e->bit[0];
        while(*str_pointer){
            if(current_bit_count==8){
                fwrite(&current_byte,1,1,compressed_fp);
                current_bit_count=0;
            }
            switch(*str_pointer){
                case '1':current_byte<<=1;current_byte|=1;current_bit_count++;break;
                case '0':current_byte<<=1;current_bit_count++;break;
                default:cout<<"An error has occurred"<<endl<<"Compression process aborted"<<endl;
                fclose(compressed_fp);
                remove(&scompressed[0]);
                return 1;
            }
            str_pointer++;
        }
        
        total_bits+=len*(e->number);
    }
    if(total_bits%8){
        total_bits=(total_bits/8+1)*8;        
        /**
         * En este momento total_bits no representa el total de bits, en su lugar
         * representa 8*number_of_bytes se va a ser usado en el archivo comprimido
         * **/
    }
    // El ciclo anterior escribe la traducion en el archivo comprimido y en el srt_arr
    //----------------------------------------


    cout<<"The size of the sum of ORIGINAL files is: "<<total_size<<" bytes"<<endl;
    cout<<"The size of the COMPRESSED file will be: "<<total_bits/8<<" bytes"<<endl;
    cout<<"Compressed file's size will be [%"<<100*((float)total_bits/8/total_size)<<"] of the original file"<<endl;
    if(total_bits/8>total_size){
        cout<<endl<<"COMPRESSED FILE'S SIZE WILL BE HIGHER THAN THE SUM OF ORIGINALS"<<endl<<endl;
    }
    cout<<"If you wish to abort this process write 0 and press enter"<<endl
        <<"If you want to continue write any other number and press enter"<<endl;
    int check;
    cin>>check;
    if(!check){
        cout<<endl<<"Process has been aborted"<<endl;
        fclose(compressed_fp);
        remove(&scompressed[0]);
        return 0;
    }
    //file_count 
    write_file_count(argc-1,current_byte,current_bit_count,compressed_fp);
    //---------------------------------------
    for(int current_file=1;current_file<argc;current_file++){
        
        if(this_is_not_a_folder(argv[current_file])){   //Si no es una carpeta 
            original_fp=fopen(argv[current_file],"rb");
            fseek(original_fp,0,SEEK_END);
            size=ftell(original_fp);
            rewind(original_fp);

            //Se obtiene la informacion del folder
            if(current_bit_count==8){
                fwrite(&current_byte,1,1,compressed_fp);
                current_bit_count=0;
            }
            current_byte<<=1;
            current_byte|=1;
            current_bit_count++;
            //---------------------------------------
            //Archivo actual or input_file
            write_file_size(size,current_byte,current_bit_count,compressed_fp);             //tamaño del archivo actual
            write_file_name(argv[current_file],str_arr,current_byte,current_bit_count,compressed_fp);   //tamaño del nombre del arhivo actual
            write_the_file_content(original_fp,size,str_arr,current_byte,current_bit_count,compressed_fp);      //Nueva version del archivo actual
            fclose(original_fp);
        }
        else{   //Si es una carpeta

            //pasa la informacion del folder o la carpeta
            if(current_bit_count==8){
                fwrite(&current_byte,1,1,compressed_fp);
                current_bit_count=0;
            }
            current_byte<<=1;
            current_bit_count++;
            //---------------------------------------

            write_file_name(argv[current_file],str_arr,current_byte,current_bit_count,compressed_fp);   //Nueva version comprimida

            string folder_name=argv[current_file];
            write_the_folder(folder_name,str_arr,current_byte,current_bit_count,compressed_fp);
        }
    }

    if(current_bit_count==8){      //Aca se escribe el ultimo byte del archivo
        fwrite(&current_byte,1,1,compressed_fp);
    }
    else{
        current_byte<<=8-current_bit_count;
        fwrite(&current_byte,1,1,compressed_fp);
    }
    fclose(compressed_fp);
    cout<<endl<<"Created compressed file: "<<scompressed<<endl;
    cout<<"Compression is complete"<<endl;
    
}

/* **
 * La siguiente funcion se usa para escribir un unsigned char llamado Uchar
 * No lo escribe directamente como un un byte, en su lugar mezcla el uChar y 
 * &current_byte, escribe 8 bits de todos los obtenidos y deja los demás en 
 * current_byte para usarlos después
 * **/

/* **
 * Aca se puede ver como se utiliza el corrimiento de bits en este algoritmo
 * 1-Realiza un corrimiento de 8 bits a la izquierda para asignar a current_bit_count
 *      el valor actual de current_byte
 * 2-Realiza un corrimiento a la derecha de 8 bits en uChar, pasando los bits de 
 *      current_bit_count a uChar. A current_byte y el resultado de ese corrimiento se 
 *      les aplica un or que es guardado en current_byte.
 * 3-Escribe los 8 bits
 * 4-Guarda los demás para ser usados despues
 * **/
void write_from_uChar(unsigned char uChar,unsigned char &current_byte,
                        int current_bit_count,FILE *fp_write){
    current_byte<<=8-current_bit_count;//1
    current_byte|=(uChar>>current_bit_count);//
    fwrite(&current_byte,1,1,fp_write);
    current_byte=uChar;   
}


/* **
 * La siguiente funcion va a contar la cantidad de archivos que se van a traducir 
 * Temp toma el valor del residuo de  file_count % 256.
 * se llama la funcion write_from_uChar donde se va a pasar temp
 * luego temp toma el valor de la division entre file_count/ 256
 * y por ultimo se vuelve a escribir en temp mediante write_from_uChar 
 * **/


void write_file_count(int file_count,unsigned char &current_byte,int current_bit_count,
                        FILE *compressed_fp){ unsigned char temp=file_count%256;
    write_from_uChar(temp,current_byte,current_bit_count,compressed_fp);
    temp=file_count/256;
    write_from_uChar(temp,current_byte,current_bit_count,compressed_fp);
}


//Comentario del autor
//It is done like this to make sure that it can work on little, big or middle-endian systems

/* **
 * Esta funcion usa 8 bits para escribir el total de bytes de el archivo a comprirmir
 * **/
void write_file_size(long int size,unsigned char &current_byte,int current_bit_count,FILE *compressed_fp){
    for(int i=0;i<8;i++){
        write_from_uChar(size%256,current_byte,current_bit_count,compressed_fp);
        size/=256;
    }
}


/* **
 * Esta funcion escribe los bytes que son traducidos desde el nombre del archivo que ingresamos al nuevo
 * archivo comprimido
 * En estas funciones podemos ver corrimiento de bits
 * **/
void write_file_name(char *file_name,string *str_arr,unsigned char &current_byte,int &current_bit_count,FILE *compressed_fp){
    write_from_uChar(strlen(file_name),current_byte,current_bit_count,compressed_fp);
    char *str_pointer;
    for(char *c=file_name;*c;c++){
        str_pointer=&str_arr[(unsigned char)(*c)][0];
        while(*str_pointer){
            if(current_bit_count==8){
                fwrite(&current_byte,1,1,compressed_fp);
                current_bit_count=0;
            }
            switch(*str_pointer){
                case '1':current_byte<<=1;current_byte|=1;current_bit_count++;break;
                case '0':current_byte<<=1;current_bit_count++;break;
                default:cout<<"An error has occurred"<<endl<<"Process has been aborted";
                exit(2);
            }
            str_pointer++;
        }
    }
}


/***
 * Esta funcion traduce y escribe los bytes del archivo que queremos comprimir al nuevo archivo
 * Es estas funciones tambien podemos ver corrimientos de bits
 * **/
void write_the_file_content(FILE *original_fp,long int size,string *str_arr,unsigned char &current_byte,int &current_bit_count,FILE *compressed_fp){
    unsigned char *x_p,x;
    x_p=&x;
    char *str_pointer;
    fread(x_p,1,1,original_fp);
    for(long int i=0;i<size;i++){
        str_pointer=&str_arr[x][0];
        while(*str_pointer){
            if(current_bit_count==8){
                fwrite(&current_byte,1,1,compressed_fp);
                current_bit_count=0;
            }
            switch(*str_pointer){
                case '1':current_byte<<=1;current_byte|=1;current_bit_count++;break;
                case '0':current_byte<<=1;current_bit_count++;break;
                default:cout<<"An error has occurred"<<endl<<"Process has been aborted";
                exit(2);
            }
            str_pointer++;
        }
        fread(x_p,1,1,original_fp);
    }
}


/* **
 * Verifica si es o no una carpeta
 * **/
int this_is_not_a_folder(char *path){
    DIR *temp=opendir(path);
    if(temp){
        closedir(temp);
        return 0;
    }
    return 1;
}


/***
 * Verifica el tamaño del archivo
 * **/

long int size_of_the_file(char *path){
    long int size;
    FILE *fp=fopen(path,"rb");
    fseek(fp,0,SEEK_END);
    size=ftell(fp);
    fclose(fp);
    return size;
}


/* **
 * Cuenta la frecuencia de uso de los bytes dentro de la carpeta
 * Solo se de la direcion de la carpeta como entrada
 * **/
void count_in_folder(string path,long int *number,long int &total_size,long int &total_bits){
    FILE *original_fp;
    path+='/';
    DIR *dir=opendir(&path[0]),*next_dir;
    string next_path;
    total_size+=4096;
    total_bits+=16; //for file_count
    struct dirent *current;
    while((current=readdir(dir))){
        if(current->d_name[0]=='.'){
            if(current->d_name[1]==0)continue;
            if(current->d_name[1]=='.'&&current->d_name[2]==0)continue;
        }
        total_bits+=9;

        for(char *c=current->d_name;*c;c++){        //Ciclo que cuenta el uso de frecuencia de los bytes en el nombre del archivo o carpeta
            number[(unsigned char)(*c)]++;
        }

        next_path=path+current->d_name;

        if((next_dir=opendir(&next_path[0]))){
            closedir(next_dir);
            count_in_folder(next_path,number,total_size,total_bits);
        }
        else{
            long int size;
            unsigned char *x_p,x;
            x_p=&x;
            total_size+=size=size_of_the_file(&next_path[0]);
            total_bits+=64;

            //--------------------2------------------------
            original_fp=fopen(&next_path[0],"rb");

            fread(x_p,1,1,original_fp);
            for(long int j=0;j<size;j++){    //Este ciclo cuenta la frecuencia de uso de los bytes en el archivo
                number[x]++;
                fread(x_p,1,1,original_fp);
            }
            fclose(original_fp);
        }
    }
    closedir(dir);
}

/****
 * Escribe en la nueva carpeta toda la informacion de la antigua carpeta
 * 
 * **/

void write_the_folder(string path,string *str_arr,unsigned char &current_byte,int &current_bit_count,FILE *compressed_fp){
    FILE *original_fp;
    path+='/';
    DIR *dir=opendir(&path[0]),*next_dir;
    string next_path;
    struct dirent *current;
    int file_count=0;
    long int size;
    while((current=readdir(dir))){
        if(current->d_name[0]=='.'){
            if(current->d_name[1]==0)continue;
            if(current->d_name[1]=='.'&&current->d_name[2]==0)continue;
        }
        file_count++;
    }
    rewinddir(dir);
    write_file_count(file_count,current_byte,current_bit_count,compressed_fp); //Contamos el numero de archivos

    while((current=readdir(dir))){
        if(current->d_name[0]=='.'){
            if(current->d_name[1]==0)continue;
            if(current->d_name[1]=='.'&&current->d_name[2]==0)continue;
        }

        next_path=path+current->d_name;
        if(this_is_not_a_folder(&next_path[0])){ // Si estamos en el archivo

            original_fp=fopen(&next_path[0],"rb");
            fseek(original_fp,0,SEEK_END);
            size=ftell(original_fp);
            rewind(original_fp);
            if(current_bit_count==8){ //Se escribe la informacion de la carpeta
                fwrite(&current_byte,1,1,compressed_fp);
                current_bit_count=0;
            }
            current_byte<<=1;
            current_byte|=1;
            current_bit_count++;
            //---------------------------------------

            write_file_size(size,current_byte,current_bit_count,compressed_fp);                     //Tamaño  del archivo o carpeta
            write_file_name(current->d_name,str_arr,current_byte,current_bit_count,compressed_fp);                ////Tamaño  del nombre del archivo o carpeta
            write_the_file_content(original_fp,size,str_arr,current_byte,current_bit_count,compressed_fp);      //Se genera el nuevo  archivo comprimido
            fclose(original_fp);
        }
        else{
            if(current_bit_count==8){ // Si estamos en la carpeta escribe la informacion del archivo
                fwrite(&current_byte,1,1,compressed_fp);
                current_bit_count=0;
            }
            current_byte<<=1;
            current_bit_count++;
            //---------------------------------------

            write_file_name(current->d_name,str_arr,current_byte,current_bit_count,compressed_fp);   // Se genera el nuevo nombre del archivo

            write_the_folder(next_path,str_arr,current_byte,current_bit_count,compressed_fp);
        }
    }
    closedir(dir);
}