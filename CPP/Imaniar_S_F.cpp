#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <malloc.h>
#include <string.h>
#include "..\\Header\\Imaniar_S_F.h"
#include "..\\Header\\Rendi_K_A.h"
#include "..\\Header\\Satria_N_B.h"



extern int i,j,k,stat,page,point,box;
extern float x,y;
extern void *map;
extern int matriksmap[20][26];
extern char character[40],arah;
extern temp A[10],tBox[5],ladder;
extern address matriksmaps;

int m = 1;
int status;

void load_box()
{
	int p = 0;
	while (k > p)
    {
        if (matriksmaps->maps[tBox[p].temp_i][tBox[p].temp_j] == 5)
        {
        	readimagefile("Image\\Map\\box.gif",11+30*tBox[p].temp_j,30*tBox[p].temp_i,40+30*tBox[p].temp_j,29+30*tBox[p].temp_i);
		}
		p++;
    }
}

void cek_box()
{
	if (matriksmaps->maps[i][j] == 5)
    {
        matriksmaps->maps[i][j] = 0;
		point++;
		box++;
        printf("point : %d\n",point);
        if(box>=4)
        {
//        	printf("%d,%d",ladder.temp_i,ladder.temp_j);
            matriksmaps->maps[ladder.temp_i - 1][ladder.temp_j]=3;
            matriksmaps->maps[ladder.temp_i][ladder.temp_j]=3;
	        clearviewport();

			setviewport(0, 0, getmaxx(), getmaxy(), 1);

			putimage(10,0,map, COPY_PUT);
			readimagefile("Image\\Map\\ladder.gif",10+30*ladder.temp_j,30*(ladder.temp_i-1),39+30*ladder.temp_j,29+30*(ladder.temp_i-1));
			readimagefile("Image\\Map\\ladder.gif",10+30*ladder.temp_j,30*ladder.temp_i,39+30*ladder.temp_j,29+30*ladder.temp_i);
			load_score();
			getimage(10,0,790,600,map);

			swapbuffers();
		}
    }
}

void run_r()
{
	if(m > 8)
	{
		m = 1;
	}
	sprintf(character,"Image\\Character\\Right\\%d.gif", m);
	m++;
}

void run_l()
{
	if(m > 8)
	{
		m = 1;
	}
	sprintf(character,"Image\\Character\\Left\\%d.gif", m);
	m++;
}

void idle()
{
	if(m > 8)
	{
		m = 1;
	}
	if (((x>(j*30)-18 && matriksmaps->maps[i][j-1]!=4 && matriksmaps->maps[i][j] == 4) || (matriksmaps->maps[i][j-1]==4 && matriksmaps->maps[i][j] == 4) || (x<(j*30)+18 && matriksmaps->maps[i][j+1]!=4 && matriksmaps->maps[i][j] == 4)) && y==i*30)
	{
		sprintf(character,"Image\\Character\\Rope\\2.gif");
	}else if(matriksmaps->maps[i][j] == 3 || (matriksmaps->maps[i][j]!=3 && y > i*30))
	{
		sprintf(character,"Image\\Character\\Climb\\1.gif");
	}else
	{
		if (arah == 'R')
		{
			sprintf(character,"Image\\Character\\Idle\\R\\%d.gif", m);
		}else
		{
			sprintf(character,"Image\\Character\\Idle\\L\\%d.gif", m);
		}

	}

	delay(50);
	m++;
}

void rope_r()
{
	if(m > 8)
	{
		m = 2;
	}
	sprintf(character,"Image\\Character\\Rope\\%d.gif", m);
	delay(50);
	m++;
}

void rope_l()
{
	if(m < 2 || m > 8)
	{
		m = 8;
	}
	sprintf(character,"Image\\Character\\Rope\\%d.gif", m);
	delay(50);
	m--;
}

void climb_up()
{
	if(m > 8)
	{
		m = 1;
	}
	sprintf(character,"Image\\Character\\Climb\\%d.gif", m);
	m++;
}

void climb_dw()
{
	if(m < 1 || m > 8)
	{
		m = 8;
	}
	sprintf(character,"Image\\Character\\Climb\\%d.gif", m);
	m--;
	if(m == 0)
	{
		m = 1;
	}
}

void pause()
{
    printf("\npause");
    if (stat == 4)
    {
        stat=status;
    }
    else
    {
        status=stat;
        stat = 4;
        setviewport(0, 0, getmaxx(), getmaxy(), 1);
        putimage(10,0,map, COPY_PUT);
        setviewport(10+x,y,40+x,30+y, 1);
        readimagefile(character,0,0,29,29);
        setviewport(0, 0, getmaxx(), getmaxy(), 1);
        setcolor(RED);

        setfillstyle(SOLID_FILL, BLACK);
        rectangle(getmaxx()/2-151, getmaxy()/2-80, getmaxx()/2+151, getmaxy()/2+77);
        floodfill(getmaxx()/2, getmaxy()/2, RED);

        settextstyle(BOLD_FONT,HORIZ_DIR, 8);
        outtextxy(getmaxx()/2-141,getmaxy()/2-70,"PAUSED");
        settextstyle(COMPLEX_FONT,HORIZ_DIR, 2);
        outtextxy(getmaxx()/2-126,getmaxy()/2+15,"Press 'P' to Continue");
        outtextxy(getmaxx()/2-126,getmaxy()/2+41,"Press 'Enter' to Menu");

        swapbuffers();
    }

    printf("test");
}

