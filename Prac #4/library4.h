#ifndef LIBRARY4
#define LIBRARY4

# define alumnos 20   /*row*/
# define practicas 10  /*col*/


int Num_ramdom(int,int);

void genera_cal(int matriz[][practicas],int,int);

void imprime_matriz(int matriz[][practicas],int,int);

float prom_cal(int matriz[][practicas],int,int,int);

float promAlumno(int matriz[][practicas],int,int,int);

void prom_imprime(int,float,char);

void bubbleSort​(int M[][practicas],int,int);

float media(int matriz[][practicas], int, int );

float mediana(int matriz[][practicas], int, int );

void copia_matriz(int matriz1[][practicas],int matriz2[][practicas],int, int );

int moda(int M[][practicas], int , int );
#endif
