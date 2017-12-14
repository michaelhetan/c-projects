#define MAX_TREE_SIZE 100
//孩子节点
typedef struct CTNode{
	int child;
	struct CTNode *next;
} *ChildPtr;

typedef struct 
{
	ElemType data;
	int parent; 
	ChildPtr firstchild;
}
