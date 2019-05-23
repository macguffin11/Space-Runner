#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <stdbool.h>
#include "..\\Header\\Rendi_K_A.h"
#include "..\\Header\\Satria_N_B.h"
#include "..\\Header\\Imaniar_S_F.h"

extern int point, mati, stat, nyawa, ulang, level, box;
extern int peti1[5],peti2[5], k, l, tangga;
extern int matriksmap[20][26], temp_m[20][26];
extern temp tBox[5];
extern void *map;
extern address matriksmaps, pNew;

void window()
{
    initwindow(800, 600, "Output",(getmaxwidth()/2)-400,(getmaxheight()/2)-300);	// GETMAX UNTUK MENCARI KOORDINAT X DAN Y MAKSIMAL.
}

/*bool Check_box()
{
	if
	return flase;
}*/

void load_score()
{
	char poin[10];
    setcolor(WHITE);
    settextstyle(BOLD_FONT,HORIZ_DIR, 1);
    sprintf(poin,"Score : %d", point);
    outtextxy(100,550,poin);
    sprintf(poin,"Level : %d", level+1);
    outtextxy(300,550,poin);
    sprintf(poin,"Life : %d", nyawa);
    outtextxy(500,550,poin);
}

void cek_mati()
{
	int p = 0;
	if (ulang == 1 && stat != 3)
        {
            while (k > p)
            {
                matriksmaps->maps[tBox[p].temp_i][tBox[p].temp_j] = 5;
//                printf("BOX = %d\n",matriksmaps->maps[peti1[p]][peti2[q]]);

        		printf("p = %d\n",p);
				p++;
            }
			k = 0;
			l = 0;

            if (mati == 1)
            {
                setcolor(RED);

		        setfillstyle(SOLID_FILL, BLACK);
		        rectangle(getmaxx()/2-245, getmaxy()/2-80, getmaxx()/2+245, getmaxy()/2+10);
		        floodfill(getmaxx()/2, getmaxy()/2, RED);

	            settextstyle(BOLD_FONT,HORIZ_DIR, 8);
                outtextxy(getmaxx()/2-235,getmaxy()/2-70,"Game Over!");
                ulang = 0;
            	point = 0;
            	box = 0;
                stat = -1;
				free(map);
            	swapbuffers();
                delay(3000);
                //nyawa = 3;
//                exit(1);
            }else
            {

            	setcolor(RED);

		        setfillstyle(SOLID_FILL, BLACK);
		        rectangle(getmaxx()/2-128, getmaxy()/2-80, getmaxx()/2+128, getmaxy()/2+10);
		        floodfill(getmaxx()/2, getmaxy()/2, RED);

	            settextstyle(BOLD_FONT,HORIZ_DIR, 8);
	            outtextxy(getmaxx()/2-118,getmaxy()/2-70,"Dead!");
	            printf("Dead!" );
	            swapbuffers();
	            stat = 0;
	            tangga = 0;
	            ulang = 0;
            	box = 0;
				free(map);
	            delay(3000);
//	            swapbuffers();
			}
        }
}

void Create_Node (address *p)
{
	*p=(address)malloc(sizeof(levell));
	(*p)->next=NULL;
	printf("\nNode Berhasil Dibuat ");
}

void Ins_Akhir (address *p, address PNew)
{
	address tail;

	tail = *p;
	while (tail->next!=NULL)
	{
		tail=tail->next;
	}
	tail->next=PNew;
}

void load_matriksmap()
{
	int read = 0,i,maps_t[20][26];
	FILE *ifp = fopen("Library\\matriksmap.dat", "rb");
	read = fread(maps_t, sizeof(char), sizeof(maps_t), ifp);
	printf("read = %d", read);
	if (read == 0) {
	    printf("Error load matriks !");
	}else if (matriksmaps == NULL)
	{   i = 0;
	    while (!feof(ifp)){
            fseek(ifp, i*sizeof(pNew->maps), SEEK_SET);
            if (matriksmaps == NULL) {
                Create_Node(&matriksmaps);
                fread(matriksmaps->maps, sizeof(char), sizeof(matriksmaps->maps), ifp);
            }else {
                Create_Node(&pNew);
                fread(pNew->maps, sizeof(char), sizeof(pNew->maps), ifp);
                Ins_Akhir(&matriksmaps,pNew);
            }
            i++;
	    }

	}

	fclose(ifp);
}

void menu()
{
	bool kembali;
	printf("menu");
	int x=0, y=0;
    int maxx = getmaxx()/2, maxy = getmaxy()/2;
    clearviewport();
	setviewport(0, 0, getmaxx(), getmaxy(), 1);
    swapbuffers();
    clearviewport();
	setviewport(0, 0, getmaxx(), getmaxy(), 1);

    readimagefile("Menu//judul.gif", 100, 50,  600,200);

    setcolor(WHITE);
    rectangle(maxx-52,maxy-140,maxx+52,maxy-104);
    settextstyle(SMALL_FONT, HORIZ_DIR, 9);
    outtextxy(maxx-47, maxy-135, "PLAY");

    rectangle(maxx-130,maxy-79,maxx+130,maxy-43);
    settextstyle(SMALL_FONT, HORIZ_DIR, 9);
    outtextxy(maxx-125, maxy-74, "HOW TO PLAY");

    rectangle(maxx-169, maxy-18, maxx+169, maxy+18);
    settextstyle(SMALL_FONT, HORIZ_DIR, 9);
    outtextxy(maxx-164, maxy-13, "CONTROL BUTTON");

	rectangle(maxx-67, maxy+43, maxx+67, maxy+79);
    settextstyle(SMALL_FONT, HORIZ_DIR, 9);
    outtextxy(maxx-62, maxy+48, "ABOUT");

	rectangle(maxx-46,maxy+104,maxx+46,maxy+140);
    settextstyle(SMALL_FONT, HORIZ_DIR, 9);
    outtextxy(maxx-41, maxy+109, "EXIT");

//    getch();
	swapbuffers();
    while(stat == -1){
    	kembali = false;

        getmouseclick(WM_LBUTTONDOWN, x, y);
//        printf("%d,%d",x,y);
        //masuk ke permaianan
        if((x>maxx-52)&&(x<maxx+52)&&(y>maxy-140)&&(y<maxy-104)){
            stat = 0;

        }
        //Menampilkan cara bermain
        else if((x>maxx-130)&&(x<maxx+130)&&(y>maxy-79)&&(y<maxy-43)){
		    clearviewport();
			setviewport(0, 0, getmaxx(), getmaxy(), 1);

        	readimagefile("Image\\Menu\\How To Play.gif",10,0,790,600);
            setcolor(WHITE);
		    rectangle(maxx-57,maxy+254,maxx+57,maxy+290);// 104 36
		    settextstyle(SMALL_FONT, HORIZ_DIR, 9);
		    outtextxy(maxx-50, maxy+259, "MENU");// 94 26
		    swapbuffers();

		    while (!kembali){
		    	getmouseclick(WM_LBUTTONDOWN, x, y);

		    	if((x>maxx-52)&&(x<maxx+52)&&(y>maxy+254)&&(y<maxy+290)){
		            kembali = true;
		        }
			}
			menu();
        }
        //Menampilkan Control Button
        else if((x>maxx-169)&&(x<maxx+169)&&(y>maxy-18)&&(y<maxy+18)){
		    clearviewport();
			setviewport(0, 0, getmaxx(), getmaxy(), 1);

        	readimagefile("Image\\Menu\\Control Button.gif",10,0,790,600);
            setcolor(WHITE);
		    rectangle(maxx-57,maxy+254,maxx+57,maxy+290);// 104 36
		    settextstyle(SMALL_FONT, HORIZ_DIR, 9);
		    outtextxy(maxx-50, maxy+259, "MENU");// 94 26
		    swapbuffers();

		    while (!kembali){
		    	getmouseclick(WM_LBUTTONDOWN, x, y);

		    	if((x>maxx-52)&&(x<maxx+52)&&(y>maxy+254)&&(y<maxy+290)){
		            kembali = true;
		        }
			}
			menu();
        }
        //Menampilkan about
        else if((x>maxx-67)&&(x<maxx+67)&&(y>maxy+43)&&(y<maxy+79)){
		    clearviewport();
			setviewport(0, 0, getmaxx(), getmaxy(), 1);

        	readimagefile("Image\\Menu\\About.gif",10,0,790,600);
            setcolor(WHITE);
		    rectangle(maxx-57,maxy+254,maxx+57,maxy+290);// 104 36
		    settextstyle(SMALL_FONT, HORIZ_DIR, 9);
		    outtextxy(maxx-50, maxy+259, "MENU");// 94 26
		    swapbuffers();

		    while (!kembali){
		    	getmouseclick(WM_LBUTTONDOWN, x, y);

		    	if((x>maxx-52)&&(x<maxx+52)&&(y>maxy+254)&&(y<maxy+290)){
		            kembali = true;
		        }
			}
			menu();
        }
        //Keluar dari permainan
        else if((x>maxx-46)&&(x<maxx+46)&&(y>maxy+104)&&(y<maxy+140)){
        	clearviewport();
			setviewport(0, 0, getmaxx(), getmaxy(), 1);

            settextstyle(COMPLEX_FONT, HORIZ_DIR, 5);
            outtextxy(maxx-104, maxy-21, "GOOD BYE");
			swapbuffers();
			printf("exit");
			delay(3000);
			free(map);
        	closegraph();
        	exit (0);
        }

    }
}
