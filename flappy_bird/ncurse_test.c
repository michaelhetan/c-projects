#include <unistd.h>
#include <stdlib.h>
#include <curses.h>
#include <sys/time.h>
#include <signal.h>

int bird_x =3, bird_y =20;
#define BIRD '*'
#define NONE ' '
void alarm_handler();
typedef struct wall{
	int x,y;
	struct wall *next;
}wall,*Wall;


void set_alarm(int sec);
int rand_y();
void display_one_block(Wall w);
Wall head,tail;
int block_cnt;

void init()
{
	initscr();
	noecho();
	cbreak();
	curs_set(0);
	refresh();
}
//#define DEBUG
void init_wall()
{
	head =(Wall) malloc(sizeof(wall));
	head->next = NULL;
	head->x = 10;
	head->y = rand_y();
	block_cnt++;
	int i,j;
	Wall p = head;
	for(;p->next == NULL;p = p->next){
		p->next = (Wall)malloc(sizeof(wall));
		p->next->x = p->x +30;
		p->next->y = rand_y();
		p->next->next = NULL;
		block_cnt++;
		if(p->next->x > 150) break;
	}
	tail = p->next;
	block_cnt =0;
	p = head;
	do{
		display_one_block(p);
		p = p->next;

	block_cnt++;
	}while(p->next != NULL);
	display_one_block(tail);
		
	p = head->next;
	do{
		x = p->x;
		y = p->y;
		for(i=0;i<10;i++)
		{
			for(j=0;j<40;j++)
			{
				move(j,i+x);
				if(j>y && j< (y+5))
				{
				addch(' ');
				refresh();	
				}else{
				addch(BIRD);
				refresh();
				}
			}
		} 
	p = p->next;
	sleep(1);
	
	}while(p->next != NULL);
}
int main()
{
	char key;
	init();
	init_wall();
	set_alarm(1);
    signal(SIGALRM,alarm_handler);
	while(1)
	{
		key = getch();
		if(key == 'w' || key==' ')
		{
			move(bird_y,bird_x);
    		addch(NONE);
			refresh();
			bird_y--;
			move(bird_y,bird_x);
			if((char)inch() == BIRD){   
				set_alarm(0);
				endwin();
				exit(0);
			}else{	
				addch('O');
				refresh();
			}
		}
	}
	getch();
	endwin();
}

void alarm_handler()
{
	Wall p = head->next;
	int x,y,i,j;
	move(bird_y,bird_x);
	addch(NONE);
	refresh();
	bird_y++;
	//addch(BIRD);
	move(bird_y,bird_x);
	if((char)inch() == BIRD){   
		set_alarm(0);
		exit(0);
		endwin();
	}else{	
		addch('O');
		refresh();
	}
	if(head->x <= -20){
		head->x = tail->x +30;
		head->y = rand_y();
		p = head;
		head = head->next;
		tail->next = p;
		tail = p;
		tail->next = NULL;
	}

	p = head;
    do{ 
#ifdef DEBUG
        printf("one block.\n");
#endif 
	p->x--;
	display_one_block(p);
    p = p->next;
   // sleep(1);
        
    }while(p->next != NULL);
	tail->x--;		
	display_one_block(tail);
}

void display_one_block(Wall w)
{
	int i,j;
	for(i=0;i<10;i++){
		for(j=0;j<40;j++){
			if(j != bird_y || (w->x+i) != bird_x){
			if((w->x) +i >= 0 ){	
                	move(j,i+w->x);
                	if(j>w->y && j< (w->y+5))
                	{   
                	addch(' ');
                	refresh();  
                	}else{
                	addch(BIRD);
                	refresh();
                	}
			}else{
				move(j,0);
				addch(' ');
				refresh();
			}
		
      		if(i == 9)
            	{   
                	move(j,(w->x)+10);
                	addch(' ');
                	refresh();
            	}
		}
	}
	}

}

int rand_y()
{
	int y;

	do{
		y = rand()%40;
	}while(y<15 ||y>25);
	
	return y;
}

void set_alarm(int sec)
{	
	struct itimerval old;

    old.it_interval.tv_sec = sec;
    old.it_interval.tv_usec = 0;
    old.it_value.tv_sec = sec;
    old.it_value.tv_usec = 0;
    setitimer(ITIMER_REAL,&old,NULL);
}
