#include<stdio.h>
#include <stdlib.h>
#include<time.h>

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
	int absen,sks;
	float tugas1,tugas2,uts,uas,nakhir,rata2t,ip;
	char nama[30],matkul[30],yesno[5],tgsl[5],nim[20],grade;

	printf("Masukan NIM:");
	scanf(" %[^\n]",nim);
	printf("Masukan Nama:");
	scanf(" %[^\n]",nama);
	printf("\n");
abs:	
	garis(20);
	printf("\n");
	printf("Masukan Mata Kuliah:");
	scanf(" %[^\n]",matkul);	
	printf("Masukan SKS:");
	scanf("%d",&sks);
	printf("Masukan Absen:");
	scanf("%d",&absen);
		if(absen<=11){
			printf("\nnilai absen yang dimasukan tidak memenuhi kriteria\n");
			printf("Nilai Tugas dan Ujian akan diberi 0\n\n");
			printf("Data yang dimasukan benar?[y/n] :");
			scanf("%s",&yesno);
				if(strncmp(yesno,"y")){
					goto abs;
				}
				else if(strncmp(yesno,"n")){
					uas=0;
					uts=0;
					nakhir=0;
					tugas1=0;
					ip=0;
						FILE *bio=fopen("biodata.txt","a");
						FILE *tab=fopen("table.txt","a");
						fprintf(bio,"%s;%s;%s;%d;%f;%f;%f;%f;%d;E\n",&nim, &nama, &matkul,absen,rata2t,uts, uas, nakhir,sks);
						fprintf(tab,"%s;%s;%s;%d;%f;%f;E\n",&nim, &nama, &matkul,sks,nakhir,ip);
						fclose(bio);
						fclose(tab);
					printf("Tekan tombol APAPUN untuk Kembali Ke Menu");
					getch();
					system("cls");
					main();	
				}
	
		}
		else if(12<=absen || absen<=14){
			printf("Masukan Nilai Tugas: ");
			scanf("%f",&tugas1);
			printf("\nTekan Enter Jika Ada Tugas Tambahan [Tekan X bila tidak ada]");
			getch();
			if(getch() == 'x' || getch() == 'X'){
				tugas2 = 0;
				rata2t=tugas1;
				goto cont;
				printf("\n");
			}
			else {
				printf("\nMasukan Nilai Tugas 2:");
				scanf(" %f", &tugas2);
				rata2t=(tugas1+tugas2)/2;
				goto cont;
			}
		cont:
			printf("\nMasukan Nilai UTS:");
			scanf("%f",&uts);
			printf("Masukan Nilai UAS:");
			scanf("%f",&uas);
			printf("Data yang dimasukan benar?[y/n] :");
			scanf("%s",&yesno);
				if(strncmp(yesno,"y")){
					goto abs;
				}
				else if(strncmp(yesno,"n")){
						FILE *bio=fopen("biodata.txt","a");
						FILE *tab=fopen("table.txt","a");
						FILE *nam=fopen("namenim.txt","a");

						nakhir=(((0.3)*uas)+((0.4)*uas)+((0.2)*rata2t)+((0.1)*absen));
						nakhir=(((0.3)*uas)+((0.4)*uas)+((0.2)*rata2t)+((0.1)*absen));
						fprintf(bio,"%s;%s;%s;%d;%f;%f;%f;%f;%d;",&nim, &nama, &matkul,absen,rata2t,uts, uas, nakhir,sks);
						fprintf(tab,"%s;%s;%s;%d;%f;",&nim, &nama, &matkul,sks,nakhir);
						fprintf(nam,"%s;%s\n",&nim, &nama);
						if(90<=nakhir || 100<=nakhir)
					    {
					    	 ip=4*sks;
					    	 fprintf(tab,"%f;",ip);
					         fprintf(bio,"A\n");
					         fprintf(tab,"A\n");
					    }
					    else if(79<=nakhir || 89<=nakhir)
					    {
					    	 ip=3*sks;
					    	 fprintf(tab,"%f;",ip);
					         fprintf(bio,"B\n");
					         fprintf(tab,"B\n");
					    }
					    else if(69<=nakhir || 78<=nakhir)
					    {
					    	 ip=2*sks;
					    	 fprintf(tab,"%f;",ip);
					         fprintf(bio,"C\n");
					         fprintf(tab,"C\n");
					    }
					    else if(59<=nakhir || 68<=nakhir)
					    {
					    	 ip=1*sks;
					    	 fprintf(tab,"%f;",ip);
					         fprintf(bio,"D\n");
					         fprintf(tab,"D\n");
					    }
					    else if(0<=nakhir || 58<=nakhir)
					    {
					    	ip=0*sks;
					    	fprintf(tab,"%f;",ip);
					      	fprintf(bio,"E\n");
					        fprintf(tab,"E\n");
					    }

						fclose(bio);
						fclose(tab);
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
					goto abs;
				}	
	
}
void table(){
	char nama[30],matkul[30],huruf[5],yesno[5],tgsl[5],grade[10],nim[20];
	int absen,sks,tsks;
	float tugas1,tugas2,uts,uas,nakhir,rata2t,ip,tip,ipk;
	time_t t = time(NULL);
    struct tm *tm = localtime(&t);
	
	FILE *tab=fopen("table.txt","r");
	FILE *nam=fopen("namenim.txt","r");
	fscanf(nam,"%[^;];%[^\n]\n",nim,nama);
	samdeg(103);
	printf("\n\t\t\tSTUDENT DATA\n\t\t\t\n");
	samdeg(103);
	printf("\n|\tNIM\t |\tName\t\t\t|\tMatkul\t\t|\tSKS|\tAkhir|\tHuruf|\n");
	samdeg(103);
	while(!feof(tab)){
		fscanf(tab,"%[^;];%[^;];%[^;];%d;%f;%f;%[^\n]\n",nim, nama, matkul,&sks,&nakhir,&ip,grade);
		printf("\n|%15s | %15s\t\t| %15s\t| \t%d  | \t%.1f | \t%s    |\n",nim, nama,matkul,sks,nakhir,grade);	
		garis(103);
		tsks=sks+tsks;
		tip=ip+tip;
	}
	ipk=tip/tsks;
	printf("\nIP: %.1f",ipk);
	fclose(tab);
	printf("\nData ini Dicetak: %s",asctime(tm));
printf("\nPress ANY key ");
getch();
system("cls");
main();
}
void detil(){
	char nama[30],matkul[30],huruf[5],yesno[5],tgsl[5],grade[10],nim[20],nim2[20];
	int absen,sks;
	float tugas1,tugas2,uts,uas,nakhir,rata2t; 
		time_t t = time(NULL);
    struct tm *tm = localtime(&t);
	FILE *bio=fopen("biodata.txt","r");
	samdeg(20);
	printf("\nCari Data Mahasiswa\n");
	samdeg(20);
	printf("\nMasukan NIM: ");
	scanf(" %[^\n]",nim2);
while(!feof(bio))
   {
     ret:
     	
	  fscanf(bio,"%[^;];%[^;];%[^;];%d;%f;%f;%f;%f;%d;%[^\n]\n",nim, nama, matkul,&absen,&rata2t,&uts, &uas, &nakhir,&sks,grade);
      if(strncmp(nim,nim2)==0)
      {
         printf("Berhasil Ditemukan\n");
         printf("NIM: %s\n",&nim);
         samdeg(103);
		 printf("\n\t\t\t\t\tSTUDENT DATA\n\t\t\t\t\t  [%s\t%s]\n",nama,nim);
		 samdeg(103);
		 printf("\n|\tNIM\t |\tName\t\t\t|\tMatkul\t\t|SKS|Absen| Tugas| UTS  | UAS |\n");
		 samdeg(103);
         printf("\n| %15s| %15s\t\t| %15s\t| %d | %d  | %.1f | %.1f| %.1f|\n",nim2, nama,matkul,sks,absen,rata2t,uts,uas);
         garis(103);
         printf("\nData ini Dicetak: %s",asctime(tm));
         printf("\nTekan APAPUN Untuk Ke Menu");
	  	 getch();
	  	 system("cls");
	  	 main();
      }
      else if(strncmp(nim,nim2)==1 && !feof(bio)){
	  	goto ret;
	  }
	  else if(strncmp(nim,nim2)==1 && feof(bio)){
	  	printf("Data Tidak Ditemukan");
	  	printf("\nTekan KEY Apapun Untuk Kembali Ke Menu");
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
			printf("Tolong Pilih Dari 1-4");
			printf("\nTekan KEY Apapun Untuk Kembali Ke Menu");
			getch();
			system("cls");
			main();
			break;
	}
return 0;
}
