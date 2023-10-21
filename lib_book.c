#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "lib_book.h"

/***********************API prototype*******************/
char check_free_element(void);
void add_book(void);
void print_lib(void);
void delete_book(void);
book *search_book_by_name(char *book_name);
void buy_book(void);
void borrow_book(void);
void lib_system(void);
void string_scan(char *str, int maxsize);
void init_sys(void);

/*******************************************************/

/***********************API Implementation*******************/
void init_sys(void)
{
    printf("--------------------------------------------------------------\n");
    printf("**************************************************************\n\n");
    printf("author: Mohamed Sami\n");
    printf("brief : Library managment syrtem\n");
    printf("date: 2023-10-19\n\n");
    printf("--------------------------------------------------------------\n");
    printf("**************************************************************\n");
}

void lib_system(void)
{
    // system("cls");
    printf("--------------------------------------------------------------\n");
    printf("**************************************************************\n\n");
    int choice;
    printf("1. Add book\n");
    printf("2. Print library\n");
    printf("3. Borrow book\n");
    printf("4. Delete book\n");
    printf("5. Buy book\n");
    printf("6. Exit\n");
    printf("--------------------------------------------------------------\n");
    printf("**************************************************************\n\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        add_book();
        break;
    case 2:
        print_lib();
        break;
    case 3:
        borrow_book();
        break;
    case 4:
        delete_book();
        break;
    case 5:
        buy_book();
        break;
    case 6:
        exit(0);
    default:
        printf("Invalid choice.\n");
    }
}

void add_book(void)
{
    char u8_book_name[50];
    system("cls");
    printf("--------------------------------------------------------------\n");
    printf("**************************************************************\n\n");
    if (num_books < MAX_NUM_BOOKS)
    {
        printf("Enter the title of book: ");
        scanf(" %[^\n]", &u8_book_name);

        // strcpy(allBooks[index].title, title);
        book *book_to_added = search_book_by_name(u8_book_name);

        if (book_to_added != NULL)
        {
            printf("The book is exist \n ");
        }
        else
        {
            // scanf(" %[^\n]", &books_table[num_books].u8_book_title);
            strcpy(books_table[num_books].u8_book_title, u8_book_name);
            printf("Enter the Author name: ");

            scanf(" %[^\n]", &books_table[num_books].u8_auth_name);

            printf("Enter the publish year: ");
            scanf("%d", &books_table[num_books].u32_public_year);

            printf("Enter the price of book: ");
            scanf("%f", &books_table[num_books].f_price);
            printf("--------------------------------------------------------------\n");
            printf("**************************************************************\n\n");
            // new_book ->copies ++;
            books_table[num_books].copies = 1;
            books_table[num_books].states = 1;

            num_books++;
        }
    }
    else
    {
        /*In case no free element*/
        printf("No free element to add new book");
    }
}

void delete_book(void)
{
    system("cls");
    char u8_book_name[50];
    printf("****************************\n");
    printf("Enter the name of book which you delete: ");
  
    scanf(" %s", &u8_book_name);

    book *book_to_delete = search_book_by_name(u8_book_name);

    if (book_to_delete != NULL)
    {
        // Delete the book from the library.

        int temp = book_to_delete->copies;
        
        for (int i = book_to_delete - books_table; i < num_books - 1; i++)
        {
            books_table[i] = books_table[i + 1];
        }
        if (temp == 0)
        {
            num_books--;
        }
        else
        {
            num_books = num_books - temp;
        }

        printf("Books :%d \n", num_books);
      

        printf("The book has been deleted.\n");
    }
    else
    {
        printf("Book not found.\n");
    }
}

void print_lib(void)
{
    system("cls");
    printf("/**************************************************/\n");
    printf("No. of books: %d \n", num_books);
    printf("The library is content: \n");

    for (int i = 0; i < num_books; i++)
    {

        if (books_table[i].copies != 0)
        {
            printf("Book name :%s - Author: %s - public_year:(%d) - No. of copies:(%d) - $%.2f\n\n", books_table[i].u8_book_title, books_table[i].u8_auth_name, books_table[i].u32_public_year, books_table[i].states, books_table[i].f_price);
        }
    }
    printf("/**************************************************/\n");
    printf("Press any key to continue...\n");
    getch();
}

void borrow_book(void)
{

    system("cls");
    char u8_book_name[50];
    printf("****************************\n");
    printf("Enter the name of book which you borrow: ");

    scanf(" %s", &u8_book_name);

    book *book_to_borrow = search_book_by_name(u8_book_name);
    if (book_to_borrow != NULL && book_to_borrow->states > 0)
    {

        book_to_borrow->states--;
        printf("The book is available \n");
        printf("The copies of book is become: %d \n", book_to_borrow->states);
    }
    else
    {
        printf("The book isn't available \n");
    }
}

void buy_book(void)
{
    system("cls");
    char u8_book_name[50];
    printf("****************************\n");
    printf("Enter the name of book which you buy: ");
    scanf(" %s", &u8_book_name);
    book *book_to_buy = search_book_by_name(u8_book_name);
    if (book_to_buy != NULL)
    {

        book_to_buy->copies++;
        book_to_buy->states++;
        num_books++;

        printf("The book '%s' has been added to become '%d' copy.\n", book_to_buy->u8_book_title, book_to_buy->copies);
    }
}

book *search_book_by_name(char *book_name)
{
    for (int i = 0; i < num_books; i++)
    {
        if (strcmp(books_table[i].u8_book_title, book_name) == 0)
        {
            return &books_table[i];
        }
    }

    return NULL;
}

void string_scan(char *str, int maxsize)
{
    int i = 0;
    fflush(stdin);
    scanf("%c", &str[i]);
    for (; str[i] != '\n' && i < maxsize - 1;)
    {
        i++;
        scanf("%c", &str[i]);
    }
    str[i] = 0;
}
