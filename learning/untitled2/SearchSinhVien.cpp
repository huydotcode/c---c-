#include<stdio.h>
#include<string.h>

typedef struct {
    int ngay;
    int thang;
    int nam;
} Ngaysinh;

typedef struct {
    char MaSV[50];
    char Hoten[50];
    Ngaysinh Ngaysinh;
} SinhVien;

void NhapSv (SinhVien sv[], int length);
void XuatSv (SinhVien sv[], int length);
void LinearSearch(SinhVien sv[], int length, char x[50]);

int main() {
    int siso;
    char tenCanTim[50];
    SinhVien sv[siso];

    do {
        printf("Nhap si so: ");
        scanf("%d", &siso);
    } while (siso <= 0);

    NhapSv(sv, siso);

    char name[50];
    printf("Nhap ten ");
    scanf("%s", name);


    LinearSearch(sv, siso, name);

    XuatSv(sv, siso);

    return 0;
}

void NhapSv(SinhVien sv[], int length) {
    for (int i=0; i<length; i++) {
        printf("\nNhap thong tin sinh vien %d:\n", i+1);
        printf("Nhap ma sv: ");
        scanf("%s", sv[i].MaSV);

        printf("Nhap ten sv: ");
        scanf("%s", sv[i].Hoten);

        printf("Nhap ngay sinh: ");
        scanf("%d", &sv[i].Ngaysinh.ngay);

        printf("Nhap thang sinh: ");
        scanf("%d", &sv[i].Ngaysinh.thang);

        printf("Nhap nam sinh: ");
        scanf("%d", &sv[i].Ngaysinh.nam);
    }
}

void XuatSv (SinhVien sv[], int length) {
    printf("\nXuat SV");
    for (int i=0; i<length; i++) {
        printf("\nSinh vien %d", i + 1);
        printf("\nMa SV %s", sv[i].MaSV);
        printf("\nTen sv %s", sv[i].Hoten);
        printf("\nNgay sinh: %d-%d-%d", sv[i].Ngaysinh.ngay,sv[i].Ngaysinh.thang, sv[i].Ngaysinh.nam);
    }
}

void LinearSearch(SinhVien sv[], int length, char x[50]) {
    for (int i = 0; i < length; i++) {
        if (strcmp(sv[i].Hoten, x)) {
            printf("Tim thay %s o vi tri %d", x, i);
        }
    }
}

