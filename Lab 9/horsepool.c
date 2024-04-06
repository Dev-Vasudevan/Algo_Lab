#include<stdio.h>
#include<stdlib.h> 
#include<string.h>

// banana
// 52121
int opcount = 0 ;

int horsepool(char * String , char * pattern ){
	int len = strlen (pattern);
	int table[26];

	for (int i =0 ; i<26 ; i++)
		table[i]=len;

	for (int i=len-1 ; i>0 ; i--)
		table[(int)(pattern[len-1-i]-'a')]=i;

	int j=len-1 ; 

	while (j<strlen(String)){
		int i;
		int temp = j ;
		for ( i=len-1 ; i>=0 ; i--){
			opcount++;
			if (String[temp--]!=pattern[i]){
				j+= table[String[j]-'a'];
				break;
			}
		}
		if (i==-1)
			return j+1-len;
	}
	return -1;
	
	
	
	// return 0;

}
int main () {
	printf("%d \n",horsepool("bananalandloll","nanal"));
	printf("%d"opcount);
}


// ana
// 21