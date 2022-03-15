#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int uts[20],uas[20],nim[50],increase=0;
char nama[10][50];
void garis(y){
	int x;
	for(x=1;x<=y;x++){
		printf("-");
	}
}
void menu(){
	garis(29);
	printf("        \n        DATA ACADEMIC  \n");
	garis(29);
	printf("\n1. MAHASISWA DATA CONFIG\n");
	printf("2. MAHASISWA REPORT\n");
	printf("3. EXIT\n");	

}
void bio(){
	system("cls");
	int x, data;
	increase=0;
	printf(" ****** FIRST CHOICE ******\n");
	printf("Masukan banyak Data[1..10] : ");
	scanf("%d", &data);
	printf("\n");
	
	for(x=1;x<=data;x++){
		printf("Data %d:\n",x);
		printf("Name\t:");
		scanf(" %[^\n]",&nama[x][50]);
		printf("NIM\t:");
		scanf("%d",&nim[x]);
		printf("UAS\t:");
		scanf("%d",&uas[x]);
		printf("UTS\t:");
		scanf("%d",&uts[x]);
	}
	for(x=1;x<=data;x++){
		increase++;
	}
}
void table(){
	system("cls");
			if(increase==0){
			system("cls");
			printf("DATA UNAVAILABLE, PLEASE INPUT DATA\n");
			printf("PRESS ENTER TO GO TO MENU");
			getch();
			system("cls");
			main();
		}
	int x;
	garis(56);
	printf("\n|NO | NIM |    NAME     |  UTS  |  UAS  |    FINAL GRADE |\n");
	garis(56);
	
	for(x=1;x<=increase;x++){
		printf("\n|%d  | %d  |    %s |  %d   |  %d   | %d |", x, nim[x], &nama[x][50], uts[x], uas[x], (uts[x]+uas[x])/2);
	}
	printf("\nTO MENU, PRESS ENTER\n");
	getch();
	system("cls");
	main();
}

int main(){
	int pilihan;
	char yesno[10];
	men:
	menu();
	garis(25);
	printf("\nPilihan Anda [1..3]:");
	scanf("%d",&pilihan);
switch(pilihan){

	case 1:
		conf:
		bio();
		printf("Is The Data Correct [y/n]: ");
		scanf("%s",&yesno);
		if(strncmp(yesno,"y")){
			system("cls");
			goto conf;	
		}
		else if(strncmp(yesno,"n")){
			system("cls");
			goto men;
		}
		break;	
	case 2:
		table();
		break;	
	case 3:
		system("cls");
		break;
	default:
		system("cls");
		printf("Maaf Pilihan Anda Tidak Ada, ENTER untuk ke menu\n");
		getch();
		system("cls");
		main();

}

}
