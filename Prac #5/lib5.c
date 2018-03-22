#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "lib5.h"

#define practicas 2 /*col*/
#define alumnos 2  /*row*/
#define size 100

/** PROTOTIPO DE FUNCIONES **/
void llena_alumno(struct Alumno al[alumnos],int matriz[][practicas],int ,int );
void imprime_alumno(struct Alumno al[alumnos],int );
void genera_cal(int matriz[][practicas],int,int );
float prom_cal(int matriz[][practicas],int ,int ,int );
float promAlumno(int matriz[][practicas],int ,int ,int );
int Num_ramdom(int ,int  );
void imprime_matriz(int matriz[][practicas],int ,int );
void aprueba(int matriz[][practicas],int ,int ,int );
void llena_prac(struct Practica prac[practicas],int matriz[][practicas],int ,int );
float mayor_prom(struct Alumno al[alumnos]);
void print_high_prom(struct Alumno al[alumnos]);
void print_prac(struct Practica prac[practicas],int );
void print_reprobados(struct Alumno al[alumnos]);
void prac_reprobadas (struct Practica prac[practicas]);
void print_all_prac(struct Practica prac[practicas]);
void print_all_student(struct Alumno al[alumnos]);
/* TERMINAN PROTOTIPOS */





/*** INICIO DE FUNCIONES ***/

//Fun. que llena toda la info de un alumno.
void llena_alumno(struct Alumno al[alumnos],int matriz[][practicas],int row,int cols) {
  int i;

  for (i = 0; i < alumnos; i++) {
    system("clear");//Limpia consola solo para linux.
    al[i].id=i; //graba el numero de renglos en id

    printf("Nombre %d:",i+1 );
    scanf("%s",&al[i].nombre );

    printf("Correo:");
    scanf("%s",&al[i].correo);
    getchar();

    printf("Genero:");
    scanf(" %c",&al[i].genero );

    printf("Ingreso (aaaa):" );
    scanf("%d",&al[i].ingreso );

    printf("Perido (1/2):" );
    scanf("%d",&al[i].perido );

    al[i].promedio=promAlumno(matriz,row,cols,i);
  }

}

//Fun. que imprime a un alumno indicado por el usuario.
void imprime_alumno(struct Alumno al[alumnos],int j) {

    printf("ID: %d\n",al[j].id+1 );
    printf("Nombre: %s\n",al[j].nombre );
    printf("Correo: %s\n",al[j].correo );
    printf("Genero: %c\n",al[j].genero );
    printf("Ingreso: %d\n",al[j].ingreso );
    printf("Perido: %d\n",al[j].perido );
    printf("Promedio: %f\n",al[j].promedio );
  }


//Fun. que llena una matriz con calificaciones de 1 a 10.
void genera_cal(int matriz[][practicas],int row,int cols) {

  srand(time(NULL));
  for (int ren = 0; ren < row; ren++) {
        for (int col = 0; col < cols; col++) {
          matriz[ren][col]=Num_ramdom(1,10);
        }

    }

}

//Fun. que regresa el promedio de una columna de una matriz.
float prom_cal(int matriz[][practicas],int row,int cols,int practica){

    float suma=0,promedio=0;

      for (int i = 0; i < row; ++i){
        suma+=matriz[i][practica];
      }

        promedio=(float)suma/row;

        return promedio;
}

//Fun. que regresa el promedio de un renglon de una matriz.
float promAlumno(int matriz[][practicas],int row,int cols,int alumno){

    float suma=0,promedio=0;

      for (int i = 0; i < cols; ++i){
        suma+=matriz[alumno][i];
      }

        promedio=(float)suma/cols;

        return promedio;
}

//Funcion que devuelve un numero aleatorio donde (a=Rango inicial,b=Rango Final).
int Num_ramdom(int a,int b ){
  int num;
  //srand(time(NULL));
  num= a+rand()%(b+1-a);
  return num;
  }



//Fun. que imprime una matriz.
void imprime_matriz(int matriz[][practicas],int row,int cols) {
    int ren,col,k;

    for (int i = 0; i < cols; i++) {
        if (i==0){
          printf("ID");
        }
      printf("\t%d",i+1 );
        if(i+1==cols){ //imprime el salto de linea.
          printf("\n");
        }
    }

    for (ren = 0; ren < row; ren++) {
      printf("%d",ren+1 );
        for (col = 0; col < cols; col++) {
          printf("\t%d",matriz[ren][col]);
        }
        printf("\t%.2f",promAlumno(matriz,row,cols,ren) );
        aprueba(matriz,row,cols,ren);
        printf("\n");
    }

 printf("\n");

    for (k = 0; k < cols; ++k){
        printf("\t%.2f",prom_cal(matriz,row,cols,k));

    }

    printf("\n");

}

//Fun. que imprime si una alumno aprueba o no. (A/NA)
void aprueba(int matriz[][practicas],int row,int cols,int alumno){
    float promedio=0;

    promedio=promAlumno(matriz,row,cols,alumno);

  (promedio>=6)? printf("\tA" ):printf("\tNA");
}

//Fun. que llena toda la info. de una practica.
void llena_prac(struct Practica prac[practicas],int matriz[][practicas],int row,int col) {
    int i;

    for (i = 0; i < practicas; i++) {
        system("clear");//Limpia pantalla solo en linux.
        prac[i].id=i; //Asigna el valor al id

        printf("Titulo P%d:",i+1);
        setbuf(stdin, NULL);
        fgets(prac[i].titulo,sizeof(prac[i].titulo), stdin);

        printf("Comentario:");
        fgets(prac[i].comentario,sizeof(prac[i].comentario), stdin);
        

        prac[i].promedio=prom_cal(matriz,row,col,i); //Asigna el promedio
      }

}


//Fun. que devuelve el mayor promedio de un alumno de la tabla.
float mayor_prom(struct Alumno al[alumnos]){
    int i;
    float mayor=0;

    mayor=al[0].promedio;

    for (i = 1; i < alumnos; i++) {

        if (al[i].promedio > mayor) {
            mayor=al[i].promedio;
        }
    }

  return mayor;
}

//Fun. que imprime al alumno/s de mayor prom.
void print_high_prom(struct Alumno al[alumnos]) {
    float prom;
    int i;

    prom=mayor_prom(al);

    for (i = 0; i < alumnos; i++) {


        if (prom==al[i].promedio) {
            printf("%d",al[i].id);
            printf("\t%s",al[i].nombre);
            printf("\t%.2f",al[i].promedio);
            printf("\n");
          }
      }
}

//Fun. que imprime la info de una practica indicada por el usuario.
void print_prac(struct Practica prac[practicas],int j) {

  printf("ID: %d\n",prac[j].id+1 );
  printf("Titulo: %s\n",prac[j].titulo );
  printf("Comentario: %s\n",prac[j].comentario );
  printf("Promedio: %f\n",prac[j].promedio );

}


//Fun. que imprime a los alumnos reprobados.
void print_reprobados(struct Alumno al[alumnos]) {
  int i;

    for (i = 0; i < alumnos ; i++) {
        if (al[i].promedio < 6) {
            printf("\n\t%d \t%s \t%.2f",al[i].id+1,al[i].nombre,al[i].promedio );
        }
    }
}

//Fun. que imprime practicas con promedio menor a 6.
void prac_reprobadas (struct Practica prac[practicas]) {
  int i;

    for (i = 0; i < practicas; i++) {
        if (prac[i].promedio < 6) {
            printf("\n%d %s %.2f",prac[i].id,prac[i].titulo,prac[i].promedio );
        }
    }
}


void print_all_student(struct Alumno al[alumnos]) {
    int i;

      for (i = 0; i < alumnos; i++) {
          imprime_alumno(al,i);
          printf("--------------------------------------\n");
      }

}

void print_all_prac(struct Practica prac[practicas]) {
    int i;

      for (i = 0; i < practicas; i++) {
          print_prac(prac,i);
          printf("--------------------------------------\n");
      }
}
/*** FIN DE FUNCIONES ***/
