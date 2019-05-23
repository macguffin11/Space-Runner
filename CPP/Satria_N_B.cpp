#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <malloc.h>
#include "..\\Header\\Imaniar_S_F.h"
#include "..\\Header\\Satria_N_B.h"
#include "..\\Header\\Rendi_K_A.h"

extern int i,j,stat,page,a,b,level,box;
extern float x,y;
extern void *map;
extern unsigned long size;
extern int matriksmap[20][26];
extern int point, temp_m[20][26], temp_n[20][26], k;
extern temp A[10],tBox[5],chara,ladder;
extern char character[40];
extern address matriksmaps;

void maps(int i, int j)
{

    printf("isi = %d", matriksmaps->maps[i][j] );
	switch(matriksmaps->maps[i][j])
    {
        case 0 :{
			break;//elemen kosong
			}
        case 1 :{
            readimagefile("Image\\Map\\brick.gif",10+30*j,30*i,39+30*j,29+30*i);
            break;
            }
        case 2 :{
            readimagefile("Image\\Map\\hard_brick.gif",10+30*j,30*i,39+30*j,29+30*i);
            break;
            }
        case 3 :{
            readimagefile("Image\\Map\\ladder.gif",10+30*j,30*i,39+30*j,29+30*i);
            break;
            }
        case 4 :{
            readimagefile("Image\\Map\\rope.gif",10+30*j,30*i,39+30*j,29+30*i);
            break;
            }
        case 5 :{
        	tBox[k].temp_i = i;
        	tBox[k].temp_j = j;
        	printf("k = %d\n",k);
        	k++;
			break;
			}
        case 6 :{
            chara.temp_i = i;
            chara.temp_j = j;
            matriksmaps->maps[i][j] = 0;
            break;
            }
        case 7 :{
            ladder.temp_i = i;
            ladder.temp_j = j;
            matriksmaps->maps[i][j] = 0;
            break;
            }
    }
}

void load_map()
{
	//load_matriksmap();
	i=0;
    while(i<4){
        j=0;
		while(j<26){
            maps(i, j);
            maps(4+i,j);
            maps(8+i,j);
            maps(12+i,j);
            maps(16+i,j);
        	j++;
    	}
    	i++;
	}
	printf("%d",&matriksmaps->maps);
}

void render ()
{
	clearviewport();
	setviewport(0, 0, getmaxx(), getmaxy(), 1);
	cek_mati();

	switch (stat)
	{
		case (-1):{
			k = 0;
            point = 0;
            box = 0;
			free(map);
			menu();
			break;
		}
		case 0:{
			swapbuffers();
			//load_matriksmap();
			//setviewport(0, 0, getmaxx(), getmaxy(), 1);
            //clearviewport();
			setviewport(0, 0, getmaxx(), getmaxy(), 1);
            readimagefile("Image\\Background\\2.bmp",10, 0, 790, 510);
			load_map();
			load_score();

			size = imagesize(10,0,790,600);
		    map = malloc(size);
		    getimage(10,0,790,600,map);

			load_box();
		    i = chara.temp_i;
		    j = chara.temp_j;
		    x = j*30;
		    y = i*30;
		    setviewport(10+x,y,40+x,30+y, 1);

		    readimagefile(character,0,0,29,29);

			swapbuffers();
			stat = 1;
			break;
		}
		case 1:{
			clearviewport();

			setviewport(0, 0, getmaxx(), getmaxy(), 1);
		    putimage(10,0,map, COPY_PUT);
			load_score();
            getimage(10,0,790,600,map);
			load_box();


			setviewport(10+x,y,40+x,30+y, 1);

		    readimagefile(character,0,0,29,29);

			swapbuffers();
			break;
		}
		case 2:{
			clearviewport();

			setviewport(0, 0, getmaxx(), getmaxy(), 1);
		    putimage(10,0,map, COPY_PUT);
			load_score();
            getimage(10,0,790,600,map);
			load_box();

		    setviewport(10+x,y,40+x,30+y, 1);

		    readimagefile(character,0,0,29,29);

		    swapbuffers();
			break;
		}
		case 3:{
			clearviewport();
//		    page = 1 - page;
			setviewport(0, 0, getmaxx(), getmaxy(), 1);
			putimage(10,0,map, COPY_PUT);
		    readimagefile("Image\\Map\\brick.gif",10+30*b,30*a,39+30*b,29+30*a);
			load_score();
            getimage(10,0,790,600,map);
			load_box();

			setviewport(10+x,y,40+x,30+y, 1);

//		    readimagefile(character,0,0,29,29);

			swapbuffers();
			stat = 1;
            break;
		}
	}
	delay(100);
}
