#include <stdio.h>
int main()
{
	int x;
	printf("Masukkan Angka [1..100]:");
	scanf("%d",&x);
	
	if(x%2==0){
		if(x>100){
			printf("Angka yang anda masukan diatas 100");
		}
		printf("Angka yang Anda Masukan adalah Genap dan Kelipatan 2");
	}
	
	else if(x%2==1){
		if(x%3==0){
			printf("Angka yang Anda Masukan adalah Genap dan Kelipatan 3");
		}
		if(x%3==1){
			printf("Angka yang Anda Masukan adalah Ganjil");
		}
	}

return 0;
}
