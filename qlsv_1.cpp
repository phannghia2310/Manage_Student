#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

struct SinhVien{
    char ten[30];
    char gt[5];
    int age;
    float dT, dL, dH;
    float dtb;
};
 
typedef SinhVien SV;
 
void nhap(SV &sv);
void nhapN(SV a[], int n);
void xuat(SV sv);
void xuatN(SV a[], int n);
void tinhDTB(SV &sv);
void sapxep(SV a[], int n);
void xeploai(SV a);
void xeploaiN(SV a[], int n);
void timkiem(SV a[], int n);
void xuatFile(SV a[], int n, char fileName[]);
int Menu();

int main(){
	system("color 0A");
	Menu();
}

void tinhDTB(SV &sv){
    sv.dtb = (sv.dH + sv.dL + sv.dT)/3;    
}
 
void nhap(SV &sv){
    printf("\nNhap ten: "); fflush(stdin); gets(sv.ten);
    printf("\nNhap gioi tinh: "); gets(sv.gt);
    printf("\nNhap tuoi: "); scanf("%d", &sv.age);
    printf("\nNhap diem 3 mon: "); scanf("%f%f%f", &sv.dT, &sv.dL, &sv.dH);
    tinhDTB(sv);
}
 
void nhapN(SV a[], int n){
    printf("\n____________________________________\n");
    for(int i = 0; i< n; ++i){
        printf("\nNhap SV thu %d:", i+1);
        nhap(a[i]);
    }
    printf("\n____________________________________\n");
}
 
void xuat(SV sv){
    printf("\nHo ten SV: %s", sv.ten);
    printf("\nGioi tinh: %s", sv.gt);
    printf("\nTuoi SV  : %d", sv.age);
    printf("\nDiem Toan - Ly - Hoa: %.2f - %.2f - %.2f", sv.dT, sv.dL, sv.dH);
    printf("\nDiem TB: %.2f", sv.dtb);
}
 
void xuatN(SV a[], int n){
    printf("\n____________________________________\n");
    for(int i = 0;i < n; ++i){
        printf("\nThong tin SV thu %d:", i+1);
        xuat(a[i]);
    }
    printf("\n____________________________________\n");
}

 void sapxep(SV a[], int n){
    //Sap xep theo ten
    SV tmp;
    for(int i=0; i<n; ++i){
        for(int j=i+1; j<n; ++j){
            if(strcmp(a[i].ten, a[j].ten)>0){
				tmp = a[i];
				a[i] = a[j];
				a[j]=tmp;
			}
        }
    }
}

void xeploai(SV sv){
    if(sv.dtb >= 8) printf("Gioi");
    else if(sv.dtb >= 6.5) printf("Kha");
    else if(sv.dtb >= 4) printf("Trung binh");
    else printf("Yeu");
}
 
void xeploaiN(SV a[], int n){
    printf("\n____________________________________\n");
    for(int i = 0;i < n;++i){
        printf("\nXep loai cua SV thu %d la: ", i+1);
        xeploai(a[i]);
    }
    printf("\n____________________________________\n");
}


void timkiem(SV a[], int n){
	printf("\n____________________________________\n");
	int tm;
	int dem = 0;
	printf("Nhap tuoi sinh vien can tim: ");
	fflush(stdin);
	scanf("%d", &tm);
	for(int i=0; i<n; ++i){
		if(tm==a[i].age){
			printf("\nKet qua tim kiem sinh vien %d:", tm);
			xuat(a[i]);
			dem++;
        }
    }
	if(dem==0)
		printf("\nKhong co sinh vien nay trong danh sach!");    
	printf("\n____________________________________\n");
}
void xuatFile(SV a[], int n, char fileName[]){
    FILE * fp;
    fp = fopen(fileName,"w");
    fprintf(fp, "%20s%5s%5s%10s%10s%10s%10s\n", "Ho Ten","GT", "Tuoi", "DT", "DL", "DH", "DTB");
    for(int i = 0;i < n;i++){
        fprintf(fp, "%20s%5s%5d%10.2f%10.2f%10.2f%10.2f\n",
					a[i].ten,a[i].gt, a[i].age, a[i].dT, a[i].dL, a[i].dH, a[i].dtb);
    }
    fclose(fp);
}

int Menu(){
	int key;
    char fileName[] = "DSSV.txt";
    int n;
    bool daNhap = false;
    do{
        printf("\nNhap so luong SV: "); scanf("%d", &n);
    }while(n <= 0);
    SV a[n];
    while(true){
        system("cls");
        printf(" \n\n\n\n\n\n");
        printf("                                ****************************************\n");
        printf("                                *    CHUONG TRINH QUAN LY SINH VIEN    *\n");
        printf("                                *      1. Nhap danh sach sinh vien     *\n");
        printf("                                *      2. Xuat danh sach sinh vien     *\n");
        printf("                                *      3. Sap xep sinh vien theo ten   *\n");
        printf("                                *      4. Xep loai sinh vien           *\n");
        printf("                                *      5. Xuat DS sinh vien ra file    *\n");
        printf("                             	*      6. Tim kiem sinh vien           *\n");
        printf("                                *      0. Thoat                        *\n");
        printf("                                ****************************************\n");
        printf("                                **       Nhap lua chon cua ban        **\n");
        scanf("%d",&key);
        switch(key){
            case 1:
                printf("\nBan da chon nhap DS sinh vien!");
                nhapN(a, n);
                printf("\nBan da nhap thanh cong!");
                daNhap = true;
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            case 2:
                if(daNhap){
                    printf("\nBan da chon xuat DS sinh vien!");
                    xuatN(a, n);
                }else{
                    printf("\nNhap DS SV truoc!!!!");
                }
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            case 3:
                if(daNhap){
                    printf("\nBan da chon sap xep SV theo DTB!");
                    sapxep(a, n);
                    xuatN(a, n);
                }else{
                    printf("\nNhap DS SV truoc!!!!");
                }
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            case 4:
                if(daNhap){
                    printf("\nBan da chon xep loai SV!");
                    xeploaiN(a, n);
                }else{
                    printf("\nNhap DS SV truoc!!!!");
                }
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            case 5:
                if(daNhap){
                    printf("\nBan da chon xuat DS SV!");
                    xuatFile(a, n, fileName);
                }else{
                    printf("\nNhap DS SV truoc!!!!");
                }
                printf("\nGhi DSSV thanh cong vao file %s!", fileName);
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            case 6:
            	if(daNhap){
            		printf("\nBan da chon tim kiem thong tin sinh vien");
            		timkiem(a, n);
            	}else{
            		printf("\nNhap DS SV truoc!!!!");
				}
				printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            case 0:
                printf("\nBan da chon thoat chuong trinh!");
                getch();
                return 0;
            default:
                printf("\nKhong co chuc nang nay!");
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
        }
    }
}
