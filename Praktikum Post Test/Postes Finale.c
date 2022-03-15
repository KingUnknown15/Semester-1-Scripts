#include<stdio.h>
int increase=0;
struct teman{
	char *nama[20];
	char *tngl[20];
	char *bulan[20];
	char *hobi[20];
	int tahun;
};
struct teman teman[100];
void table(struct teman teman[100]);

void garis(y){
	int x;
	for(x=1;x<=y;x++){
		printf("-");
	}
}
int main(){
	struct teman teman[100];
	int x=1,y;
	char yesno[10]="ynYN";
	char tambah[10]="tnTN";
	printf(" ****** ISI DATA TEMAN ******\n");
	printf("\n");
	yeet:
	for(y=x;y<=x;y++){
		printf("Teman %d:\n",y);
		printf("Name\t:");
		scanf(" %[^\n]",&teman[y].nama);
		printf("Tanggal Lahir\t:");
		scanf(" %s",&teman[y].tngl);
		printf("Bulan Lahir\t:");
		scanf(" %[^\n]",&teman[y].bulan);
		printf("Tahun Lahir\t:");
		scanf("%d",&teman[y].tahun);
		printf("Hobi\t:");
		scanf(" %[^\n]",&teman[y].hobi);
	}
	printf("Data yang dimasukan benar? [y/n]:");
	scanf("%s",&yesno);
	
	if(strncmp(yesno,"y")){
			system("cls");
			goto yeet;
		}
		else if(strncmp(yesno,"n")){
			goto shrek;
		}
	shrek:
		system("cls");
		printf("Data Sahabat yang Lain[t/n]: ");
		scanf("%s",&tambah);
			if(strncmp(tambah,"t")){
				goto tab;
			}
			else if(strncmp(tambah,"n")){
				x++;
				goto yeet;
			}
	tab:
		system("cls");
		garis(56);
		printf("\n|NO | NAME         |    TANGGAL LAHIR         |  HOBI  |\n");
		garis(56);
	
		for(y=1;y<=x;y++){
			printf("\n|%d  | %s  |    %s %s %d   |  %s   |\n", y, teman[y].nama, teman[y].tngl, teman[y].bulan, teman[y].tahun,teman[y].hobi);
					garis(56);
		}
return 0;
}









