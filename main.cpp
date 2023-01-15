#include <stdio.h>
#include <unistd.h>         // sleep
#include <string.h>         // bzero()  memset()

#include "defines.h"
#include "interface.h"
#include "compute.h"

int main() {

    unsigned tab[F][C], comp[F][C];
    unsigned gen = 0;                   // Current generation

    srand(time(NULL));

    bzero(tab, sizeof(tab));

    random_filling(tab);

    while (gen < MAX) {

        system("clear");
        printf("\n\t\tGeneration: %u\n", ++gen);

        print_board(tab);

        filling_neighbours(tab, comp);

        board_update(tab, comp);

        sleep(1);   // 1 second for each gneration
    }


    return EXIT_SUCCESS;
}
