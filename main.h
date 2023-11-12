#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unisted.h>
#include <limits.h>
#include <stdlib.h>

#define OUTPUT_BUFFER_SIZE 1024
#define BUFFER_FLUSH -1

#define NULL_STRING "(NULL)"

#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE  1
#define CONVERT_UNSIGNED   2

/**
 *struct parameters - parameters struct
 *
 *@unsign: flag if unsigned value
 *
 *@plus_flag: on if plus_flag specified
 *@space_flag: on if hashtag_flag specified
 *@hashtag_flag: on if_flag specified
 *@zero_flag: on if_flag specified
 *@minus_flag: on if_flag specified
 *
 *@width: field width specified
 *@precision: field precision specified
 *@h_modifier: on if h_modifier is specified
 *@l_modifier: on if l_modifier is specified
 *
 */

typedef struct parameters
{
	unsigned int unsign          : 1;
	unsigned int plus_flag       : 1;
	unsigned space_flag          : 1;
	unsigned hashtag_flag         : 1;
	unsigned int zero_flag       : 1;
	unsigned int minus_flag      : 1;
	unsigned int width;
	unsigned int precision;
	unsigned int h_modifier      : 1;
	unsigned int l_modifier      : 1;
} par_t;

/**
 * struct specifier - struct token
 *@specifier: format token
 *@f: the function associated
 */

typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, par_t *);

} specifier_t;


int _puts(char *str);
int _putchar(int c);


int print_char(va_list va, par_t *params);
int print_int(va_list va, par_t *params);
int print_string(va_list va, par_t *params);
int print_percent(va_list va, par_t *params);
int print_s(va_list va, par_t *params);

char *convert(va_list va, par_t *params);
int print_unsigned(va_list va, par_t *params);
int print_address(va_list va, par_t *params);



int (*get_specifier(char *s))(va_list va, par_t *params);
int get_print_func(char *s, va_list va, par_t *params);
int get_flag(char *s, par_t *params);
int get_modifier(char *s, par_t *params);
char *get_width(char *s, par_t *params);


int print_hex(va_list va, par_t *params);
int print_HEX(va_list va, par_t *params);
int print_binary(va_list va, par_t *params);
int print_octal(va_list va, par_t *params);


int print_from_to(char *start, char *stop, char *except);
int print_rev(va_list va, par_t *params);
int print_rote13(va_list va, par_t *params);


int _isdigit(int c);
int _strlen(int *s);
int print_number(char *str, par_t *params);
int print_number_right_shift(char *str, par_t *params);
int print_number_left_shift(char *str, par_t *params);


void init_params(par_t *params, va_list va);

char *get_precision(char *p, par_t, va_list pa);

int _printf(const char *format, ...);

#endif

