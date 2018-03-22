#ifndef LIB5
#define LIB5

#define practicas 2 /*col*/
#define alumnos 2  /*row*/
#define size 100

struct Practica {
  int id;
  char titulo[size];
  char comentario[size];
  float promedio;
};
struct Alumno {
  int id;
  char nombre[size];
  char correo[size];
  char genero;
  int ingreso;
  int perido;
  float promedio;
};

void llena_alumno(struct Alumno al[alumnos],int matriz[][practicas],int row,int cols);
void imprime_alumno(struct Alumno al[alumnos],int j);
void genera_cal(int matriz[][practicas],int row,int cols);
float prom_cal(int matriz[][practicas],int row,int cols,int practica);
float promAlumno(int matriz[][practicas],int row,int cols,int alumno);
int Num_ramdom(int a,int b );
void imprime_matriz(int matriz[][practicas],int row,int cols);
void aprueba(int matriz[][practicas],int row,int cols,int alumno);
void llena_prac(struct Practica prac[practicas],int matriz[][practicas],int row,int col);
float mayor_prom(struct Alumno al[alumnos]);
void print_high_prom(struct Alumno al[alumnos]);
void print_prac(struct Practica prac[practicas],int j);
void print_reprobados(struct Alumno al[alumnos]);
void prac_reprobadas (struct Practica prac[practicas]);
void print_all_prac(struct Practica prac[practicas]);
void print_all_student(struct Alumno al[alumnos]);
#endif
