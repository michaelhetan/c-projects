#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

//int table[4][4] = {{11,0,23,456},{0,3415,143,234},{1234,23,3,3},{34,3,75,1234}};
int table[4][4] = {0};
void display();
void number_generate();
#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'

void init()
{
	int i,j;

	initscr();
	cbreak();
	noecho();
	curs_set(0);
	for(i=0;i<=20;i++){
		for(j=0;j<9;j +=2){
			move(j,i);
			addch('-');
			refresh();
		}
	}
	for(i=0;i<=20;i +=5){
		for(j=0;j<9;j +=2){	
			move(j,i);
			addch('|');
			refresh();
		}
	}	

}

void end()
{
	sleep(5);
	endwin();
	exit(0);
}

void main()
{
	char ch;
#if 0
	char test[6];
	scanf("%c %c %c %c",&test[0],&test[1],&test[2],&test[3]);
	printf("\nend");
	return;
#endif
	init();
	display();
	while(1){
		ch = getch();
		switch(ch){
		case UP:
//			number_generate();
//			display();	
			break;
		case DOWN:
			number_generate();
			display();	
			break;
		case LEFT:
			break;
		case RIGHT:
			break;
		default:
			break;
		}
		number_generate();
		display();	
	}	
	end();

}

/*display the 16 columns using table array data*/
void display()
{
	int i,j,k,l,tmp;
	int data[5] = {0};

	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			tmp = table[j][i];
			k = 0;
			while(tmp>0){
				data[k++] = tmp%10;
				tmp = tmp/10;	
			}
			for(l=0;l<k;l++){
			move(2*j+1,i*5+4-l);
			addch(data[l]+'0');
			refresh();
			}
			if(table[j][i] == 0){
				for(l=0;l<4;l++){
				move(2*j+1,i*5+4-l);
				addch(' ');
				refresh();
				}		
			}
		}
	}
}

void number_generate()
{
	int x,y,num,max =0;
	int i,j;
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			if(table[i][j] >max){
				max = table[i][j];
			}
		}
	}
	
	max = max/2;
	if(max != 0){
		do{
			x = rand()%4;
			y = rand()%4;
		}while(table[x][y] != 0);
		do{
			num = rand()%(max+1);
		}while(num ==0);
		table[x][y] = num*2;
		//table[x][y] = (rand()%(max+1))*2;
	}else{
		x = rand()%4;
		y = rand()%4;
		table[x][y] = 2;	
	}
	
}

void number_calc()
{
	int i,j,x,y,temp,l;

	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			temp = table[i][4-j];
			if(table[i][4-j] == 0){
				l++;
				continue;
			}else{
				for(x=0;x<3-j;x++){
					if(table[i][x] == 0){
						continue;
					}else if (temp == table[i][x]){
						
					}else{
						table[i][]
					}
				}
			}
		}
	}		
}
