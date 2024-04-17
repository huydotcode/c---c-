#include <stdio.h>

void ReadData(char filename[],int arr[],int &n); // hàm đọc từ file ra mảng A
void BubbleSort(int arr[], int n);    // sắp xếp mảng A theo thuật toán BubbleSort
void output_arr(int arr[], int n);    // xuất giá trị mảng A ra màn hình
void swap(int &a, int &b);
void main1(char filename[]);                     // hàm nhận vào tên file fn, tạo mảng A, sắp xếp mảng A và xuất ra màn hình


int main() {
    char fn[]="sort.txt";
    main1(fn);

    return 0;
}

void ReadData(char filename[],int arr[],int &n) {
    printf("Read data");
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Cannot open this file");
        return;
    }
    int i=0;
    while (fscanf(file, "%d", &arr[i]) != EOF) {
        i++;
    }
    n = i;
    fclose(file);
}

void BubbleSort(int arr[], int n) {
    printf("\nBubble sort\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void output_arr(int arr[], int n) {
    printf("Xuat mang\n");
    for (int i=0; i<n; i++) {
        printf("%d\t", arr[i]);
    }
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void main1(char filename[]) {
    int n;
    int arr[n];

    ReadData(filename, arr, n);
    BubbleSort(arr, n);
    output_arr(arr, n);
}