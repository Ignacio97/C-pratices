//practica3.c

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "library3.h"

/***INICIO PROTOTIPO DE FUNCIONES***/
void informacion_err();
void detener_pantalla(char* mensaje);

/***FIN PROTOTIPO DE FUNCIONES***/





/*** INICIA MAIN ***/

int main(int argc, char* argv[]){

 //DECLARACION DE VARIABLES
		int num=0,num2=0;
 // FIN DE VARAIBLES


//si hay menos de 3 argumentos, por default error.
	if (argc<3){
		informacion_err();
		detener_pantalla("Presione ENTER para continuar!!");
		return 1;
	}

//si hay 3 arg. podria entrar en reversa,digitos,suma,perfecto.
else if(argc==3){

					if (!strcmp("reversa",argv[1])){
						num=atoi(argv[2]);
						printf("La reversa de %d es %d\n",num,regresa_reversa(num));
					}

					else if(!strcmp("digitos",argv[1])){
						num=atoi(argv[2]);
						printf("El numero %d tiene %d digitos.\n",num,digitos(num));
					}
					else if(!strcmp("suma",argv[1])){
						num=atoi(argv[2]);
						printf("La suma de los dig. de %d es %d\n",num,devuelve_suma(num));
					}
					else if(!strcmp("perfecto",argv[1])){
						num=atoi(argv[2]);
						numero_perfecto(num);
					}
		}
//si hay 4 arg. podria entrar en amigos.
 else if (argc==4){

				if(!strcmp("amigos",argv[1])){
					num=atoi(argv[2]);
					num2=atoi(argv[3]);
				(num==0||num2==0) ? printf("%s\n","Los numeros no son primos"):numeros_bffos(num,num2);



				}

			else {
			informacion_err();
			detener_pantalla("Presione ENTER para continuar!!");
		}

	}


//si hay mas de 4 arg. error por default.
else{
			informacion_err();
			detener_pantalla("Presione ENTER para continuar!!");
		}





	return 0;
}

/**TERMINA MAIN **/





/*** INICIO DE FUNCIONES ***/

void informacion_err(){
	printf("\n%s\n","El programa debe recibir dos parametros:" );
	printf("\t%s\n","[1] Funcion a utilizar: \"reversa\", \"digitos\",\"suma\",\"Perfecto\"" );
	printf("\t%s\n","[2] Valor entero decimal." );
	printf("\n\t%s\n\n","EJEMPLO: ./prac3 reversa 123" );
	printf("\t%s\n\n","----------------------------------------------------------------------------------------" );
	printf("%s\n","El programa debe recibir tres parametros:" );
	printf("\t%s\n","[1] Funcion a utilizar: \"amigos\"");
	printf("\t%s\n","[2] Dos valores enteros decimal." );
	printf("\n\t%s\n\n","EJEMPLO: ./prac3 amigos 220 284" );
}

void detener_pantalla (char* mensaje){
    printf("\n%s\n", mensaje);
    setbuf(stdin, NULL);
    getchar();
}



/*** FIN DE FUNCIONES ***/
