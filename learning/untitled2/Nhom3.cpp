#include <stdio.h>
#include <string.h>

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
void QuickSort (SinhVien sv[], int left, int right);
void Swap (SinhVien sv1, SinhVien sv2);

int main() {

    int siso;
    SinhVien sv[siso];

    do {
        printf("Nhap si so: ");
        scanf("%d", &siso);
    } while (siso <= 0);

    NhapSv(sv, siso);

    QuickSort(sv, 0, siso - 1);

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

void QuickSort (SinhVien sv[], int left, int right) {
	if (left > right) return;
	
    printf("\nQuick Sort");
    int i = left;
    int j = right;
    SinhVien middle = sv[(left + right) / 2];

    do {
        while (strcmp(sv[i].MaSV, middle.MaSV) < 0) i++;
        while (strcmp(sv[j].MaSV, middle.MaSV) > 0) j--;

        if (i <= j) {
            SinhVien temp;
            temp = sv[i];
            sv[i] = sv[j];
            sv[j] = temp;
            i++; j--;
        }
    } while (i <= j);

    if (left < j) QuickSort (sv, left, j);
    if (right > i) QuickSort (sv, i, right);
}

void Swap (SinhVien sv1, SinhVien sv2) {

}
