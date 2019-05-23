#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <malloc.h>
#include "..\\Header\\Rezky_W_S.h"
#include "..\\Header\\Satria_N_B.h"
#include <time.h>

extern int i,j,stat,page,a,b;
extern float x,y;
extern void *map;
extern int matriksmap[20][26];
extern double time_taken,time_start;
extern clock_t waktu;
extern temp A[10];
extern char character[40];
extern address matriksmaps;


void wreck_left()
{
	if(matriksmaps->maps[i+1][j-1] == 1)
    {
		matriksmaps->maps[i+1][j-1] = 0;
		a = i+1;
		b = j-1;
		clearviewport();

		setviewport(0, 0, getmaxx(), getmaxy(), 1);
		putimage(10,0,map, COPY_PUT);
        readimagefile("Image\\Map\\blank.bmp",10+30*(j-1),30*(i+1),39+30*(j-1),29+30*(i+1));
		getimage(10,0,790,600,map);
		waktu = clock();
		time_start = ((double)waktu)/CLOCKS_PER_SEC;
		count_time();

		setviewport(10+x,y,40+x,30+y, 1);

		readimagefile(character,0,0,29,29);

		swapbuffers();
    }
}

void wreck_right()
{
	if(matriksmaps->maps[i+1][j+1] == 1)
    {
		matriksmaps->maps[i+1][j+1] = 0;
		a = i+1;
		b = j+1;

		clearviewport();

		setviewport(0, 0, getmaxx(), getmaxy(), 1);
		putimage(10,0,map, COPY_PUT);
        readimagefile("Image\\Map\\blank.bmp",10+30*(j+1),30*(i+1),39+30*(j+1),29+30*(i+1));
		getimage(10,0,790,600,map);
		waktu = clock();
		time_start = ((double)waktu)/CLOCKS_PER_SEC;
		count_time();

		setviewport(10+x,y,40+x,30+y, 1);

		readimagefile(character,0,0,29,29);

    	swapbuffers();
	}
}

void count_time()
{
    waktu = clock() - waktu;
    time_taken = ((double)waktu)/CLOCKS_PER_SEC;

    printf("%f",time_taken);
}
