/**
 * @file App.c
 * @author Mohamed Sami
 * @brief
 * @version 0.1
 * @date 2023-10-21
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "lib_book.h"
#include "lib_book.c"

int main()
{
    init_sys();
    
    while (1)
    {
        lib_system();
    }

    return 0;
}
