#include <stdio.h>
#include<stdlib.h>

void display (int * arr , int n){
	for (int i=0; i<n ; i++){
		printf("%d ",arr[i]);

	}
	printf("\n");
}
int * seive(int n){
	n++;
	int arr[n];
	for (int i=0; i<n ; i++)
		arr[i]=i;
	display(arr,n);
	int count=1;
	
	for (int i=2 ; i<n ; i++)
	{
		if (arr[i]==0)continue;
		count++;
		for (int j=i ; i*j<n ; j++){
			arr[i*j]=0;
		}
	}
	display(arr,n);

	int *lis = (int *)calloc(count, sizeof(int));
	int j=1;
	for (int i=0 ; i<count ; i++){
		lis[i]=arr[j++];
		for (; arr[j]==0;j++);
	}
	display(lis,count);
	return lis;
}

int GCD ( int m , int n ){
	int * prime = seive(m);
	int size = sizeof(prime)/sizeof(prime[0]);
	int factors[size];
	int j=1;
	factors[0]=1;
	int gcd=1;
	for (int i=1; i < n ; i++){
		while (!(m%prime[i]) && !(n%prime[i])){

			m/=prime[i];
			n/=prime[i];
			factors[j++]=prime[i];
			gcd*=prime[i];
		}
	}
	display(factors,j);
	return gcd;

}

int main ()
{
	printf("%d",GCD(12,36));


}
