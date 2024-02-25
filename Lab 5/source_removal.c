#include<stdio.h> 
#include<stdlib.h> 

typedef struct Node {
	struct Node* next ; 
	int data;
}Node ; 

typedef struct Graph {
	Node **list ; 
	int ** mat ;
	int size;
}Graph;

Graph * create_Graph (int size){
	Graph * g = (Graph *)malloc (sizeof(Graph));
	g->size = size; 
	g->list = (Node **)calloc(size, sizeof(Node *));
	g->mat = (int **)calloc (size,sizeof(int*));
	for (int i =0 ; i<size ; i++)
		g->mat[i]=(int * )calloc (size,sizeof(int));

	return g;
}
void add_edge(Graph * g , int src , int des , int wt ){
	g->mat[src][des]=wt;
	Node * head = (Node *)malloc (sizeof(Node));
	head ->data = des ;
	head->next = g->list[src];
	g->list[src]=head;
}
int * in_degree ( Graph *g ){
	int *in_deg = (int *)calloc (g->size , sizeof(int));

	for (int i =0 ; i<g->size ; i++){
		
		for (int j=0 ; j< g->size ; j++){
			if (g->mat[j][i])
				in_deg[i]++;
		}

	}
	return in_deg;
}
void display(int *arr , int size){
	for (int i=0; i<size ; i++)
		printf("%d",arr[i]);
	printf("\n");
}
int pri_dequeue(int * in_deg , int * visited , int size){
	// display(in_deg,size);
	for (int i=0 ; i < size ; i++){
		if (!in_deg[i] && !visited[i]){
			return i;
		}
	}
	return -1;
}

void topsort ( Graph *g){
	int * in_deg = in_degree(g);
	int * visited = (int *)calloc (g->size , sizeof(int));
	while(1){

		int node = pri_dequeue(in_deg,visited,6);
		
		if (node==-1 )break;
		visited[node]=1;
		printf("%d ",node);

		for (int i=0 ; i<g->size ; i++)
			if (g->mat[node][i])
				in_deg[i]--;
		

	}
}

int main (){
	Graph * g = create_Graph(6);

	add_edge(g,3,1,1);
	add_edge(g,4,1,1);
	add_edge(g,5,0,1);
	add_edge(g,5,2,1);
	add_edge(g,2,3,1);
	add_edge(g,4,0,1);
	topsort(g);
}
