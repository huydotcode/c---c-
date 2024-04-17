#include<stdio.h>
#include<string.h>

struct WORD{
    char Name[256];
    char Meaning[512];
};

void nhap_tu_vung(WORD w[], int n);
void xuat_tu_vung(WORD w[], int n);
void doc_file(WORD w[], int &n, char *filename);
void xuat_ra_file(WORD w[], int n, char *filename);

int main() {
    int n = 2;
    WORD w[n];

//    nhap_tu_vung(w, n);
//    xuat_tu_vung(w, n);

    char filename[50];
    printf("\nNhap ten file: ");
    gets(filename);
    fflush(stdin);

//    xuat_ra_file(w, n, filename);
    doc_file(w, n, filename);
    xuat_tu_vung(w,n);

    return 0;
}

void nhap_tu_vung(WORD w[], int n) {
    for (int i=0; i<n ;i++) {
        printf("\nNhap tu: ");
        gets(w[i].Name);
        fflush(stdin);
        printf("Nhap nghia cua tu: ");
        gets(w[i].Meaning);
        fflush(stdin);
    }
}
void xuat_tu_vung(WORD w[], int n) {
    printf("\nTu vung:");
    for (int i=0; i<n; i++) {
        printf("\n%s: %s", w[i].Name, w[i].Meaning);
    }
}
void doc_file(WORD w[], int &n, char *filename) {
    FILE *file = fopen(filename, "ab+");

    if (!file) return;

    int i=0;
    while(fread(&w[i], sizeof(WORD), 1, file) != NULL) {
        i++;
    }

    n=i;
    fclose(file);
}
void xuat_ra_file(WORD w[], int n, char *filename) {
    FILE *file = fopen(filename, "ab+");

    if (!file) return;

    fwrite(w, sizeof(WORD), n, file);
    fclose(file);
}
