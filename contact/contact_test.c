#include <string.h>
#include <stdio.h>
#include <sys/io.h>
#include <stdlib.h>

#define contact_file "contact.data"
enum sex {male,female};
struct contacts {
	int number;
	char name[20];
	char phone[20];
	enum sex s;
	char address[20];	
};

char menu[6][30] = {"1 add contact", "2 delete contact", "3 search contact", "4 view contacts","5 delete all", "6 quit"};
int add_contact();
void del_contact();
void view_all();
void quit();
int save_contact(struct contacts *person);

void write_to_file(struct contacts *c);
void print_contact(struct contacts *p);
void search_contact();

void show_menu(){
	int i=0; 
	while(i<6){
		printf("%s.\n",menu[i]);
		i++;
	}	
}	

void clear_screen(){
	system("clear");
}

typedef struct contacts ElementType;
struct Person{
	ElementType e;
	struct Person *next;	
};

struct Person *Head;

void main()
{
	char ch;
	clear_screen();
	show_menu();	
	Head = (struct Person*) malloc(sizeof(struct Person));
	while(1){
		ch = getchar();
		switch(ch){
		case '1':
		add_contact();
		break;
		case '2':
		del_contact();
		break;
		case '4':
		view_all();
		break;
		case '3':
		search_contact();
		break;
		case '6':
		quit();
		exit(0);
		break;
		}
	}
}


void print_contact(struct contacts *p){

printf("name = %s.\n number = %d.\n address = %s.\n",p->name,p->number,p->address);
	
}
int add_contact(){
	struct contacts *person;	
	char ch;
	person =(struct contacts*)malloc(sizeof(struct contacts));
	if(person == NULL){
		printf("malloc failure.\n");
		return -1;
	}
	memset(person,0,sizeof(struct contacts));
	
	clear_screen();
	while(1){
#if 1
		printf("pls input name:\n");
		scanf("%s",person->name);
		printf("pls input number:\n");
		scanf("%d",&person->number);
		printf("pls input address:\n");
		scanf("%s",person->address);
		write_to_file(person);
#endif 	
		printf("continue to add? (Y/N)\n");
		do{
			scanf("%c",&ch);
			printf("ch = %d\n",ch);
		}while(ch == '\n');
//	while( ch=getchar()!='\n'); 
		if(ch == 'Y' || ch == 'y'){
			continue;
		}else{
			clear_screen();
			show_menu();		
			break;
		}
	}
	
	free(person);	
}
void write_to_file(struct contacts *c){
	FILE *f = fopen(contact_file,"a");
	if(f != NULL){
		fwrite(c,sizeof(struct contacts),1,f);
	fclose(f);
	}
	return;
}

int read_file(struct contacts *c,int count){
	FILE *f = fopen(contact_file,"r");
	if(f != NULL){
		fread(c,sizeof(struct contacts),1,f);
	}
	fclose(f);
}

int save_contact(struct contacts *person){
	FILE *p = NULL;
	p = fopen(contact_file,"a");
	if(p == NULL){
		printf("open file fialure.\n");
		return -1;
	}	
	fprintf(p,"%d,%s,%s\n",person->number,person->name,person->address);
	fclose(p);
	return 0;
}
void del_contact(){

}


void view_all(){
	int length;
	int i;
	struct contacts c;

	FILE *f = fopen(contact_file,"r");
	if(f != NULL){
		fseek(f,0,SEEK_END);
	//	printf("length = %d\n",ftell(f));
		length = ftell(f)/sizeof(struct contacts);
		
	}
	i = 0;
	while(i<length){
		fseek(f,i*sizeof(struct contacts),SEEK_SET);
		fread(&c,sizeof(struct contacts),1,f);
		printf("%d,%s,%s\n",c.number,c.name,c.address);
		i++;
				
	}	
	fclose(f);
}
int read_contact(){
}
void search_contact(){
	char ch[20];
	long int count;
	long int length,i;
	struct contacts c;
	printf("pls input name:\n");
	scanf("%s",ch);
		
	FILE *f = fopen(contact_file,"r");
	if(f != NULL){
		fseek(f,0,SEEK_END);
	//	printf("length = %d\n",ftell(f));
		length = ftell(f)/sizeof(struct contacts);
		
	}
	i = 0;
	while(i<length){
		fseek(f,i*sizeof(struct contacts),SEEK_SET);
		fread(&c,sizeof(struct contacts),1,f);
		if(0 == strcmp(c.name,ch)){
			printf("found:%d,%s,%s\n",c.number,c.name,c.address);
			fclose(f);
			return;
		}
		i++;
	}
	fclose(f);	
	printf("not found\n");
	return;
}

void quit(){


}
