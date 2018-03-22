#ifndef LIB13
#define LIB13

void display(unsigned int valor);
int clearbit (unsigned int valor, unsigned char pos);
int setbit(unsigned int valor, unsigned char pos);
unsigned char getbit (unsigned int valor, unsigned char pos);
unsigned int togglebit(unsigned int valor, unsigned char pos);
unsigned int introtright(unsigned int valor, unsigned char loc);
unsigned int introtleft(unsigned int valor, int loc);
unsigned char byterotright(unsigned char valor, unsigned int loc);
unsigned char byterotleft(unsigned char valor, unsigned int loc);
unsigned char getbyte(unsigned int valor, unsigned char pos);
void encrypt(char* mensaje, unsigned char clave);

#endif
