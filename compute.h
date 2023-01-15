#ifndef _COMPUTE_H_
#define _COMPUTE_H_

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void random_filling(unsigned tab[F][C]);

void filling_neighbours(unsigned tab[F][C], unsigned comp[F][C]);

void board_update(unsigned tab[F][C], unsigned comp[F][C]);

#endif
