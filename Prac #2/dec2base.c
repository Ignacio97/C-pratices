//dec2base.c
#include "dec2base.h"
#include <stdio.h>


void dec2binchar (int value, char* binchar, int size)
{
    //basado en la solucion de su companero
    //Ricardo Castañon Renteria

    int cociente, residuo, i;
    cociente=value;
    
    //Comentar por que esta instruccion es utlizada: Se utiliza para declar el arreglo y que este contenga 
    //caracter vacio al final.
    binchar[size] = '\0';
    
    //Comentar en que sentido se asignan variables al arreglo
    //Comentar por que es necesario este proceso
    //Investigar funcionamiento de la funcion memset y como se podria implementar
/*Esta accion se ejectuta de izq. a der. y es necesaria para inicializar cada valor del arreglo en 0, 
de no ser asi, en dicha poscision haria un "numero raro"*/

    for(i=0; i<size; i++)
    {
        binchar[i]='0';
    }
    
    i=1;
    //Comentar en que sentido se le asignan valores al arreglo y por que

    /*Se asigna de derecha a izquierda esto para que se acamode en el orden que le corresponde, de lo contraio
    la cadena quedaria alrevez, por ejemplo 6 en binario es 110, quedaria 011.*/
    while(cociente!=0)
    {
        residuo=cociente%2;
        cociente= cociente/2;
        //por que solo se encuentra la variable residuo en la condicion
/*  porque el residuo solo sera 1 o 0; asi mismo en c 0 es false y 1 true, por lo cual si el residuo en 1
entrara dentro de la condicion y en la posicion correspondiente.*/
        if(residuo)
        {
            binchar[size-i]='1';
                        
        }
        i++;
    }
}



int dec2bin(int value){

int num,residuo, base = 1, binario = 0;

    num=value;
    
     while (num > 0){
    residuo = num % 2;
    binario = binario + (residuo * base) ;
    num = num / 2;
    base *= 10;
    }
		
    return binario;
}

char* dec2hex(int value)
{
    return "5A7";
}

int dec2oct(int value){
    
    int num,residuo, base = 1, octal = 0;

    num=value;
    
     while (num > 0){
    residuo = num % 8;
    octal = octal + (residuo * base) ;
    num = num / 8;
    base *= 10;
    }
    
    return octal;
}







/*** RESPUESTAS ***/
/*
Indicar que hace define: La directiva #define indica al preprocesador que defina un item de datos u operacion, 
en este caso sustituira "MAX" por el valor 10 cada vez que se mande a llamar.

memset:La función memset de C *memset(void *str, int c, size_t n) 
copia el caracter c (un char sin signo) a los primeros n caracteres de str.

podria usarse de la siguiente manera memset(binchar,0,10); y esto sustituiria al ciclo for que
que llena la cadena de ceros.



*/
/* FIN */