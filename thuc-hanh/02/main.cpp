    #include<stdio.h>
    #include <stdlib.h>
    #include <time.h>

void NhapMang(int arr[], int n);
void XuatMang(int arr[], int n);
void PhatSinhMang(int arr[], int n);
void PhatSinhMangTang(int arr[], int n);

int GhiMangVaoFileText(char *filename, int arr[], int n);
int DocFileTextVaoMang(char *filename, int arr[], int &n);

int InterchangeSort(int arr[], int n);
int LinearSearch(int arr[], int n, int x);
int BinarySearch(int arr[], int n, int x);

int main() {
    int n;
    int arr[n];
    int choice;

    do {
        printf("\n\n1. Nhap mang");
        printf("\n2. Xuat mang");
        printf("\n3. Phat sinh mang");
        printf("\n4. Phat sinh mang tang");
        printf("\n5. Ghi mang vao file text");
        printf("\n6. Doc file text vao mang");
        printf("\n7. Sap xep doi cho truc tiep");
        printf("\n8. Tim kiem tuyen tinh");
        printf("\n9. Tim kiem nhi phan");
        printf("\n0. Thoat chuong trinh");

        printf("\nNhap su lua chon: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nNhap so phan tu: ");
                scanf("%d", &n);
                NhapMang(arr, n);
                break;
            case 2:
                XuatMang(arr, n);
                break;
            case 3:
                printf("\nNhap so phan tu: ");
                scanf("%d", &n);
                PhatSinhMang(arr, n);
                break;
            case 4:
                printf("\nNhap so phan tu: ");
                scanf("%d", &n);
                PhatSinhMangTang(arr, n);
                break;
            case 5:
                char filename1[50];
                printf("\nNhap ten file: ");
                fflush(stdin);
                scanf("%s", &filename1);

                GhiMangVaoFileText(filename1, arr, n);
                break;
            case 6:
                char filename2[50];
                printf("\nNhap ten file: ");
                fflush(stdin);
                scanf("%s", &filename2);

                DocFileTextVaoMang(filename2, arr, n);
                break;
            case 7:
                InterchangeSort(arr, n);
                printf("Mang sau khi sap xep: ");
                XuatMang(arr, n);
                break;
            case 8:
                int key1;
                int find1;
                printf("\nNhap so can tim: ");
                scanf("%d", &key1);
                find1 = LinearSearch(arr, n, key1);

                if (find1 != -1) {
                    printf("Vi tri duoc tim thay: %d", find1);
                } else {
                    printf("Khong tim thay");
                }
                break;
            case 9:
                int key2;
                int find2;
                printf("\nNhap so can tim: ");
                scanf("%d", &key2);

                InterchangeSort(arr, n);
                find2 = BinarySearch(arr, n, key2);

                if (find2 != -1) {
                    printf("Vi tri duoc tim thay: %d", find2);
                } else {
                    printf("Khong tim thay");
                }
                break;
            default:
                break;
        }
    } while (choice != 0);
}

void NhapMang(int arr[], int n) {
    printf("\nNhap mang co %d phan tu: \n", n);
    for (int i=0; i<n; i++) {
        printf("Nhap phan tu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}
void XuatMang(int arr[], int n) {
    printf("\nXuat mang\n");
    for (int i=0; i<n; i++) {
        printf("%20d", arr[i]);
    }
}
void PhatSinhMang(int arr[], int n) {
    printf("\nPhat sinh mang\n");
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand();
    }
}
void PhatSinhMangTang(int arr[], int n) {
    printf("\nPhat sinh mang tang\n");
    srand(time(NULL));

    arr[0] = rand() % 10;

    for (int i = 1; i<n; i++) {
        arr[i] = arr[i-1] + rand() % 10;
    }
};

int GhiMangVaoFileText(char *filename, int arr[], int n) {
    printf("\nGhi mang vao file text\n");
    FILE *file = fopen(filename, "w");

    if (!file) return 0;

    for (int i=0; i<n; i++) {
        fprintf(file, "%d\t", arr[i]);
    }

    fclose(file);
    return 1;
}

int DocFileTextVaoMang(char *filename, int arr[], int &n) {
    printf("\nDoc file text vao mang\n");
    FILE *file = fopen(filename, "r");

    if (!file) return 0;

    int i=0;
    while (fscanf(file, "%d", &arr[i]) != EOF) {
        i++;
    }

    n=i;
}

int InterchangeSort(int arr[], int n) {
    printf("\nInterchange sort\n");
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

}
int LinearSearch(int arr[], int n, int x) {
    printf("\nTim kiem %d\n", x);
    for (int i=0; i<n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }

    return -1;
}
int BinarySearch(int arr[], int n, int x) {
    printf("\nTim kiem %d\n", x);
    int right = n - 1;
    int left = 0;
    while (right >= left) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            right = mid - 1;

        if (arr[mid] < x)
            left = mid + 1;
    }
    return -1;
}
