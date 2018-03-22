//library3.c
#include "library3.h"
#include <stdio.h>


/***INICIO PROTOTIPO DE FUNCIONES***/

int devuelve_residuo(int,int);
int divide(int,int);
int divisores_propios(int );

/***FIN PROTOTIPO DE FUNCIONES***/




/*** INICIO DE FUNCIONES ***/


//Fun. que recibe un num. y devuelve la reversa del mismo.
int regresa_reversa(int num){
	int reversa=0,base=10,residuo=0;

	while(num!=0){
	residuo=devuelve_residuo(num,base);
	num=divide(num,base);

	reversa=(reversa*base) + residuo;

	}

	return reversa;
}

//Fun. que recibe un numero y devuelve la cant. de digitos que contiene.
int digitos(int num){
	int contador=0,base=10;

	while(num>=1){
		num=divide(num,base);
		contador++;
	}

	return contador;
}

//Fun. que recibe un num. y devuelve la suma de sus digitos.
int devuelve_suma(int num){
	int residuo,base=10,suma=0;

	while (num!=0) {
				residuo=devuelve_residuo(num,base);
				num=divide(num,base);
				suma+=residuo;
	}
	return suma;
}

//Fun. que recibe un num. e imprime si es perfecto.
void numero_perfecto(int num){


		(num==divisores_propios(num)) ? printf("\n%s\n","Numero perfecto"):printf("\n%s\n","Numero imperfecto");

	}

//Fun. que recibe dos numeros e imprime si son amigos.
void numeros_bffos(int num,int num2){

	if (num==divisores_propios(num2)){
		printf("\nLos numeros %d y %d son amigos porque la suma de los divisores propios de %d es igual a %d.\n",num,num2,num2,num);
	}

	else if (num2==divisores_propios(num)){
			printf("\nLos numeros %d y %d son amigos porque la suma de los divisores propios de %d es igual a %d.\n",num,num2,num,num2);

	}

	else{
		printf("%s","Lo siento tus numeros no son bffos </3\n" );
	}
}

//Fun. que recibe dos numeros(a,b) y devuelve el residuo(c). (a%b)=c
int devuelve_residuo(int dividendo,int divisor){

	return (dividendo%divisor);
}

//Fun. que recibe dos numeros(a,b) y devuelve el cociente(c). (a/b)=c
int divide(int dividendo,int divisor){

	return (dividendo/divisor);
}

//Fun. que recibe un num. y devuelve la suma de sus divisores propios.
int divisores_propios(int num){

		int i,residuo,suma=0;

			for (i = 1; i!=num; i++) {
					residuo=devuelve_residuo(num,i);

					if (residuo==0) {
						suma+=i;
					}
			}

	return suma;
}


/*** FIN DE FUNCIONES ***/
