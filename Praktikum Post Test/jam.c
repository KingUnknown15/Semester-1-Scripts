#include<stdio.h>
int main()
{
	int sec, jam, menit, detik;
	printf("masukan detik:");
	scanf("%d",&sec);

	jam = (sec/3600);
	menit = (sec - (3600*jam))/60;
	detik = (sec - (3600*jam)- (60*menit));
	
	printf("jam: %d\n", jam);
	printf("menit: %d\n", menit);
	printf("detik: %d\n", detik);
	
	return 0;



}
