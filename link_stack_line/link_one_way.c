#include <stdio.h>
#include <stdlib.h>
#include "link_one_way.h"

pNode init_link()
{
	pNode head;
	head = (pNode)malloc(sizeof(Node));
	if(head == NULL){
		printf("malloc head fail\n");	
		return NULL;
	}
	head->next = NULL;
	return head;
}

int add_node(pNode h,pNode n)
{
	pNode p = h;
	
	while(p->next != NULL){
		p = p->next;
	}
	p->next = n;
	n->next = NULL;
	
	return 0;
}

int insert_node(pNode head,pNode n,int position)
{
	pNode p = head;
	int i;
	int count;

	count = link_count(head);
	if(position >count){
		printf("not enough node\n");
		return -1;
	}
	for(i=0;i<position;i++){
		p = p->next;		
	}	
	n->next = p->next;
	p->next = n;
	
	return 0;
}

int del_node(pNode head,int position)
{
	pNode p = head;
	int i;
	int count;
	count = link_count(head);
	if(position >count){
		printf("not enough node\n");
		return -1;
	}
	for(i=0;i<position;i++){
		p = p->next;		
	}	
	free(p->next);
	p->next = p->next->next;	
	return 0;
}

int link_count(pNode head)
{
	int count;
	pNode p = head;
	while(p->next != NULL){
		p = p->next;
		count++;
	}
	return count;
}

int free_link(pNode head)
{
	pNode p = head;
	while(p->next != NULL){
		free(p);
		p = p->next;
	}
	return 0;
}
