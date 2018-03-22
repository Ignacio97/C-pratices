#ifndef LIB8
#define LIB8

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

/**FIN **/



#endif
