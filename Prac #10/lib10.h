#ifndef LIB10
#define LIB10

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
int menu_editar(void);
int categoria(void);
void menu(void);
void captura(ADVERT *ad);
void save (ADVERT ad);
void print(ADVERT *ad);
void display(void);
void delete(void);
int search(char  key[]);
void editar(void);
void search_cate(char*key,const int);
void backup(void);
void guarda_orden_nombre(void);
void anuncios_en_fecha(void);
void limpia(ADVERT *a);
void bubbleSort(void **array, int n, int (*cmp)( void**a, void**b));
void swap(void** a, void**b);
int compara_id(void** a,void**b);
int compara_nombre(void** a,void**b);
int compara_clase(void** a,void**b);
int llena_array(ADVERT **registros);
int crea_array_ptr(ADVERT ***ptr);
void ordena(int (*comparar)(void **a,void **b));
void prime_anuncio(ADVERT**registro,int n);
void anuncios_en_fecha();

/**FIN **/



#endif
