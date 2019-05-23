#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <malloc.h>
#include <windows.h>
#include <time.h>
#include "..\\Header\\Imaniar_S_F.h"
#include "..\\Header\\Luthfi_A.h"
#include "..\\Header\\Rezky_W_S.h"
#include "..\\Header\\Rendi_K_A.h"
#include "..\\Header\\Satria_N_B.h"


extern int i,j,stat,a,b,level,point,box,k;
extern float x,y;
extern void *map;
extern int matriksmap[20][26];
extern double time_taken,time_start;
extern temp A[10];
extern clock_t waktu;
extern int mati, nyawa, ulang;
extern char character[40],arah;
extern address matriksmaps;

void left ()
{
	if ((matriksmaps->maps[i][j-1]!=1 && matriksmaps->maps[i][j-1]!=2 && j>0 && (x>((j-1)*30))) || (matriksmaps->maps[i][j]!=2 && matriksmaps->maps[i][j]!=1 && x>(j)*30))
    {
        x = x - 6;
        if (x<((j)*30)-24)
        {
            j = j - 1;
		}

		if (matriksmaps->maps[i][j]!=4 || (matriksmaps->maps[i][j] == 4 && y != i*30))
		{
			run_l();
		}else if (((x<=((j)*30) && matriksmaps->maps[i][j-1]==4 && matriksmaps->maps[i][j]==4) || (matriksmaps->maps[i][j-1]!=4 && x>((j)*30)+24)) && y == i*30)
		{
			rope_l();
		}

        arah = 'L';

		printf("x = %f\n",x);
        printf("j = %d\n",j);
    }
}

void right ()
{
	if ((matriksmaps->maps[i][j+1]!=1 && matriksmaps->maps[i][j+1]!=2 && j<25 && (x<((j+1)*30))) || (matriksmaps->maps[i][j]!=2 && matriksmaps->maps[i][j]!=1 && x<(j)*30))
    {
        x = x + 6;
        if (x>((j)*30)+24)
        {
            j = j + 1;
		}

		if (matriksmaps->maps[i][j]!=4)
		{
			run_r();
		}else if (((x>=((j)*30) && matriksmaps->maps[i][j+1]==4 && matriksmaps->maps[i][j]==4) || (matriksmaps->maps[i][j+1]!=4 && x<((j)*30)-24)) && y == i*30)
		{
			rope_r();
		}

        arah = 'R';
                        printf("x = %f\n",x);
                        printf("j = %d\n",j);
    }

}

void up ()
{
	if ((matriksmaps->maps[i-1][j]!=1 && matriksmaps->maps[i-1][j]!=2 && matriksmaps->maps[i][j]!=4 && matriksmaps->maps[i][j]!=0 && (y>((i-1)*30)) && x == j*30) || (matriksmaps->maps[i][j]!=2 && matriksmaps->maps[i][j]!=1 && y>i*30))
    {
        y = y - 6;
        if (y<=((i)*30)-6)
        {
            i = i - 1;
		}


		if (matriksmaps->maps[i][j]==3 || (matriksmaps->maps[i][j]!=3 && y > i*30))
		{
			climb_up();
		}
                        printf("y = %f\n",y);
                        printf("i = %d\n",i);
    }
}

void down ()
{
	if ((matriksmaps->maps[i+1][j]!=1 && matriksmaps->maps[i+1][j]!=2 && y<((i+1)*30) && x>=(((j-1)*30)+1) && x<=(j*30)+1) || (matriksmaps->maps[i][j]==3 && y<(i)*30))
    {
        y = y + 6;
        if (y==((i+1)*30))
        {
            i = i + 1;
		}

		if (matriksmaps->maps[i][j]==3 || (matriksmaps->maps[i][j]!=3 && y > i*30))
		{
			climb_dw();
		}
                        printf("y = %f\n",y);
                        printf("i = %d\n",i);
    }
}

void fall ()
{
//    delay(75);
	if((matriksmaps->maps[i+1][j] == 0 && matriksmaps->maps[i][j]!=4 && matriksmaps->maps[i][j]!=3) || matriksmaps->maps[i+1][j] == 5 || matriksmaps->maps[i+1][j] == 4 || (matriksmaps->maps[i+1][j]==0 && y>(i)*30))
	{
		stat = 2;
	    y = y + 6;
        if (y==((i+1)*30))
        {
            i = i + 1;
		}

		if (arah == 'R')
		{
			sprintf(character,"Image\\Character\\Right\\1.gif");
		}else
		{
			sprintf(character,"Image\\Character\\Left\\1.gif");
		}
	}else if (matriksmaps->maps[i][j] == 4 && y< i*30)
	{
		stat = 2;
		y = y + 6;
	    if (y==((i+1)*30))
	    {
	        i = i + 1;
		}

		if (arah == 'R')
		{
			sprintf(character,"Image\\Character\\Right\\1.gif");
		}else
		{
			sprintf(character,"Image\\Character\\Left\\1.gif");
		}
	}else
	{
		stat = 1;
	}
}

void control()
{
	if (stat == 1)
	{
	    if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	    {
	    	right();
		}
	    if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	    {
	    	left();
		}
	    if (GetAsyncKeyState(VK_UP) & 0x8000)
	    {
	    	up();
		}
	    if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	    {
	    	down();
		}

	    if (GetAsyncKeyState(0x5A) & 0x8000)
	    {
	    	wreck_left();
		}
	    if (GetAsyncKeyState(0x58) & 0x8000)
	    {
	    	wreck_right();
		}

		if (GetAsyncKeyState(0x50) & 0x8000)
	    {
	    	pause();
		}

		if (time_start > 0)
        {
            count_time();
        }

        if (time_taken > 3+time_start)
        {
            matriksmaps->maps[a][b] = 1;
            time_taken = -1;
            time_start = -1;
            waktu = 0;
            stat = 3;

            if (matriksmaps->maps[i][j] == 1)
            {
                nyawa--;
                ulang = 1;
                if(nyawa == 0)
                {
                	mati = 1;
				}
            }
        }
	    cek_box();
	    if(!GetAsyncKeyState(VK_RIGHT) && !GetAsyncKeyState(VK_LEFT) && !GetAsyncKeyState(VK_UP) && !GetAsyncKeyState(VK_DOWN) && !GetAsyncKeyState(0x5A) && !GetAsyncKeyState(0x58) && !GetAsyncKeyState(0x50))
	    {
	    	idle();
		}

		if(i < 0 && level < 10)
        {
            stat = 0;
            level++;
            box = 0;
            k = 0;
            matriksmaps=matriksmaps->next;
            printf("level = %d",level);

        }

	}else if (stat == 4 || stat == 2)
	{
	    if (GetAsyncKeyState(0x50) & 0x8000)
	    {
			pause();

		}

		if (GetAsyncKeyState(VK_RETURN) & 0x8000)
	    {
	    	stat = -1;
		}
	}

	if (stat == 1 || stat == 2)
	{
		fall();
	}
//	delay(100);
}
