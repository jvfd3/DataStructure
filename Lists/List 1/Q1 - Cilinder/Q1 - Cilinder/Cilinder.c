#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Should I put the values for volume and area inside of the struct?
// Should it be automatically calculated when both values are available?
typedef struct cilinder {
	int x, y;
	float radius, height;
}Cilinder;

/*
	float ReturnCilinderHeight (Cilinder* c){
		return c -> height;
	}
	
	float ReturnCilinderRadius (Cilinder* c){
		return c -> radius;
	}
*/

Cilinder* CreateCilinder (){
	Cilinder* c = (Cilinder*) malloc ( sizeof (Cilinder) );
	if(c != NULL){
		return c;
	}
	return NULL;
}
void	SetDataToCilinder 		(Cilinder* c, int x, int y, float h, float r){
	
	if(h<0){
		printf("You tried to insert a negative Height (%f). It can't be done. Insert a positive Height instead.\n", h);
	}
	
	if(r<0){
		printf("You tried to insert a negative Radius (%f). It can't be done. Insert a positive Radius instead.\n", r);
	}
	
	if((h>0)&&(r>0)){
		c->x=x;
		c->y=y;
		c->radius = r;
		c->height = h;
	//	scanf("%f",&(c->height));
	}
}
float	ReturnCilinderVolume	(Cilinder* c){
	return M_PI*c->radius*c->radius*c->height;
}
float	ReturnCilinderArea		(Cilinder* c){
	return 2*M_PI*c->radius*(c->radius+c->height);
}
void	ShowCilinderData		(Cilinder* c, int n){
	printf("Cilinder %d\t",			n);
	printf("(x,y)=(%d,%d)\t", 		c->x, c->y);
	printf("Height:  %.3f\t", 		c->height);
	printf("Radius:  %.3f\t", 		c->radius);
//	printf("Height:  %.3f\t", 		ReturnCilinderHeight	(c));
//	printf("Radius:  %.3f\t", 		ReturnCilinderRadius	(c));
	printf("Volume:  %.3f\t", 		ReturnCilinderVolume	(c));
	printf("Area:    %.3f\n", 		ReturnCilinderArea	(c));
}
void 	FreeCilinder			(Cilinder* c){
	free(c);
}

