/*
This program handles the program and parameter inputs. The basic function is like below:
cmd -s [startaddr] -e [endaddr] -n[loop] -t -q [-h] 
-s start address 
-e end address 
-n loop 
-t print time 
-q quite mode
-h help manual

Return:
If input error, return -1;
If success, return 0;

*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int getopt(int argc,char * const argv[], const char *optstring);
extern char *optarg;
extern int optind,opterr,optopt;

int string_to_num(char* str);
void print_help();
int main(int argc,char *argv[])
{
	unsigned int opt = 0;
	int start = 0,end = 0, loop = 0, time_flag = 0, quite_flag = 0;

//	printf("argc = %d,argv[0] = %s.\n",argc,argv[0]);
	while((opt = getopt(argc,argv,"s:e:n:tqh")) != -1)
	{
	//	printf("optind = %d\n",optind);
		switch(opt)
		{
			case 's':
				start = string_to_num(optarg);
				printf("start address is 0x%x\n", start);
				break;
			case 'e':
				end = string_to_num(optarg); 
				printf("start address is 0x%x\n", end);
				break;
			case 'n':
				loop = string_to_num(optarg);
				printf("loop is 0x%x\n", loop);
				break;
			case 't':
				time_flag = 1;
				printf("Time flag\n");
				break;
			case 'q':
				quite_flag = 1;
				printf("Quite flag\n");
				break;
			case 'h':
				print_help();
				break;
			case '?':
				break;
			default:
				break;
		}
	}
	
	return 0;
}

int string_to_num(char* str)
{
	int len;
	int i = 0;
	char hexflag = 0;
	int value = 0; 

	len = strlen(str);
	if(str[0] == '0' && str[1] == 'x')
		hexflag = 1; 
	if(hexflag == 1){
		i = 2;
		//len = len -2; 
		while(i<len){
			value <<= 4;
			if(!((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'f') || (str[i] >= 'A' && str[i] <= 'F')) ){
				printf("argument format error in x16! \n");
				exit(1);
			}
			switch(str[i]){
				case '1':
					value += 1;
					break;
				case '2':
					value += 2;
					break;
				case '3':
					value += 3;
					break;
				case '4':
					value += 4;
					break;
				case '5':
					value += 5;
					break;
				case '6':
					value += 6;
					break;
				case '7':
					value += 7;
					break;
				case '8':
					value += 8;
					break;
				case '9':
					value += 9;
					break;
				case 'a':
				case 'A':
					value += 10;
					break;
				case 'b':
				case 'B':
					value += 11;
					break;
				case 'c':
				case 'C':
					value += 12;
					break;
				case 'd':
				case 'D':
					value += 13;
					break;
				case 'e':
				case 'E':
					value += 14;
					break;
				case 'f':
				case 'F':
					value += 15;
					break;
			}
			i++;
		}
	}else{
		while(i<len){
			if(!((str[i] >= '0' && str[i] <= '9'))){
				printf("argument format error in x10!\n");
				exit(1);
			}
			i++;
		}
		value = atoi(str);
	}
	
	return value;	
}

void print_help()
{
	printf("-s startaddress -----------------> specify start address\n");
	printf("-s startaddress -----------------> specify start address\n");
	printf("-s startaddress -----------------> specify start address\n");
	printf("-s startaddress -----------------> specify start address\n");
}	
