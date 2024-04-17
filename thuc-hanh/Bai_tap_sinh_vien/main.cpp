#include<stdio.h>
#include<string.h>

#define MAX 100

typedef struct {
    int ngay;
    int thang;
    int nam;
} NgaySinh;

typedef struct {
    float diem_tk1;
    float diem_tk2;
    float diem_tk3;
    float diem_gk;
    float diem_ck;
    float diem_tb;
} Diem;

typedef struct {
    char mssv[10];
    char ho[30];
    char ten[20];
    NgaySinh ngay_sinh;
    Diem diem;
} SinhVien;

void nhap_mang_sv(SinhVien mang_sv[], int &so_luong);
void nhap_sv (SinhVien &sv);
void xuat_mang_sv(SinhVien mang_sv[], int so_luong);
void xuat_sv (SinhVien &sv);

void ghi_mang_vao_file (char *ten_file, SinhVien mang_sv[], int so_luong);
void doc_mang_trong_file (char *ten_file, SinhVien mang_sv[], int &so_luong);

SinhVien linear_search (SinhVien mang_sv[], int so_luong, char ten_can_tim[50]);
//SinhVien binary_search (SinhVien mang_sv[], int so_luong, char ten_can_tim[50]);

SinhVien binary_search (SinhVien mang_sv[], int left, int right, char ten_can_tim[50]);
void QuickSort (SinhVien sv[], int left, int right);

int main() {
    SinhVien mang_sv[MAX];
    int so_luong;
    int lua_chon;

    do {
        printf("\n1. Nhap sinh vien");
        printf("\n2. Xuat mang sinh vien");
        printf("\n3. Ghi mang sinh vien vao file");
        printf("\n4. Doc va in ra sinh vien trong file");
        printf("\n5. Tim kiem theo ten");
        printf("\n6. Tim kiem theo ten va tra danh sach");
        printf("\nNhap su lua chon ( Nhap 0 de thoat): ");
        scanf("%d", &lua_chon);
        switch (lua_chon) {
            case 1:
                nhap_mang_sv(mang_sv, so_luong);
                break;
            case 2:
                xuat_mang_sv(mang_sv, so_luong);
                break;
            case 3:
                char ten_file_ghi[50];
                printf("\nNhap ten file can ghi: ");
                fflush(stdin);
                scanf("%s", &ten_file_ghi);
                ghi_mang_vao_file(ten_file_ghi, mang_sv, so_luong);
                break;
            case 4:
                char ten_file_doc[50];
                printf("\nNhap ten file can doc: ");
                fflush(stdin);
                scanf("%s", &ten_file_doc);
                doc_mang_trong_file(ten_file_doc, mang_sv, so_luong);
                break;
            case 5:
                char ten_can_tim[50];
                printf("\nNhap ten can tim: ");
                fflush(stdin);
                scanf("%s", &ten_can_tim);

                linear_search(mang_sv, so_luong, ten_can_tim);
                break;
            case 6:
                char ten_can_tim1[50];
                printf("\nNhap ten can tim: ");
                fflush(stdin);
                scanf("%s", &ten_can_tim);

                SinhVien sv_can_tim = binary_search(mang_sv, 0, so_luong - 1, ten_can_tim);
                break;
        }

    } while (lua_chon != 0);
    return 0;
}

void nhap_mang_sv(SinhVien mang_sv[], int &so_luong) {
    char lua_chon;
    do {
        nhap_sv(mang_sv[so_luong]);
        so_luong++;

        printf("\nTiep tuc nhap sinh vien (y/n): ");
        fflush(stdin);
        scanf("%c", &lua_chon);

    } while (lua_chon == 'y' || lua_chon == 'Y');
}

void nhap_sv (SinhVien &sv) {
    printf("\nNhap thong tin sinh vien");

    printf("\nNhap ma so sinh vien: ");
    fflush(stdin);
    scanf("%s", sv.mssv);

    printf("Nhap ho va ten dem cua sinh vien: ");
    fflush(stdin);
    gets(sv.ho);

    printf("Nhap ten cua sinh vien: ");
    fflush(stdin);
    scanf("%s", &sv.ten);

    printf("Nhap ngay sinh cua sinh vien ( dd ): ");
    scanf("%d", &sv.ngay_sinh.ngay);

    printf("Nhap thang sinh cua sinh vien ( MM ): ");
    scanf("%d", &sv.ngay_sinh.thang);

    printf("Nhap nam sinh cua sinh vien ( yyyy ): ");
    scanf("%d", &sv.ngay_sinh.nam);

    printf("Nhap diem thuong ky 1 cua sinh vien: ");
    scanf("%f", &sv.diem.diem_tk1);

    printf("Nhap diem thuong ky 2 cua sinh vien: ");
    scanf("%f", &sv.diem.diem_tk2);

    printf("Nhap diem thuong ky 3 cua sinh vien: ");
    scanf("%f", &sv.diem.diem_tk3);

    printf("Nhap diem giua ky cua sinh vien: ");
    scanf("%f", &sv.diem.diem_gk);

    printf("Nhap diem cuoi ky cua sinh vien: ");
    scanf("%f", &sv.diem.diem_ck);

    sv.diem.diem_tb = (((sv.diem.diem_tk1+ sv.diem.diem_tk2 + sv.diem.diem_tk3) / 3) * 0.2 +
            (sv.diem.diem_gk * 0.3) + (sv.diem.diem_ck * 0.5));
    printf("Diem trung binh cua sinh vien la: %.2f", sv.diem.diem_tb);
}

void xuat_mang_sv(SinhVien mang_sv[], int so_luong) {
    printf("\n%-15s%-20s%-15s%-20s%-30s", "MSSV", "Ho va dem", "Ten", "Ngay sinh", "Diem");
    for (int i = 0; i < so_luong; i++) {
        xuat_sv(mang_sv[i]);
    }
}

void xuat_sv (SinhVien &sv) {
    printf("\n%-15s%-20s%-15s%d/%d/%d %14.2f %.2f %.2f %.2f %.2f %.2f", sv.mssv, sv.ho, sv.ten, sv.ngay_sinh.ngay,
           sv.ngay_sinh.thang, sv.ngay_sinh.nam, sv.diem.diem_tk1, sv.diem.diem_tk2, sv.diem.diem_tk3, sv.diem.diem_gk,
           sv.diem.diem_ck, sv.diem.diem_tb);
}

void ghi_mang_vao_file (char *ten_file, SinhVien mang_sv[], int so_luong) {
    printf("Ghi mang vao file %s", ten_file);
    FILE* file = fopen(ten_file, "ab+");

    if (file == NULL) {
        printf("\nKhong the mo tep nay");
        return;
    }
    fwrite(mang_sv, sizeof(SinhVien), so_luong, file);
    fclose(file);
    printf("\nGhi vao mang thanh cong!\n");
}

void doc_mang_trong_file (char *ten_file, SinhVien mang_sv[], int &so_luong) {
    printf("\nThong tin sinh vien trong file %s: ", ten_file);
    FILE *file = fopen(ten_file, "ab+");

    so_luong = 0;

    if (file == NULL) {
        printf("\nKhong the mo tep!\n");
        return;
    }

    while(fread(&mang_sv[so_luong],sizeof(SinhVien),1,file)!=NULL){
        so_luong++;
    }

    fclose(file);
    xuat_mang_sv(mang_sv, so_luong);
    printf("\nDoc thong tin trong file thanh cong!\n");
}

SinhVien linear_search (SinhVien mang_sv[], int so_luong, char ten_can_tim[50]) {
    int i=0;
    while (i < so_luong && strcmp(mang_sv[i].ten, ten_can_tim) != 0 ) {
        i++;
    }

    if (i < so_luong) {
        printf("\nKet qua tim kiem: ");
        xuat_sv(mang_sv[i]);
    }
}

void QuickSort (SinhVien mang_sv[], int left, int right) {
    if (left > right) return;

    printf("\nQuick Sort");
    int i = left;
    int j = right;
    SinhVien middle = mang_sv[(left + right) / 2];

    do {
        while (strcmp(mang_sv[i].ten, middle.ten) < 0) i++;
        while (strcmp(mang_sv[j].mssv, middle.mssv) > 0) j--;

        if (i <= j) {
            SinhVien temp;
            temp = mang_sv[i];
            mang_sv[i] = mang_sv[j];
            mang_sv[j] = temp;
            i++; j--;
        }
    } while (i <= j);

    if (left < j) QuickSort (mang_sv, left, j);
    if (right > i) QuickSort (mang_sv, i, right);
}

SinhVien binary_search (SinhVien mang_sv[], int left, int right, char ten_can_tim[50]) {
    int mid = (left + right) / 2;

    if (left > right) {
        if (strcmp(mang_sv[mid].ten, ten_can_tim) == 0) {
            return mang_sv[mid];
        }

        if (strcmp(mang_sv[mid].ten,  ten_can_tim) > 0) {
            return binary_search(mang_sv, left, mid - 1, ten_can_tim);
        }

        if (strcmp(mang_sv[mid].ten, ten_can_tim) < 0) {
            return binary_search(mang_sv, mid + 1, right, ten_can_tim);
        }
    }
}


