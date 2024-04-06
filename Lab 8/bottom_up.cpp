#include <stdio.h>
#include <stdlib.h> 

void display (int * arr , int n ){
	for (int i=0 ; i<n ; i++){
		printf("%d",arr[i] );
	}
	printf("\n");
}

// one based indexing 

void heapify ( int * arr  , int ind , int size ){
	
	
	// {5,3,8,6,7,6,1}
	// printf("%d arr[%d]\n" ,arr[ind-1] , ind-1);
	display(arr,size);
	if (size < ind *2 )
		return ; 

	
	int max_ind;
	int root =arr[ind-1];
	int left = arr[ind*2 -1];
	int right =0; 
	if (size> ind*2)
		 right = arr[ind*2];
// printf("left %d root %d right %d \n ",left , root , right);

	if (left>=right && left >root ){
		max_ind = ind*2 -1 ;
		arr[ind-1]=arr[ ind*2 -1 ];
		arr[ind*2 -1]=root;
		heapify(arr, ind*2 , size );
	} 
	else if ( right > left && right > root  ){
		
		max_ind = ind*2 ; 
		arr[ind-1] = arr[ind*2];
		arr[ind*2]=root;
		heapify(arr,ind*2 +1 , size);
	}


}
void bottom_up ( int * arr , int n ){
	// int item = n/2 ; 
	for (int ind = n/2 ; ind>0 ; ind--){
		heapify(arr,ind,n);
	}
}

void heapsort(int *arr , int n ){
	int sz = n ;
	while (n){
		printf("\n");
		display(arr,sz);
		bottom_up(arr,n--);
		int temp = arr[0];
		arr[0]=arr[n];
		arr[n]=temp;
	}

}

int main () { 
	int a[] = {5,3,1,6,7,6};
	int n = sizeof(a)/sizeof(a[0]);
	// display(a,n);
	heapsort(a,n);
	// display(a,n);
}

