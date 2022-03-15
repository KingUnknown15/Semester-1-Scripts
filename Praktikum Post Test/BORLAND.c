#include<stdio.h>

int main(){
	int x,y=6;
	char *nama[]={"B","O","R","L","A","N","D"};
	
	for(x=0;x<=6;x++){
		for(y=6-x;y<=6;y++){
			printf("%s",nama[y]);
		}
		printf("\n");
	}
return 0;
}





