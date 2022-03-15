#include<stdio.h>

int first[10][10], second[10][10], multiply[10][10];
int row1=2,col1=3,row2=3,col2=2;

void garis(y){
	int x;
	for(x=1;x<=y;x++){
		printf("-");
	}
}
void header(){
	garis(40);
	printf("\n\tPERKALIAN MATRIX\n");
	garis(40);
	printf("\nInput Matrix A(2x3) dan Matrix B(3x2)");
}
void firstM(){
int c,d;
  for (c = 0; c < 2; c++)
    for (d = 0; d < 3; d++)
      scanf("%d", &first[c][d]);

}
void secondM(){
int c,d;
	for (c = 0; c < 3; c++)
      for (d = 0; d < 2; d++)
        scanf("%d", &second[c][d]);
}
void multi(){
int c,d,k,sum=0;    
	for (c = 0; c < 2; c++) {
      for (d = 0; d < 2; d++) {
        for (k = 0; k < 3; k++) {
          sum = sum + first[c][k]*second[k][d];
        }
 
        multiply[c][d] = sum;
        sum = 0;
        printf("%d ", multiply[c][d]);
      }
      printf("\n");
    }
    //for (c = 0; c < 2; c++) {
      //for (d = 0; d < 2; d++)
        //printf("%d ", multiply[c][d]);
 
      //printf("\n");
    //}
}
int main(){
	header();
	printf("\n");
	printf("MATRIX A\n");
	firstM();
	printf("MATRIX B\n");
	secondM();
	printf("MATRIX C\n");
	multi();
return 0;
}
