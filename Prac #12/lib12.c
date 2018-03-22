#include <stdio.h>
#include "lib12.h"

//Funcion que copia num caracteres de la cadena apuntada por source en la cadena
//apuntada por destination
void * memcpy ( void * destination, const void * source, size_t num )
{
	//Cast a los puntero para buscar entre los caracteres, de lo contrario no funciona
    char *dest=(char *)destination;
    char *sour=(char *)source;

	//Mientras no se terminen los caraceres a sustituir o copiar
    while(num)
    {
        *dest++=*sour++; //Comparacion de los valores y aumento para los apuntadores
        num--;
    }
}

//Funcion que compara num caracteres apuntados por ptr1 y ptr2
int memcmp ( const void * ptr1, const void * ptr2, size_t num )
{
    unsigned char *p1,*p2;

	//Cast para los apuntadores.
    p1=(unsigned char *)ptr1;
    p2=(unsigned char *)ptr2;

	//Mientras no se termine la cadena a comparar
    while(num--)
    {//En caso de hallar una diferencia se termina el ciclo
      if(*p1!=*p2) return (*p1-*p2);
      p1++;
      p2++;
    }
    return 0;
}

//Funcion que copia el caracter value en la cadena apuntada por ptr num veces
void *memset ( void * ptr, int value, size_t num )
{
	//Cast al apuntador
    char *p= (char *)ptr;
	//Mientras los caracteres a reemplazar no se hayan acabado
    while(num--)
    {
        *p=value; //Cambiar valor de la cadena
        p++;	  //Sumar una posición al apuntador
    }
}

//Función que busca la primera aparicion de un caracter
void * memchr ( const void * ptr, int value, size_t num)
{
	//Cast al puntero para buscar entre los caracteres, de lo contrario no funciona
    char *p= (char *) ptr;

    while(num--)
    {		//Comparacion con el caracter
            if(*p==value) return p;
            p++;
    }
	//En caso de no haber coincidencia se regresa una direccion nula
    return NULL;
}

//Funcion que copia la cadena source en destination
char * strcpy ( char * destination, const char * source )
{
	//Mientras no se haya acabado la cadena que se copiará
    while(*source++!=0)
    {
		//Se copia el valor y se aumenta una posicion al apuntador
        *destination++=*source;
    }

}

//Funcion que copia num caracteres de una cadena a otra y rellena con caracteres
char * strncpy ( char * destination, const char * source, size_t num )
{
    int cont;

	//Mientras no se termine la cadena source
    for(cont=0;cont<num-1;cont++)
    {
        if(*(source+cont)!='\0') *(destination+cont)=*(source+cont);
            else *(destination+cont)= '\0'; //Rellena con caracteres nulos
    }
}

//Función que agrega cadena a una cadena apuntada
char* strcat ( char*destination, const char* source)
{
    int cont=0,cont2=0;

	//Encuentra el fin de cadena (destino)
    while(*(destination+cont)!='\0') cont++;

    do{

        *(destination+cont)=*(source+cont2);
        cont++;
        cont2++;

      } while(*(source+cont2)!='\0');
}

//Compara las cadenas apuntadas por str1 y str2. Determina cual es mayor, menor o si son iguales
int strcmp ( const char * str1, const char * str2 )
{
	//Mientras no se hayan terminado las cadenas
    while((*str1!='\0') || (*str2!='\0'))
    {
        if (*str1 > *str2) //Si la cadena 1 es mayor
            return 1;
        if (*str1 < *str2) //Si la cadena 2 es mayor
            return -1;

        str1++;
        str2++;
    }
    return 0;
}

//Funcion similar a strcmp a excepcion de que no hace distincion entre mayusculas y minusculas
int strcmpi ( const char * str1, const char * str2 )
{
    char c1,c2;

    while((*str1!='\0')|| (*str2!='\0'))
    {
        c1=*str1;
        c2=*str2;

        if(c1>='A' && c1<= 'Z') c1=c1+32;  //Convierte los caracteres en minusculas
        if(c2>='A' && c2<= 'Z') c2=c2+32;

        if (c1 > c2)   
            return 1;
        if (c1 < c2)
            return -1;

        str1++;
        str2++;
    }
    return 0;
}

//Función que regresa la longitud de una cadena
size_t strlen(const char *str)
{
	//Variable en donde se almacena la longitud
    size_t size=0;
    while(*(str+size)!='\0') size++;  //Ciclo, mientras no se haya acabado la cadena
    return size;
}

//Funcion que busca una cadena en otra
char *strstr(char *str1, const char *str2)
{
	//Determina el tamaño de la cadena a buscar
    size_t n = strlen(str2);
	//Mientras la cadena en donde se hace la busqueda no haya acabado
    while(*str1)
	//Usar la funcion de memcmp para encontar coincidencias
	//Si son iguales los n numeros memcmp regresará 0
        if(!memcmp(str1++,str2,n))
            return str1-1;
    return NULL; //Si no se encontró coincidencia no habrá dirección a la cual apuntar
}
