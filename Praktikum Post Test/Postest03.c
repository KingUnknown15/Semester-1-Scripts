#include <stdio.h>
int main(){
	int x;
	printf("Masukan Angka [1..100]:");
	scanf("%d",&x);
	
	if(x%2==0 && x<=100){
		printf("Angka yang anda Masukan adalah Genap dan Kelipatan 2");
	}
	else if(x%3==0 && x<=100){
		printf("Angka yang anda Masukan adalah Ganjil dan Kelipatan 3");
	}
	else if(x>100){
		printf("Angka yang anda Masukan melebihi 100");
	}
	else{
		printf("Angka yang anda Masukan bukan yang dimaksud diatas");
	}
return 0;
}



