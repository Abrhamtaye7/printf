#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>

/*
 * File: main.h
 *
 * Desc: This file contains all function prototypes and struct
 * type declarations used for the printf Group project in the
 * ALX software engineering program.
 *
 * Authors: Gizachew Bayness (eleccrazy), Abrham Tessfaye (Abraham7)
 *
 * Date Created: May 14, 2022.
 *
 */

int _putchar(char c);

int _printf(const char *format, ...);
int print_c(va_list ap);
int print_s(va_list ap);
int print_int(va_list ap);
int print_b(va_list ap);
int print_o(va_list ap);
int print_u(va_list ap);
int print_x(va_list ap);
int print_X(va_list ap);
int print_S(va_list ap);

/**
 * struct converterStruct - structure for specifier conversion.
 *
 * @specifier: Conversion specifier.
 * @func: The function corresponding to the specifier.
 *
 */

typedef struct converterStruct
{
	char *specifier;
	int (*func)(va_list);
} converter;

#endif
