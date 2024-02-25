#include<stdio.h> 
#include<stdlib.h>

typedef struct Node {
	struct Node * next ; 
	int data ;
	int wt;
}Node;

typedef struct Graph {
	int ** mat ; 
	Node ** list;
	int size;
}Graph;

Graph * create_Graph(int size){
	Graph * g = (Graph *)malloc(sizeof(Graph));
	g->size = size; 
	g->mat = (int **)calloc(size, sizeof(int*));
	for (int i =0 ; i < size ; i++)
		g->mat[i] = (int *)calloc(size,sizeof(int));

	g->list = (Node **)calloc(size,sizeof(Node*));

	return g;
}

void add_edge(Graph *g , int src , int des, int wt){
	g->mat[src][des]=wt;
	Node * head = (Node *)malloc(sizeof(Node));
	head->data = des ; 
	head->wt=wt;
	head->next = g->list[src];
	g->list[src]=head;
}
void display (int * arr){
	for (int i=0 ; i < 6 ; i++)
		printf("%d  ",arr[i]);
	printf("\n");
}

void traverse ( Graph *g , int node , int * visited){
	int* nodes=  g->mat[node];
	if (visited[node])return ; 
	visited[node]=1;
	printf(" %d   ",node);
	

	for (int i=0; i<g->size ; i++)
	{
		
		if (nodes[i] && !visited[i]){
			
			traverse(g,i,visited);
		}
	}
}
void dfs( Graph * g ){
	int  visited []= {0,0,0,0,0,0};

	int size = g->size;
	for (int i=0 ; i < size ; i++){
		if (!visited[i])
			
			traverse(g,i,visited);
	}
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
