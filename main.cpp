#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <time.h>

#include "Header\\Imaniar_S_F.h"
#include "Header\\Luthfi_A.h"
#include "Header\\Rezky_W_S.h"
#include "Header\\Rendi_K_A.h"
#include "Header\\Satria_N_B.h"

address matriksmaps;


int i,j;
int stat = -1,page = 0;
int point = 0, box = 0, k = 0, l = 0,a,b;
int mati = 0, nyawa = 3, ulang = 0, tangga = 0, level = 0;
int matriksmap[20][26];
float x,y;
void *map;
unsigned long size;
clock_t waktu;
double time_taken,time_start = 0;
char character[40] = "Image\\Character\\Idle\\1.gif", arah='R';
address pNew;

temp A[10],tBox[5],chara,ladder;

int main() {
    int lv=1;
	window();
	load_matriksmap();
    /*while(lv<=5)
    {
        Create_Node (&pNew);
        load_matriksmap();
        if(lv==1)
        {
            //Create_Node (&matriksmaps);
            //load_matriksmap(matriksmaps);
            matriksmaps=pNew;
            tail=matriksmaps;
            matriksmaps->maps[1][1]=5;

        }
        else{
            //Create_Node (&pNew);
            //load_matriksmap(pNew);
            tail->next=pNew;
            tail=pNew;
            pNew->maps[1][1]=3;
        }

        lv++;
    }*/
    while(true)
    {
    	control();
//		waktu = clock();
//		time_taken = ((double)waktu)/CLOCKS_PER_SEC;
//		printf("%f\n",time_taken - time_start);
//		waktu = clock();
//		time_start = ((double)waktu)/CLOCKS_PER_SEC;
//    	update();
		render();
    }
	return 0;
}
