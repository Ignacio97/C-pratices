/***
Programa que elige un numero al azar del 1 al 1000.Pide al usuario que adivide el numero
por medio de pistas.Tambien muestra mensajes en base al numero de intentos.

NOTA: ESTE PROGRAMA FUE CREADO Y COMPILADO EN LINUX.
***/


#include <stdio.h>
#include <time.h>
#include <stdlib.h>


/***INICIO PROTOTIPO DE FUNCIONES***/
void wait_enter();
void intentos(int contador);
int Num_ramdom(int a,int b );
void Imprime_edo(int num2,int num,int contador);
void imprime();
/***FIN PROTOTIPO DE FUNCIONES***/



/*** INICIA MAIN ***/
int main() {
    int a=1,b=1000,num,num2,contador;
    char opc;

    do {
      num=Num_ramdom(a,b);
      contador=0;
        do {
          contador++;
          imprime();
      //printf("(Numero:%d,intento:%d)\n",num,contador ); //agregar esta linea si se desea porbar el prog.
          scanf("%d",&num2);
          Imprime_edo(num2,num,contador);
        } while(num2!=num);
        setbuf(stdin, NULL); // Limpia el buffer de entrada.
        scanf("%c",&opc);

    } while(opc=='y');

  return 0;
}
/**TERMINA MAIN **/




/*** INICIO DE FUNCIONES ***/

//Fun. que recibe numero de intentos e imprime mensaje en base a ello.
void intentos(int cont){
  if (cont<10) {
    printf("Felicidades!! has adivinado en pocos intentos.\n" );
  }
  else if (cont>10) {
      printf("Lo puedes hacer mejor!!\n" );
  } else {
    printf("Haaa!!! ya conoces el numero secreto.\n" );
  }
}

//Fun. que imprime mensaje DE ESTADO del juego.
void Imprime_edo(int num2,int num,int contador) {
  if (num2>num) {
    printf("Muy alto.Intentalo nuevamente.\n");
    printf("\tEnter para continuar..\n" );
    wait_enter();
  }
  else if (num2<num) {
    printf("Muy bajo.Intentalo nuevamente.\n");
    printf("\tEnter para continuar..\n" );
    wait_enter();
  }
  else {
      printf("Excelente! Has adivinado el numero.\n");
      intentos(contador);//IMPRIME MENSAJE EN BASE AL NUMERO DE INTENTOS.
      printf("\tQuieres jugar de nuevo (y/n)?");
  }
}

//Funcion que devuelve un numero aleatorio donde (a=Rango inicial,b=Rango Final).
int Num_ramdom(int a,int b ){
  int num;
  srand(time(NULL));
  num= a+rand()%(b+1-a);
  return num;
  }

  //Funcion que imprime mensaje DE INICIO del juego.
  void imprime(){
    system("clear");
    printf("\nTengo un numero entre 1 y 1000." );
    printf("\nPuedes adivinarlo?");
  }

//Fun. que espera a que el usuario presione enter.
void wait_enter(){
  setbuf(stdin, NULL); // Limpia el buffer de estrada.
      getchar();
}

/*** FIN DE FUNCIONES ***/
