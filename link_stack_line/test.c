#include <stdio.h>
#include "link_one_way.h"
#include <stdlib.h>


int main()
{
	pNode head = NULL;
	pNode n;
	pNode p;
	int i;
	int count;

	head = init_link();
	for(i=0;i<20;i++){
		n = (pNode)malloc(sizeof(Node));
		n->data = 'a'+i;
		add_node(head,n);
	}
		
	n = (pNode)malloc(sizeof(Node));
	n->data = 'z';
	add_node(head,n);
	printf("node count = %d\n",link_count(head));
	n = (pNode)malloc(sizeof(Node));
	n->data = 'z';
	insert_node(head,n,10);
	
	count = link_count(head);
	printf("there are %d nodes.\n",count);
	p = head;
	for(i=0;i<=count;i++){
		printf("node %d data = %c.\n",i,p->data);
		p = p->next;
	}
	
	free_link(head);
	return 0;
}
