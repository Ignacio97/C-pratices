#include <stdio.h>
#include "lib12.h"
//#include<string.h>

int main()
{
   char string1[]= "ocupo 100 para exceentar!";
   char string2[70]= {0};
   char string3[]="si se puede ";
   char string4[60];
   char string5[]="Si se puede ";
   char string6[30]={0};
   char string7[120]="Oye y si se pudo excentar ";
   char string8[]="No se puedo! ";
   char string9[]="Me voy a ordinario!";
   char string10[]="bye";
   char *cptr;
   int num;

   //Prueba de la función memcpy y strlen
   printf("Antes de memcpy  = %s\n",string2);
   memcpy(string2,string1, strlen(string1));
   printf("Despues de memcpy= %s\n\n",string2);

   //Prueba de la funcion memcmp
   num= memcmp(string3,"Que.la.fuerza.te.acompanie", sizeof(string3));
   printf("Numero al comparar 2 cadenas = %d\n\n",num);

   //Prueba de la función memset y strcpy
   stpcpy(string4, "NOOOOO se puede excentar");
   printf("Antes de memset   = %s\n",string4);
   memset(string4,'X',15);
   printf("Despues de memset =%s\n\n",string4);

   //Prueba memchr
   printf("%s\n",string3);
   cptr= memchr(string3,'.',strlen(string1));
   printf("Cadena despues de (.) = %s\n\n",cptr);

   //Prueba strncpy
   printf("Antes de strncpy    = %s\n",string6);
   strncpy(string6,string5,29);
   printf("Despues de strncpy  = %s\n\n",string6);

   //Prueba strcat
   printf("Antes de strcat    = %s\n",string7);
   strcat(string7, string8);
   printf("Despues de strcat  = %s\n\n",string7);

   //Prueba strcmp
   num= strcmp(string9,string10);
   printf("Diferencia entre %s y %s (strcmp) = %d\n",string9,string10,num);

   //Prueba strcmpi
   num= strcmpi(string9,string10);
   printf("Diferencia entre %s y %s (strcmpi)= %d\n\n",string9,string10,num);

   //Prueba strstr
   printf("Cadena en donde se buscara =%s\n",string3);
   cptr= strstr(string3,"fuerza");
   printf("Cadena despues de (fuerza) = %s\n\n",cptr);


   printf("\n");
  return 0;
}
