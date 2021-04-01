#include <stdio.h>
int fun3 (int x, int y){
	if (x>y){
		return -1;
	} else if (x==y){
		return 1;
	} else {
		return (x* fun3 (x+1,y));
	}
}

int Fun3 (int x, int y){
	int z;
	if (x>y){
		printf("%d>%d:\treturn -1\n",x,y);
		return -1;
	} else if (x==y){
		printf("%d==%d:\treturn 1\n",x,y);
		return 1;
	} else {
		z=x*Fun3(x+1,y);
		printf("%d\t=%d*Fun3(%d+1,%d)\n",z,x,x,y);
//		printf("return %d\n",z);
		return z;
	}
}
void barrier(){
	printf("XXXXXXXXXXXXXXXXXXXXXXXXXX\n");
}
void printingTable(){
	int x,y,limit=10;
	for(x=0;x<limit;x++){
		for(y=0;y<limit;y++){
			printf("%d\t",fun3(x,y));
		}
		printf("\n");
	}
}
int main (){
	printf("a) fun3\t(7,9)=%d\n",Fun3(7,9));barrier();
	printf("b) Fun3\t(5,3)=%d\n",Fun3(5,3));barrier();
	printf("c) Fun3\t(4,7)=%d\n",Fun3(4,7));barrier();
	printf("d) Fun3\t(6,6)=%d\n",Fun3(6,6));
	
//	printingTable();

}
