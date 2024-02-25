#include<stdio.h> 
#include<stdlib.h>

void display(int * arr , int size){
	for (int i=0 ; i<size ; i++)
		printf("%d",arr[i] );
	printf("\n");
}
void bubble(int * arr, int n){
	for (int i=0 ; i< n ; i++){
		for (int j=0 ; j< n-1 ; j++){
			
			if ( arr[j] > arr[j+1])
			{
				int temp = arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}

		}
	}
}

int main (){
	int a[]={5,3,1,9,8,2,4,7};
	int n = sizeof(a)/sizeof(int);
	bubble(a,n);
	display(a,n);
	
}
