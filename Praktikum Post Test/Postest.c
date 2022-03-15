#include<stdio.h>
int main()
{
	int A,ribuan,ratusan,puluhan,satuan;
	printf("Masukan Angka:");
	scanf("%d",&A);
	
	ribuan = A/1000;
	ratusan = (A - ribuan*1000)/100;
	puluhan = (A- ribuan*1000- ratusan*100)/10;
	satuan = (A- ribuan*1000- ratusan*100 - puluhan*10);
	
	printf("Ribuan = %d\n",ribuan);
	printf("Ratusan = %d\n",ratusan);
	printf("Puluhan = %d\n",puluhan);
	printf("Satuan = %d\n",satuan);
	
	return 0;
}

