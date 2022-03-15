#include<stdio.h>
#include<stdlib.h>

void menu(){
	printf("--------------------\n");
	printf("	MENU\n");
	printf("--------------------\n");
	printf("1.Biodata\n2.Hitung\n3.Deret\n4.Keluar\n");

}
int hitung(int x){
	int alas,tinggi;
	char yesno[10]="ynYN";
	printf("--------------------\n");
	printf("Masukan Alas: ");
	scanf("%d",&alas);
	printf("Masukan Tinggi: ");
	scanf("%d",&tinggi);
	printf("--------------------\n");
	x=alas*tinggi/2;
	printf("Luas Segitiga Adalah: %d",x);

	printf("\nHitung selesai\nUlangi Hitung[y/n]:");
	scanf("%s",&yesno);
		if(strncmp(yesno,"y")){
			system("cls");
			main();
		}
		else if(strncmp(yesno,"n")){
			system("cls");
			hitung(x);
		}

return x;
}
int deret(int x){
	int i=1,j,suku,hasil=0;
	char yesno[10]="ynYN";
	printf("--------------------\n");
	printf("Masukan Suku Ke[0..1000]:\n ");
	scanf("%d",&suku);
	for(x=1;x<=suku;x++){
		hasil= hasil+i;
		printf("%d",i);
		i=i+2;		
		if(x<suku){
			printf("+");
		}
	}
	printf("=%d\n",hasil);
	printf("--------------------\n");
	printf("Deret selesai\nUlangi Deret[y/n]:");
	scanf("%s",&yesno);
		if(strncmp(yesno,"y")){
			system("cls");
			main();
		}
		else if(strncmp(yesno,"n")){
			system("cls");
			deret(x);
		}

return x;
}
void biodata(){
	char yesno[10]="ynYN";
	
	printf("--------------------\n");
	printf("    BIODATA\n");
	printf("--------------------\n");
	printf("NIM: 1910511071\n");
	printf("Nama: Adika Rajendra Haris\n");
	printf("Kelas: C\n");
	printf("Semester: 1\n");
	printf("--------------------\n");
	printf("Cetak biodata selesai\nUlangi Cetak[y/n]:");
	scanf("%s",&yesno);
		if(strncmp(yesno,"y")){
			system("cls");
			main();
		}
		else if(strncmp(yesno,"n")){
			system("cls");
			biodata();
		}
}
int main(){
	int pil,luas,hasil;
	menu();
	
	printf("--------------------\n");
	printf("Pilihan Anda [1..4]:");
	scanf("%d",&pil);
	
	switch(pil){
		case 1:
			system("cls");
			biodata();
			break;
		case 2:
			system("cls");
			hitung(luas);
			break;
		case 3:
			system("cls");
			deret(hasil);
			break;
		case 4:
			system("cls");
			break;
		default:
			system("cls");
			printf("--------------------\n");
			printf("Angka Yang Anda Masukan TIDAK Ada Pilihanya\n");
			printf("--------------------\n");
			main();
	}
return 0;
}
