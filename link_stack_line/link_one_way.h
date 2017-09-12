
#ifndef LINK_ONE_WAY_H
#define LINK_ONE_WAY_H
typedef char ElemType;

typedef struct Node{
	ElemType data;
	struct Node *next;
}Node,*pNode;


pNode init_link();
int add_node(pNode h,pNode n);
int insert_node(pNode head,pNode n,int position);
int del_node(pNode head,int position);
int link_count(pNode head);
int free_link(pNode head);

#endif
