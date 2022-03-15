#include<stdio.h>

int main(){
	int first=40,second=60,*f,*s;
	f=&first;
	s=&second;
	
	printf("First Value= %d\n",first);
	printf("Second Value= %d\n",second);
	printf("\nAlamat Variable First Value = %x\n",&first);
	printf("Alamat Variable First Value = %x\n",&second);
	
	first=60;
	second=40;	

	
	printf("\nFirst Value= %d\n",*f);
	printf("Second Value= %d\n",*s);
	printf("\nAlamat Variable First Value = %x\n",f);
	printf("Alamat Variable First Value = %x\n",s);
	
	
return 0;
}
