#include<stdio.h>
#include <stdlib.h>
#include <time.h>

void nhapMang(int arr[], int length);
void xuatMang(int arr[], int length);
void PhatSinhMang(int arr[], int n);

void InterchargeSort(int arr[], int length);
void BubbleSort(int arr[], int length);
void InsertionSort(int arr[], int length);
void SelectionSort(int arr[], int length);
void QuickSort(int arr[], int left, int right);

void LuuMangVaoFile(char *filename, int arr[], int n);
void DocMangTrongFile(char *filename, int arr[], int &n);

void Swap (int &a, int &b);

int main() {
    int length;
    int arr[length];
    int choice;

    do {
        printf("\n1. Nhap mang");
        printf("\n2. Xuat mang");
        printf("\n3. Phat sinh mang");
        printf("\n4. Ghi mang vao file");
        printf("\n5. Doc mang trong file");
        printf("\n5. InterchargeSort");
        printf("\n6. BubbleSort");
        printf("\n7. InsertionSort");
        printf("\n8. SelectionSort");
        printf("\n9. QuickSort");
        printf("\nNhap 0 de thoat chuong trinh");
        printf("\nNhap su lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nNhap so phan tu cua mang: ");
                scanf("%d", &length);
                nhapMang(arr, length);
                break;
            case 2:
                xuatMang(arr, length);
                break;
            case 3:
                printf("\nNhap so phan tu cua mang can phat sinh: ");
                scanf("%d", &length);
                PhatSinhMang(arr ,length);
                break;
            case 4:
                char filename1[50];
                printf("\nNhap ten file: ");
                scanf("%s", &filename1);
                fflush(stdin);
                LuuMangVaoFile(filename1, arr, length);
                break;
            case 5:
                char filename2[50];
                printf("\nNhap ten file: ");
                scanf("%s", &filename2);

                DocMangTrongFile(filename2, arr, length);
                break;
            case 6:
                InterchargeSort(arr, length);
                break;
            case 7:
                BubbleSort(arr, length);
                break;
            case 8:
                InsertionSort(arr, length);
                break;
            case 9:
                SelectionSort(arr, length);
                break;
            case 10:
                QuickSort(arr, 0, length - 1);
                break;
            default:
                break;
        }
    } while (choice != 0);



    return 0;
}

void nhapMang(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        printf("Arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
}

void xuatMang(int arr[], int length) {
    printf("\nXuat mang: ");
    printf("\nArr: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
}

void InterchargeSort(int arr[], int length) {
    printf("\nInterchargeSort");
    for (int i = 0; i < length - 1; i++) {
        for (int j = i+1; j < length; j++) {
            if (arr[i] > arr[j]) Swap(arr[i], arr[j]);
        }
    }
}

void BubbleSort(int arr[], int length) {
    printf("\nBubbleSort");
    for (int i = 0; i < length - 1; i++) {
        for (int j = length - 1; j > i; j--) {
            if (arr[i] > arr[j]) Swap(arr[i], arr[j]);
        }
    }
}

void InsertionSort(int arr[], int length) {
    printf("\nIntertionSort");
    for (int i = 1; i < length; i++) {
        int x = arr[i];
        int pos = i - 1;

        while (pos >= 0 && arr[pos] > x) {
            arr[pos + 1] = arr[pos];
            --pos;
        }
        arr[pos + 1] = x;
    }
}

void SelectionSort(int arr[], int length) {
    for (int i = 0; i < length - 1; i++) {
        int min = i;

        for (int j = i + 1; j < length; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }

        if (min != i) Swap(arr[i], arr[min]);
    }
}
void QuickSort(int arr[], int left, int right) {
    int i = left;
    int j = right;
    int middle = arr[(left + right) / 2];

    do {
        while (arr[i] < middle) i++;
        while (arr[j] > middle) j--;

        if (i <= j) {
            Swap(arr[i], arr[j]);
            i++; j--;
        }
    } while (i <= j);

    if (left < j) QuickSort(arr, left, j);
    if (right > i) QuickSort(arr, i, right);

}

void Swap (int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void PhatSinhMang(int arr[], int n) {

    srand(time(NULL));

    for (int i=0; i<n; i++) {
        arr[i] = rand();
    }
}

void LuuMangVaoFile(char *filename, int arr[], int n) {
    printf("\nLuu mang vao file");
    FILE *file = fopen(filename, "w");

    if (!file) {
        printf("Khong the mo file");
        return;
    }

    for (int i=0; i<n; i++) {
        fprintf(file, "%d\t", arr[i]);
    }

    fclose(file);
}
void DocMangTrongFile(char *filename, int arr[], int &n) {
    FILE *file = fopen(filename, "r");
    int i=0;
    while(!feof(file)) {
        fscanf(file, "%d", &arr[i]);
        i++;
    }
    n=i;
    fclose(file);
}


