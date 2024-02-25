
#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	struct Node * next ;
	int data ;
	int wt;
}Node ;

typedef struct Graph {
	Node ** list ;
	int ** mat ; 
	int size;

}Graph;

typedef struct Queue {
	int * arr;
	int front ; 
	int rear ; 
}Queue;

void enqueue(Queue * q, int data){
	q->arr[q->rear++]= data ;
}

int dequeue( Queue *q ){
	return q->arr[q->front++];
}

int is_not_empty(Queue *q){
	return ( q->front!=q->rear );
}

Graph * create_Graph ( int size  ){
	Graph * g = (Graph *)malloc(sizeof(Graph));
	g->size= size;
	g->list = (Node **)calloc(size, sizeof(Node*));
	g->mat = (int **)calloc(size, sizeof(int *));

	for (int i=0 ; i<size ; i++)
		g->mat[i]=(int*)calloc(size,sizeof(int));

	return g;
}

void add_edge( Graph *g , int src , int des , int wt){
	g->mat [src][des]=wt;
	Node * head = (Node * ) malloc (sizeof (Node )) ; 
	head ->data = des  ; 
	head ->next = g->list[src];
	g->list[src]=head;
}


void bfs (Graph * g){
	int *visited = (int *)calloc(g->size , sizeof(int));
	Queue * q = (Queue*)malloc(sizeof(Queue));
	q->arr = (int *)calloc(g->size , sizeof(int));
	q->front =-1;
	q->rear = -1;

	for (int i =g->size-1 ; i>=0; i--)
	{
		if (!visited[i]){
			visited[i]=1;
			enqueue(q,i);

			while (is_not_empty(q)){
				int src = dequeue(q);
				printf("%d",src);

				int * nodes = g->mat[src];
				for (int i=0 ; i < g->size ; i++){
					if (nodes[i] && !visited[i]){
						visited[i]=1;
						enqueue(q,i);
					}
				}
			}
		}
	}
}

int main(){
	Graph *g = create_Graph(6);
	add_edge(g,3,1,1);
	add_edge(g,5,1,1);
	add_edge(g,4,0,1);
	add_edge(g,4,2,1);
	add_edge(g,2,3,1);
	add_edge(g,5,0,1);
	bfs(g);


}