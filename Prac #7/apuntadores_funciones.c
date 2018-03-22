#include<stdio.h>
#include <stdlib.h>
#include <math.h>

float max(int*, int);
float min(int*, int);
//EXTRA
float desviacion(int*, int);
float media(int*, int);
float mediana(int*, int);
float moda(int*, int);
int* captura(char* archivo, int* tamano);

/*
Funcion que recibe el nombre del archivo a leer y
regresa un arreglo unidimensional con los valores contendos
en el archivo. Usar memoria dinamica.
*/
//void captura(char* archivo, int* arreglo, int* tamano);

int main(int argc, char* argv[])
{
    int size, i, *arreglo=NULL, tam;
    //arreglo de apuntadores a funciones
   float (*funciones[])(int*, int) = {max, min, media, mediana, moda };
  char* nombres[] = {"maximo", "minimo", "media", "mediana", "moda"};

    //ejemplo de uso de funcion captura
      arreglo=captura(argv[1],&tam);

for ( i = 0; i < tam; i++) {
  printf("%d\n",*(arreglo+i) );
}printf("\n%d\n", tam);

    size = sizeof(funciones)/sizeof(funciones[0]);
    for(i=0; i<size; i++)
        printf("%s: %.3f\n", nombres[i], funciones[i](arreglo,tam));


    return EXIT_SUCCESS;
}


//Funcion que encuentra el valor maximo.
float max(int* vector, int i){
    int j=1;
    float mayor=*vector;
    for(j=1;j<i;j++){
        if(vector[j]>mayor)
            mayor=vector[j];
    }
    return mayor;
}

//Funcion que encuentra el valor minimo.
float min(int* vector, int i){
    int j=1;
    float menor=*(vector);
    for(j=1;j<i;j++){
        if((*(vector+j))<menor){
            menor=*(vector+j);
        }
    }
    return menor;
}

//Funcion que calcula la media.
float media(int* vector, int i){
    int j=0, total=0;
    float prom;
    for(j=0;j<i;j++){
        total+=*(vector+j);
    }
    prom=(float)total/i;
    return prom;
}

//Funcion que encuentra la mediana.
float mediana(int* vector, int tam){
    float mediana;
    if(tam%2!=0){
        mediana=vector[tam/2];
    }
    else{
        mediana=(float)(vector[tam/2]+vector[(tam/2)-1])/2;
    }
    return mediana;
}

//Funcion que encuentra la moda.
float moda(int* vector, int tam){
    int frecuencias[50]={0};
    int masGrande=0, moda=0, rango, i;
    for(i=0; i<tam; i++){
        frecuencias[vector[i]]++;
    }
    for(rango=1; rango<50; rango++){
        if(frecuencias[rango]>masGrande){
            masGrande=frecuencias[rango];
            moda=rango;
        }
    }
    return moda;
}

//Funcion que calcula la desviacion estandar.
float desviacion(int* vector, int tam){
    float varianza=0, desviacion, prom;
    int i;
    prom=media(vector,tam);
    for(i=0;i<tam;i++){

        varianza=varianza+(pow((vector[i]-prom),2));
    }
    varianza/=(tam-1);
    desviacion=sqrt(varianza);
    return desviacion;
}

//Funcion necesaria para el qsort.
int compare (const void * a, const void * b){
  return ( *(int*)b - *(int*)a );
}

int* captura(char* archivo, int* tamano){
  int size=1,*vector=NULL;
  FILE* file=NULL;

      file=fopen(archivo,"r");

    if (file==NULL) {
      printf("%s\n","Error al abrir archivo" );
    }

      vector=(int*)malloc(sizeof(int)*size);

        while (!feof(file)) {
            fscanf(file,"%d",(vector+size-1));
            size++;
            vector=(int*)realloc(vector,(sizeof(int)*size));
          }
          *tamano=size-2;

          fclose(file);

return vector;
}
