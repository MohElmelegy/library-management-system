/**************************************************/
/***************header file************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#ifndef LIB_BOOK
#define LIB_BOOK
#define MAX_NUM_BOOKS 100

typedef struct
{
    char u8_book_title[50];
    char u8_auth_name[50];
    int u32_public_year;
    float f_price;
    char copies ;
    char states;

} book;

book books_table[MAX_NUM_BOOKS];


int num_books = 0;

/***********************API prototype*******************/

void add_book (void);

void print_lib (void);

char check_free_element(void);

void delete_book (void);

void buy_book (void);

void lib_system (void);

void init_sys (void);




#endif
/**************************************************/
