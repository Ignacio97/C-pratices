#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "library4.h"

# define alumnos 20        /*row*/
# define practicas 10       /*col*/


/***INICIO PROTOTIPO DE FUNCIONES***/
float media(int M[][practicas], int, int );
void Prom_imprime(int,float,char);
float promAlumno(int matriz[][practicas],int,int,int);
float prom_cal(int matriz[][practicas],int,int,int);
int Num_ramdom(int,int);
void imprime_matriz(int matriz[][practicas],int,int);
void genera_cal(int matriz[][practicas],int,int);
/***FIN PROTOTIPO DE FUNCIONES***/


/*** INICIO DE FUNCIONES ***/


//Fun. que llena una matriz con calificaciones de 1 a 10.
void genera_cal(int matriz[][practicas],int row,int cols) {

  srand(time(NULL));
  for (int ren = 0; ren < row; ren++) {
        for (int col = 0; col < cols; col++) {
          matriz[ren][col]=Num_ramdom(1,10);
        }

    }

}

//Fun. que imprime una matriz.
void imprime_matriz(int matriz[][practicas],int row,int cols) {
    int ren,col,k;


    for (ren = 0; ren < row; ren++) {
        for (col = 0; col < cols; col++) {
          printf("\t%d",matriz[ren][col]);
        }
        printf("\t%.2f",promAlumno(matriz,row,cols,ren) );
        printf("\n");
    }
    
 printf("\n");
    
    for (k = 0; k < cols; ++k){
        printf("\t%.2f",prom_cal(matriz,row,cols,k));

    }
 
    printf("\n");

}

//Funcion que devuelve un numero aleatorio donde (a=Rango inicial,b=Rango Final).
int Num_ramdom(int a,int b ){
  int num;
  //srand(time(NULL));
  num= a+rand()%(b+1-a);
  return num;
  }


 

//Fun. que regresa el promedio de un reglon de una matriz.
float prom_cal(int matriz[][practicas],int row,int cols,int practica){

    float suma=0,promedio=0;

      for (int i = 0; i < row; ++i){
        suma+=matriz[i][practica];
      }

        promedio=(float)suma/row;

        return promedio;
}

//Fun. que regresa el promedio de una col de una matriz.
float promAlumno(int matriz[][practicas],int row,int cols,int alumno){

    float suma=0,promedio=0;

      for (int i = 0; i < cols; ++i){
        suma+=matriz[alumno][i];
      }

        promedio=(float)suma/cols;

        return promedio;
}



//Fun. que imprime mensaje dependiendo de la opcion.
void prom_imprime(int posicion, float promedio,char opcion){
  
    if (opcion=='b'){
      printf("La practica %d tiene un promedio de %.2f\n",posicion,promedio);
          
        }    

    else{
      printf("El alumno %d tiene un promedio de %.2f\n",posicion,promedio);
    }
}


//Algoritmo de ordenamiento por Burbuja
void bubbleSort​(int M[][practicas], int row, int col){
    int i, n, tmp, j=0, swapped = 1;

        n = row*col;
        while (swapped) {
        swapped = 0;
        j++;
        
          for (i=0; i<n-j; i++) {
                if (M[0][i] > M[0][i + 1]){
                  tmp = M[0][i];
                  M[0][i] = M[0][i + 1];
                  M[0][i + 1] = tmp;
                  swapped = 1;
                }
            }
        }
}

//Fun. que devulve el promedio de una
float media(int matriz[][practicas], int row, int cols){
      int i;
      float promedio=0,suma=0;

      for (i = 0; i < cols; i++){
          suma+=prom_cal(matriz,row,cols,i);
      }

      promedio=(float)suma/cols;

      return promedio;
}


//Fun. que devuelve la mediana de una matriz.
float mediana(int matriz[][practicas], int row, int cols ){
    int total=row*cols,suma=0;
    float mediana=0;

    

      if (total%2==0){
        suma=(matriz[0][total/2])+(matriz[0][(total/2)-1]);
        mediana=(float) suma/2;
      }
        
      else{
             mediana=matriz[0][total/2];
      }

return mediana;

}

//Fun. que copia una matriz.
void copia_matriz(int matriz1[][practicas],int matriz2[][practicas],int row, int cols){
      int total=row*cols,i;


      for ( i = 0; i < total; ++i){
        matriz2[0][i]=matriz1[0][i];
      }
}

//Fun. que devuelve la moda de una matriz.
int moda(int M[][practicas], int ren, int col){ 

  int i,j,F[11]={0},mayor,moda;
  
  

    for(i=0;i<ren; i++){
      for(j=0;j<col; j++){

        F[M[i][j]]++; 
      }
    } 
  
  mayor=0;
  moda=0;
  

  for(i=1;i<11;i++){
      if(F[i]>mayor){
        mayor=F[i];
         moda=i;   
      }

    
  }
return moda;  
}


/*
IMPORTANTE!!
La Funcion Moda si funciona aunque no correctamente. Devuele "el numero con mas frecuencia" pero
si hay mas numeros con la misma frecuencia solo devolvera el primero de ellos.

-No supe como resolver ese inconveniente.

*/


  
/*** FIN DE FUNCIONES ***/      