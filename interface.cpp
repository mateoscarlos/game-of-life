#include "defines.h"
#include "interface.h"

void print_board(unsigned matrix[F][C]) {

    for (int i=0; i<F; i++) {
        printf ("\n\t\t");
        for (int j=0; j<C; j++)
            if ( matrix[i][j] == 1 )
                printf ("██");  // U+2588
            else
                printf("  ");
    }
    printf ("\n\n");
}
