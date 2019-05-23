
#ifndef Satria_N_B_H
#define Satria_N_B_H

#include <stdio.h>

typedef struct {
        int temp_i;
        int temp_j;
}temp;

typedef int matriks[20][26];
typedef struct lvl *address;
typedef struct lvl {
 matriks maps;
 address next;
 } levell;

void maps(int i, int j);

void load_map();

void render ();

#endif
