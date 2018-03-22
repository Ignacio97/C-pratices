#ifndef MY_STRING
#define MY_STRING


void * memcpy ( void * destination, const void * source, size_t num );
int memcmp ( const void * ptr1, const void * ptr2, size_t num );
void * memset ( void * ptr, int value, size_t num );
void * memchr ( const void * ptr, int value, size_t num);
char* strcpy ( char* destination, const char* source );
char* strncpy ( char* destination, const char* source, size_t num );
char* strcat ( char*destination, const char* source );
int strcmp ( const char * str1, const char * str2 );
int strcmpi ( const char * str1, const char * str2 );
size_t strlen(const char *str);
char *strstr (char * str1, const char * str2 );

#endif
