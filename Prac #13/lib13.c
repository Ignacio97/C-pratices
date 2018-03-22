

#define INT_BITS 32
#define CHAR_BITS 8

void display(unsigned int valor)
{
    unsigned int cont, inicio= 0X80000000; // 2^(32-1)

    for (cont=inicio; cont>0 ; cont>>=1) //El contador se recorre un bit
        if(cont & valor) //Si contador AND valor ==1
            printf("1");
          else  printf("0");

}

int clearbit (unsigned int valor, unsigned char pos)
{
    valor= valor & ~(1<<(pos-1));
    return valor;
}

int setbit(unsigned int valor, unsigned char pos)
{
    valor= valor | (1<<(pos-1));
    return valor;
}

unsigned char getbit (unsigned int valor, unsigned char pos)
{
    valor= valor & (1<<(pos-1));
    return valor;
}

unsigned int togglebit(unsigned int valor, unsigned char pos)
{
    valor= valor ^ (1<<(pos-1));
    return valor;
}

unsigned int introtright(unsigned int valor, unsigned char loc)
{
    return (valor>>loc)|(valor<<(INT_BITS-loc));
    //(valor>>loc) mueve el bloque de bits segun lo solicitado
    //Ej. Num 2(Binario: 10 ), moverlo 1.  Resultado 1: 01
    //(valor<<32-loc) mueve segun los 32 bits que hay en la variable entero(4 bytes)
    //Resultado 2: 31ceros del desplazamiento y el ultimo cero del 2
    //Se comparan con OR para obtener todos los unos contenidos entre los 2 resultados. Finalmente se obtiene 1
}

unsigned int introtleft(unsigned int valor, int loc)
{
    return (valor<<loc)|(valor>>(INT_BITS-loc));
    //Función que hace lo opuesto a introtright
}

unsigned char byterotright(unsigned char valor, unsigned loc)
{
    return (valor>>loc)|(valor<<(CHAR_BITS-loc));                              // Ej.Num=111 (binario=  01101111)
    //(valor>>loc) mueve el bloque de bits segun lo solicitado (maximo 8 bits) Despues del corrimiento  10111100
    //(valor<<8-loc) mueve segun los 8 bits que hay en la variable char        Dato para comparar       00000001
    //Se comparan con OR para dejar pasar todos los unos                       Resultado:               10111101 = 189
}

unsigned char byterotleft(unsigned char valor, unsigned int loc)
{
    return (valor<<loc)|(valor>>(CHAR_BITS-loc));
    //Función que rota al contrario de byterotleft. Es similar a la función introleft
    //a excepción de que es para 8 bits unicamente

}

unsigned char getbyte(unsigned int valor, unsigned char pos)
{
    valor=(valor<<(INT_BITS-pos))>>(INT_BITS-4);
    return (valor&0X0F);

}

void encrypt(char* mensaje, unsigned char clave)
{
    while(*mensaje!='\0')
    {
        *mensaje=*mensaje^clave;
        mensaje++;
    }
    *++mensaje='\0';
}
