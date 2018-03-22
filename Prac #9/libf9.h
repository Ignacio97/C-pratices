#ifndef LIBF9
#define LIBF9

#define SIZE 50
#define CLEAR() system("clear") //clearscreen on linux

//estructura del tipo ADVERT
typedef struct clasificados{
  int id;
  char clase[SIZE];
  char titular[SIZE];
  long telefono;
  char contenido[SIZE];
    struct tiempo{        //struct tiempo
        int dia;
        int mes;
        int year;
      }fecha;
}ADVERT;


/**PROTOTIPOS DE FUNCONES **/
void menu(void);
int llena_array(ADVERT **registros);
int crea_array_ptr(ADVERT ***ptr);
void ordena(int (*comparar)(void **a,void **b));
void prime_anuncio(ADVERT**registro,int n);
void bubbleSort(void **array, int n, int (*cmp)( void**a, void**b));
void swap( void** a, void**b);
int compara_id(void** a,void**b);
int compara_nombre(void** a,void**b);
int compara_clase(void** a,void**b);
int compara_telefono(void** a,void**b);
int compara_contenido(void** a,void**b);
int compara_fecha(void** a,void**b);
void display(void);
void respaldo(int );
/**FIN **/



#endif
