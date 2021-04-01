#include <stdio.h>

void 	recursiveCounter	(int n){
    if (n > 0){
        recursiveCounter(n-1); 	  
		printf("%d ", n);
	} else {
		printf("%d ", n);
	}
}
int		filterInput			(){
	int num;
	do{
		printf("\nType a positive Integer:\t");
		scanf("%d", &num);
	} while (num<0);
	return num;
}

int main(){
    int n=filterInput ();
    recursiveCounter  (n);
}



