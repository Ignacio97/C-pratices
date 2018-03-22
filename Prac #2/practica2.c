/*practica2 Programacion Estructurada*/

#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include"dec2base.h"

void detener_pantalla(char* mensaje);
void informacion_err();

int main(int argc, char* argv[])
{
    //declaracion de variables a utilizar
    int num = 0;


    //comprobacion de numero de parametros ingresados por consola
    if(argc<3)
    {
        //Por defecto el programa recibe un argumento, el nombre del archivo (ej. practica2.c).
        informacion_err();
        detener_pantalla("\n\tPresione ENTER para salir");
        return 1;
    }
    else
    {
        num = atoi(argv[2]);
        if(strcmp("bin", argv[1])==0)
        {
          printf("\nEl numero: %d, en binario es: %s\n",num,dec2binchar(num));
        }
        else if(strcmp("hex", argv[1]==0))
        {
          printf("\nEl numero: %d, en hexadecimal es: %s",num,dec2hex(num));
        }
        else if(strcmp("oct", argv[1])==0)
        {
          printf("\nEl numero: %d, en binario es: %d",num,dec2oct(num));
        }
        else
        {
            informacion_err();
            detener_pantalla("\n\tPresione ENTER para salir");
            return 1;
        }
    }

    detener_pantalla("\n\tPresione ENTER para salir");
    return 0;
}


void detener_pantalla (char* mensaje)
{
    printf("\n%s\n", mensaje);
    setbuf(stdin, NULL);
    getchar();
}

void informacion_err()
{
    printf("El programa debe recibir dos parametros");
    printf("\n   [1] Base a convertir el valor entero: \"bin\", \"hex\", \"oct\"");
    printf("\n   [2] Valor entero decimal");
    printf("\n\nEjemplo:\nprac2.exe bin 5");
}

