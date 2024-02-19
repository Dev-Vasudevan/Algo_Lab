// Using quicksort to sort an array on integers which are hardcoded 

#include <stdio.h>
#include<stdlib.h>

// for quicksort we take the 0th element as the pivot and subdivide the array 
// into one with all elemets left of a new pivot less that original pivot and right 
// having elemets larger than pivot 
// Then recursively call it 


void display ( int *arr , int n){
	for (int i=0; i < n ; i++)
		printf("%d ",arr[i]);
	printf("\n");
}

void quicksort(int * arr, int n  ){
	if (n<=1 )return ;
	int pivot = arr[0];
	int i=1;
	int j=n-1;

	while (j>i){
		display(arr,n);
		for (;arr[i]<pivot && i < n ;i++);
		for (; arr[j]> pivot ; j--);
		if (j<=i)break;
		int temp = arr[i];
		arr[i]=arr[j];
		arr[j]=temp;
	}
	arr[0]=arr[j];
	arr[j]=pivot;
	quicksort( arr ,j );
	quicksort(arr+j+1, n-1-j);

}

int main (){
	int a[]={5,3,1,9,8,2,4,7};
	int n = sizeof(a)/sizeof(int);
	quicksort(a,n);

	display(a,n);
}
