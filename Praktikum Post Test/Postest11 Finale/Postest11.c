#include<stdio.h>
#include <stdlib.h>

void garis(y){
int x;
	for(x=1;x<=y;x++){
		printf("-");
	}
}
void samdeg(y){
int x;
	for(x=1;x<=y;x++){
		printf("=");
	}
}
void menu(){
	samdeg(21);
	printf("\n\tMENU\n");
	samdeg(21);
	printf("\n1. Input Biodata\n");
	printf("\n2. Lihat Nilai\n");
	printf("\n3. Detil Nilai\n");
	printf("\n4. Exit\n");
	garis(21);
}
void bio(){
	float uts,uas,tugas1,tugas2,rata2t,nakhir;
	char nama[50],nim[20],yesno[10];
jim:
	printf("Masukan NIM:");
	scanf(" %[^\n]",nim);
	printf("Masukan Nama:");
	scanf(" %[^\n]",nama);
	printf("\nTekan ENTER Untuk Input Nilai Tugas [Tekan X bila tidak ada]:");
	getch();
	if(getch()== 'x' || getch() == 'X'){
		tugas1 = 0;
		tugas2 = 0;
		rata2t = 0;
		goto cont;
		printf("\n");
	}
	else {
		printf("\nMasukkan Nilai Tugas 1:"); 
		scanf(" %f", &tugas1);
		printf("Ada tugas lagi? [Tekan X bila tidak ada]"); 
		getch();
			if (getch() == 'X' || getch() == 'x'){
				tugas2 = 0;
				rata2t=tugas1;
				goto cont;
			}
			else {
				printf("\nMasukkan Nilai Tugas 2:"); 
				scanf(" %f", &tugas2);
				rata2t=(tugas1+tugas2)/2;
				goto cont;
			}
	}
cont:
	printf("\n");
	printf("Masukan Nilai UTS:");
	scanf("%f",&uts);
	printf("Masukan Nilai UAS:");
	scanf("%f",&uas);
	printf("Data yang dimasukan benar?[y/n] :");
	scanf("%s",&yesno);	
	if(strncmp(yesno,"y")){
		goto jim;
	}
	else if(strncmp(yesno,"n")){
		FILE *bio=fopen("biodata.txt","a");
		nakhir = ((rata2t*0.25) + (uts*0.25) + (uas*0.5));
		fprintf(bio,"%s;%s;%f;%f;%f;%f;",&nim, &nama,rata2t,uts, uas, nakhir);
		if(90<=nakhir || 100<=nakhir)
		{
        	fprintf(bio,"A\n");
		}
		else if(79<=nakhir || 89<=nakhir)
		{
			fprintf(bio,"B\n");
		}
		else if(69<=nakhir || 78<=nakhir)
		{
			fprintf(bio,"C\n");
		}
		else if(59<=nakhir || 68<=nakhir)
		{
			fprintf(bio,"D\n");
		}
		else if(0<=nakhir || 58<=nakhir)
		{
			fprintf(bio,"E\n");
		}
	}
		printf("Ada Data Lagi[y/n]: ");
		scanf("%s",&yesno);
			if(strncmp(yesno,"y")){
				printf("Tekan tombol APAPUN untuk Kembali Ke Menu");
				getch();
				system("cls");
				main();	
			}
			else if(strncmp(yesno,"n")){
				goto jim;
			}
}
void table(){
	float uts,uas,tugas1,tugas2,rata2t,nakhir;
	char nama[50],nim[20],yesno[10],grade[10];
	FILE *bio=fopen("biodata.txt","r");
	printf("                  		TABEL BIODATA          \n");
	printf("---------------+--------------------+---------------+---------------+---------------+---------------+---------------+\n");
	printf("     NIM       |        NAMA        |      RATA     |       UTS     |      UAS      |      AKHIR    |      HURUF    |\n");
	printf("---------------+--------------------+---------------+---------------+---------------+---------------+---------------+\n");
	
	while(!feof(bio)){
		fscanf(bio,"%[^;];%[^;];%f;%f;%f;%f;%[^\n]\n",nim, nama,&rata2t,&uts, &uas, &nakhir,grade);
			printf("|%12s  | %10s         |\t%.0f          |\t%.1f\t    |  \t%.1f\t    | \t%.1f\t    |\t%s\t    |\n",nim,nama,rata2t,uts,uas,nakhir,grade);
	}
}
void detil(){
	float uts,uas,tugas1,tugas2,rata2t,nakhir;
	char nama[50],nim[20],yesno[10],grade[10],nim2[20];
	FILE *bio=fopen("biodata.txt","r");
	
	samdeg(20);
	printf("\nCari Data Mahasiswa\n");
	samdeg(20);
	printf("\nMasukan NIM: ");
	scanf(" %[^\n]",nim2);
	
	while(!feof(bio)){
		ret:
			fscanf(bio,"%[^;];%[^;];%f;%f;%f;%f;%[^\n]\n",nim, nama,&rata2t,&uts, &uas, &nakhir,grade);	
		if(strncmp(nim,nim2)==0){
			printf("                  		TABEL BIODATA          \n");
			printf("---------------+--------------------+---------------+---------------+---------------+---------------+---------------+\n");
			printf("     NIM       |        NAMA        |      RATA     |       UTS     |      UAS      |      AKHIR    |      HURUF    |\n");
			printf("---------------+--------------------+---------------+---------------+---------------+---------------+---------------+\n");
			printf("|%12s  | %10s         |\t%.0f          |\t%.1f\t    |  \t%.1f\t    | \t%.1f\t    |\t%s\t    |\n",nim,nama,rata2t,uts,uas,nakhir,grade);
			printf("Tekan APAPUN Untuk ke Menu");
			getch();
			system("cls");
			main();
		}
		else if(strncmp(nim,nim2)==1 && !feof(bio)){
	  	goto ret;
	  	}
	  	else{
	  	printf("Tidak Ada");
	  	getch();
	  	system("cls");
	  	main();
	  	}
	}
}
int main(){
	int pilihan;
	menu();
	printf("\nMasukan Pilihan[1-4]: ");
	scanf("%d",&pilihan);
	switch(pilihan){
		case 1:
			bio();
			break;
		case 2:
			table();
			break;
		case 3:
			detil();
			break;
		case 4:
			system("cls");
			break;
		default:
			printf("Pilihan Tidak Ada\nTolong PILIH dari 1-4");
			getch();
			system("cls");
			main();
	}
return 0;
}

