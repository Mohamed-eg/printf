#ifndef mainH
#define mainH
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define buffSize 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define longSize 2
#define shortSize 1

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt FMT_TY - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt FMT_TY;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);

/****************** FUNCTIONS ******************/

/* Funtions to print chars and strings */
int printChar(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int printString(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int printPercent(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Functions to print numbers */
int printIntegr(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int printBinary(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int printUnsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int printOctalNum(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int printHexaDec(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int printHexUpper(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int printHexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Function to print non printable characters */
int printNONprintable(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Funcion to print memory address */
int printPointer(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Funciotns to handle other specifiers */
int getFlags(const char *format, int *i);
int getWidth(const char *format, int *i, va_list list);
int getPrecision(const char *format, int *i, va_list list);
int getSize(const char *format, int *i);

/*Function to print string in reverse*/
int getReverse(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/*Function to print a string in rot 13*/
int printRot13Str(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* width handler */
int handleWriteCh(char c, char buffer[],
	int flags, int width, int precision, int size);
int writeNum(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int writeNumber(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int writePointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int writeUnsgnd(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);

/****************** UTILS ******************/
int IsItPrintable(char);
int appendHexaCode(char, char[], int);
int IsItDigit(char);

long int ConvertSizeNum(long int num, int size);
long int ConvertSizeUnsign(unsigned long int num, int size);

#endif
