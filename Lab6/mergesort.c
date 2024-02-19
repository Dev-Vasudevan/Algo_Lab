#include <stdio.h>
#include <stdlib.h>

void display ( int *arr , int n){
	for (int i=0; i < n ; i++)
		printf("%d ",arr[i]);
	printf("\n");
}


void copy (int * a , int * b, int n ){

	for ( int i =0 ; i < n ; i++)
		a[i]=b[i];

}
void merge ( int * arr , int * b , int *c , int n  ){
	int j=0,k=0;
	for  (int i=0 ; i <n ; i++){

		if (j==n/2){
			copy (arr+i,c+k,n-k-j);
			break;
		}
		if (k== (n-n/2)){
			// display (b,n/2);
			copy (arr+i,b+j,n-j-k);
			// printf("AFTER COPYIGN");
			// display(arr,n);
			break ;
		}

		if (b[j]>c[k])
			arr[i]=c[k++];
		else 
			arr[i]= b[j++];

	}
}

void mergesort (int *arr  , int n ){

	if (n==1)return ;
	// display(arr,n);
	int b[n/2], c[n-n/2];

	copy (  b ,arr , n/2);
	copy (c , arr+n/2 , n-n/2);

	mergesort(b,n/2);
	mergesort(c, n-(n/2));
	merge(arr,b,c,n);
	return;

}

int main (){
	int a[]={5,3,1,9,8,2,4,7};
	int n = sizeof(a)/sizeof(int);
	mergesort(a,n);

	display(a,n);
}
