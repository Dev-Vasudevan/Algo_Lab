#include<stdio.h>
#include<stdlib.h> 


typedef struct Node {
	struct Node *next ; 
	int data ;
	int des ; 
	int wt;

}Node;
typedef struct Stack {
	struct Node * top;
	int size ;
}Stack;

void display ( Node * head ){
	while (head){
		printf ("%d",head->data);
		head=head->next;
	}

}
typedef struct Graph {
	Node ** list; 
	int ** mat ; 
	int size;
}Graph; 

void push (Stack * st , int data){
	Node * head = (Node *)malloc(sizeof(Node));
	head->data = data;
	head ->next = st->top ;
	st->top = head ; 
	st->size++;

}
int pop (Stack * st){
	int item = st->top->data ; 
	Node * head = st->top ; 
	st->top = st->top -> next ; 
	free (head);
	st->size--;
	return item ;
}

Graph * create_Graph( int size){
	Graph * g = (Graph *)malloc(sizeof(Graph));
	g->list =  (Node **)calloc(size , sizeof(Node));
	g->mat = (int **)calloc(size,sizeof(int*));
	for (int i=0 ; i < size ; i++)
		g->mat[i] = (int*)calloc(size,sizeof(int));
	g->size = size;
	return g;
}
void add_edge(Graph *g, int src , int des , int wt ){
	g->mat[src][des]=wt;
	Node * head = (Node *)malloc(sizeof(Node));
	head->data = des ; 
	head->wt = wt;
	head->next = g->list[src];
	g->list[src]=head;
}
void dfs ( Graph * g ){
	Stack * st = (Stack *)malloc (sizeof(Stack));
	st->top = NULL;
	st->size=0;
	int *visited = (int *)calloc(g->size, sizeof(int));
	int  push_order [g->size]; 
	int  pop_order[g->size] ; 
	int push_i=0;
	int pop_i = 0; 
	for (int i = 0 ; i< g->size ; i++){
		if (!visited[i]){
			printf("Pushed %d \n",i);
			push(st,i);
			push_order[push_i++]=i;
			while (st->top){
				Node * nodes = g->list[st->top->data];
				int flag =1;
				// this is giving the adj list of item at TOS
				while (nodes ){
					if ( !visited [nodes->data]){
						printf("Pushed %d \n",nodes->data);
						push(st,nodes->data);
						push_order[push_i++]=nodes->data ; 
						visited[nodes->data]=1;
						flag=0;
						break;
					}
					nodes=nodes->next;

				}
				if (flag){
					
					pop_order[pop_i++]=pop(st);
				}




			}
		}
	}
	for (int i=0 ; i<g->size ; i++)
		printf("%d ",push_order[i]);

	printf("\n");
	for (int i=0 ; i<g->size ; i++)
		printf("%d ",pop_order[i]);
}

int main (){
	Graph *g = create_Graph(6);

	add_edge(g,0,1,1);
	add_edge(g,0,2,1);
	add_edge(g,1,3,1);
	add_edge(g,2,4,1);
	add_edge(g,3,5,1);
	add_edge(g,4,5,1);
	dfs(g);

}
