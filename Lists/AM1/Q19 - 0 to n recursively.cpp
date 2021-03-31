#include <stdio.h>

void fun(int n){
    if (n > 0){
        fun(n-1); 	  
		printf("%d ", n);
	} else if(n<0){
		printf("%d ", n);
		fun(n+1);
	} else {
		printf("%d ", n);
	}
}

int main(){
    int n;
    printf("Type an integer\t");
    scanf("%d", &n);
    fun (n);
    printf("\nEnd\n");
}



