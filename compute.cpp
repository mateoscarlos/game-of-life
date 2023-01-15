#include "defines.h"
#include "compute.h"

void random_filling(unsigned tab[F][C]) {

    double random;

    for (int i=0; i<F; i++)
        for (int j=0; j<C; j++) {
            random = (double) rand () / RAND_MAX;    // Random number between 0-1
            if (random < 0.10)         // 10% of cells
                tab[i][j] = 1;           // live cells
            else
                tab[i][j] = 0;
        }
}

void filling_neighbours(unsigned tab[F][C], unsigned comp[F][C]) {

    unsigned neighbours = 0;

    for (int f=0; f<F; f++)
        for (int c=0; c<C; c++) {
            neighbours = 0;
            for (int f_vec=f-1; f_vec<=f+1; f_vec++)
                for (int c_vec=c-1; c_vec<=c+1; c_vec++)
                    if ( tab[f_vec][c_vec]  ==  1  &&
                            ( f_vec != f  ||  c_vec != c ) &&
                            ( f_vec >= 0  &&  f_vec < F )  &&
                            ( c_vec >= 0  &&  c_vec < C )
                       )
                        neighbours++;
            comp[f][c] = neighbours;
        }
}

void board_update(unsigned tab[F][C], unsigned comp[F][C]) {

    for (int f=0; f<F; f++)
        for (int c=0; c<C; c++)
            if ( tab[f][c] == 1 ) {                             // If a live cell
                if ( comp[f][c] != 2  &&  comp[f][c] != 3 )     // has less than 2 or more than 3 neighbours alives
                    tab[f][c] = 0;                              // it dies
            } else
                if ( comp[f][c] == 3 )                          // If a dead cell, has
                    tab[f][c] = 1;                              // 3 neighbours alives, becomes a live cell.
}
