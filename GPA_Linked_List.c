/*Kelompok 10
 *Bintang Gegas Giani - 1906379472
 *M. Wildan Nugraha - 1906299856
 *Naufal Alfarabay - 1906379485

 *Algoritma dan Pemrograman - 01

 *Sebuah program yang mensistematiskan 
  indeks prestasi mahasiswa secara otomatis.
  Program diharapkan dapat mengkalkulasikan indeks prestasi
  dan mengkonversi menjadi indeks 4.
  
  Made in May 2022
*/

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include "gradevalue.h"
#include <stdlib.h>

#define MATKUL_MAKS 12

struct matkul {
	char nama[50];
	int sks;
	float nilai;
};

struct matkul_LINKED_LIST {
	int iterator;
	char nama[50];
	int sks;
	float nilai;
	struct matkul_LINKED_LIST *next;
};

struct matkul_LINKED_LIST * headAddressa = NULL; // langkah 3
struct matkul_LINKED_LIST * nextAddressa = NULL;
struct matkul_LINKED_LIST * iteratorPtr;
struct matkul_LINKED_LIST * TmpPtr;

void displayGradeMenu() {
	puts("\t\t(0) A\t(4.0)\n\t\t(1) A-\t(3.7)\n\t\t(2) B+\t(3.3)\n\t\t(3) B\t(3.0)\n\t\t(4) B-\t(2.7)\n\t\t(5) C+\t(2.3)\n\t\t(6) C\t(2.0)\n\t\t(7) D\t(1.0)\n\t\t(8) E\t(0.0)\n");
	return;
}

struct matkul_LINKED_LIST * new_node (char * nama, int sks, float nilai, struct matkul_LINKED_LIST * next, int iterator){
	struct matkul_LINKED_LIST * tmpAddress = malloc(sizeof(struct matkul_LINKED_LIST));
	strcpy(tmpAddress->nama, nama);
	tmpAddress->sks = sks;
	tmpAddress->nilai = nilai;
	tmpAddress->iterator = iterator;
	tmpAddress->next = next;
	return tmpAddress;
}

void getCourses(int *size){
	struct matkul c;
	int nilai;
	int credit;
	char stop = 'y';
	int i = 0;
	int result;
	char temp[50];
	iteratorPtr == headAddressa;
	while((stop == 'y') && (i < MATKUL_MAKS)){
		
		system("cls");
		printf("\n");
		puts(" 888b     d888          888    888               888 ");
		puts(" 888b     d888          888    888               888 ");
		puts(" 88888b.d88888          888    888               888 ");
		puts(" 888Y88888P888  8888b.  888888 888  888 888  888 888 ");
		puts(" 888 Y888P 888     Y88b 888    888 .88P 888  888 888 ");
		puts(" 888  Y8P  888 .d888888 888    888888K  888  888 888 ");
		puts(" 888   Y   888 888  888 Y88b.  888 Y88b Y88b 888 888 ");
		puts(" 888       888  Y888888   Y888 888  888   Y88888 888 ");
		printf("\n\n");
		
		printf("[%d]\tDetail untuk Mata Kuliah %d: \n\n", i+1, i+1);
		puts("\t[A]\tMasukkan nama mata kuliah:");
		printf("\t\t");
		fgets(c.nama, 50, stdin);
	
		printf("\n");
		puts("\t[B]\tMasukkan jumlah SKS:");
		printf("\t\t");
		fgets(temp, 50, stdin);
		result = sscanf(temp, "%2d", &credit);
		while (result != 1){
			puts("\t\tInput salah. Mohon memasukkan input angka yang benar:");
			printf("\t\t");
			fgets(temp, 50, stdin);
			result = sscanf(temp, "%2d", &credit);
		}
		c.sks = credit; 
		
		printf("\n");
		puts("\t[C]\tPilih nilai yang diharapkan (input angka sebelah kiri nilai yang tertera):");
		
		//Referensi ke displayGradeMenu
		displayGradeMenu(); 
		printf("\t\t");
		fgets(temp, 50, stdin);
		result = sscanf(temp,"%1d", &nilai);
		while (result != 1){ 
			puts("\t\tInput salah. Mohon memasukkan input angka yang benar:");
			printf("\t\t");
			fgets(temp, 50, stdin);
			result = sscanf(temp,"%1d", &nilai);
		}
		
		//Fetch ke header
		c.nilai = getGradeValue(nilai);
		i++;
		iteratorPtr = headAddressa;
        nextAddressa = new_node(c.nama, c.sks, c.nilai, NULL, i);
		while(1){
            if(headAddressa==NULL){
                headAddressa = nextAddressa;
                break;
            }
            else if ((*iteratorPtr).next == NULL){
                (*iteratorPtr).next = nextAddressa;
                break;
        	}
            else{
                iteratorPtr = (*iteratorPtr).next;
            }
        }
		
		
		if (i >= MATKUL_MAKS){
			puts("\n\tMata Kuliah ditambahkan!\n\n\tJumlah maksimum Mata Kuliah telah dimasukkan.\n\tTekan ENTER untuk melihat hasil.\n\n");
			getchar();
		}else{
			printf("\n\tMata Kuliah ditambahkan!\n\n[%d]\tUntuk menambahkan Mata Kuliah lainnya tekan (y).\n\tJika tidak, tekan ENTER untuk keluar dari penambahan Mata Kuliah.\n", i+3);
			printf("\t");
			stop = getchar();

			if (stop == 'y'){
				getchar();

			}
		}
	}
	*size = i;
}

void displayCourses(int size){
	int i;
	puts("\t888    888                   d8b 888 ");
	puts("\t888    888                   Y8P 888 ");
	puts("\t888    888                       888 ");
	puts("\t8888888888  8888b.  .d8888b  888 888 ");
	puts("\t888    888     Y88b 88K      888 888 ");
	puts("\t888    888 .d888888 .Y8888b. 888 888 ");
	puts("\t888    888 888  888      X88 888 888 ");
	puts("\t888    888 888  888      X88 888 888 ");
	puts("\t888    888 .Y888888  88888P' 888 888\n\n");
	i = 0;
	iteratorPtr = headAddressa;
	while (1){
        if(iteratorPtr->next == NULL){
			printf("\t%d). %s\t\tJumlah SKS: %d\tPerkiraan Nilai: %.2f\n",i+1,iteratorPtr->nama, iteratorPtr->sks, iteratorPtr->nilai);
			puts("+----------------------------------------------------+");
            iteratorPtr = (*iteratorPtr).next;	
            break;
        }else{
        	printf("\t%d). %s\t\tJumlah SKS: %d\tPerkiraan Nilai: %.2f\n",i+1,iteratorPtr->nama, iteratorPtr->sks, iteratorPtr->nilai);
			puts("+----------------------------------------------------+");
            iteratorPtr = (*iteratorPtr).next;
            i++;
        }
    }
}

void calculateIPK( int size, float mutu_kumulatif, int sks_l, float *ipk, float *ip){
	float points = mutu_kumulatif;
	int cred = sks_l;
	int i;
	iteratorPtr = headAddressa;
	while (1){
	        if(iteratorPtr->next == NULL){
	            points += (iteratorPtr->sks) * (iteratorPtr->nilai);
	            cred += iteratorPtr->sks;
	            iteratorPtr = (*iteratorPtr).next;
	            break;
	        }else{
	            points += (iteratorPtr->sks) * (iteratorPtr->nilai);
	            cred += iteratorPtr->sks;
	            iteratorPtr = (*iteratorPtr).next;
	        }
	    }
	*ipk = points/cred;
	*ip = (points - mutu_kumulatif)/(cred - sks_l);
}

int main (int argc, char ** argv){
	float mutu_kumulatif;
	int result;
	int sks_l;
	int numCourses = 0;
	float ipk;
	float ip;
	char c;
	char temp[50];

	puts("                                                                                ");
 	puts(" 888    d8P           888 888               888          888                    ");
 	puts(" 888   d8P            888 888               888          888                    ");
 	puts(" 888  d8P             888 888               888          888                    ");
 	puts(" 888d88K      8888b.  888 888  888 888  888 888  8888b.  888888 .d88b.  888d888 ");
 	puts(" 8888888b        888b 888 888 .88P 888  888 888     888b 888   d88  88b 888P    ");
 	puts(" 888  Y88b   .d888888 888 888888K  888  888 888 .d888888 888   888  888 888     ");
 	puts(" 888   Y88b  888  888 888 888  88b Y88b 888 888 888  888 Y88b. Y88..88P 888     ");
 	puts(" 888    Y88b  Y888888 888 888  888   Y88888 888  Y888888   Y888  Y88PY  888     ");
 	puts("\n");
 	puts("                      8888888 8888888b.  888    d8P                             ");
 	puts("                        888   888   Y88b 888   d8P                              ");
 	puts("                        888   888    888 888  d8P                               ");
 	puts("                        888   888   d88P 888d88K                                ");
 	puts("                        888   8888888PY  8888888b                               ");
 	puts("                        888   888        888  Y88b                              ");
 	puts("                        888   888        888   Y88b                             ");
 	puts("                      8888888 888        888    Y88b                            ");
 	puts("\n");

	puts("[1]\tMasukkan total SKS Anda yang telah selesai diambil:\n\t(Lihat di laman siakNG Anda di bagian ringkasan akademis,\n\tlalu lihat kolom SKS L.)");
	printf("\t");
	fgets(temp, 50, stdin);
	result = sscanf(temp,"%d",&sks_l);
	while (result != 1){ 
		puts("\tInput salah. Mohon memasukkan input angka yang benar:");
		printf("\t");
		fgets(temp, 50, stdin);
		result = sscanf(temp,"%d",&sks_l);
	}
	printf("\n\t\tTotal SKS Anda: %d SKS\n\n", sks_l);

	puts("[2]\tMasukkan Mutu Kumulatif Anda yang selesai diambil:");
	puts("\t(Mutu kumulatif adalah total nilai yang diterima di setiap Matkul,\n\tatau Anda dapat melihat di ringkasan akademis SiakNG, lalu lihat di\n\tkolom MUTU KUMULATIF.)");
	printf("\t");
	fgets(temp, 50, stdin); 
	result = sscanf(temp,"%f",&mutu_kumulatif); 
	while (result != 1){ 
		puts("\tInput salah. Mohon memasukkan input angka yang benar:");
		printf("\t");
		fgets(temp, 50, stdin);
		result = sscanf(temp,"%f",&mutu_kumulatif); 
	}
	printf("\n\t\tMutu Kumulatif Anda: %.2f \n", mutu_kumulatif); 

	printf("\n\t\tIPK Anda sekarang  : %.2f\n\n", mutu_kumulatif/sks_l);

	puts("[3]\tTekan 'y' untuk memasukkan Mata Kuliah agar mengetahui perkiraan IPK.\n\tJika tidak, tekan ENTER.\n");
	printf("\t");
	c = getchar();
	system("cls");
	
	if( c == 'y') { 
		getchar(); 
		
		//Mereferensikan ke fungsi getCourses
		getCourses(&numCourses);

		system("cls");
		//Mereferensikan ke fungsi displayCourses
		displayCourses(numCourses);
		
		//Mereferensikan ke fungsi calculateIPK
		calculateIPK(numCourses, mutu_kumulatif, sks_l, &ipk, &ip);
		printf("\n\tPerkiraan IP semester ini :\t%.2f\n\n", ip);
		printf("\tPerkiraan IPK Anda        :\t%.2f\n\n\n", ipk); 
	}
	puts("Tekan ENTER untuk KELUAR...");
	getchar();

	return 0;
}
