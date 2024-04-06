#include<stdio.h>
#include<stdlib.h>

void heapify(int h[], int n){
    int i, j, k, v;
    for (i=n/2;i >= 0;i--){
        k = i;v=h[k];

        while(2*k <= n){
            j = 2*k;
            // if (j<n){
            if(h[j] < h[j+1])
                j = j+1;
            // }
            if (v > h[j])
                break;
            else{
                h[k] = h[j];
                k = j;
            }
            h[k] = v;
        }
    }
    return;
}



int main(){
    // int s;
    int a[] = {5,3,1,6,7,8};
    int n = sizeof(a)/sizeof(a[0]);

    heapify(a,n);

    for(int i=0;i<n;i++)
        printf("%d ", a[i]);


}