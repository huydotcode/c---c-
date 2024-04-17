#include <stdio.h>
#include <string>
#include <iostream>

void ReadData(char filename[],int arr[],int &n); // hàm ??c t? file ra m?ng A
void BubbleSort(int arr[], int n);    // s?p x?p m?ng A theo thu?t toán BubbleSort
void output_arr(int arr[], int n);    // xu?t giá tr? m?ng A ra màn hình
void swap(int &a, int &b);
void main1(char filename[]);                     // hàm nh?n vào tên file fn, t?o m?ng A, s?p x?p m?ng A và xu?t ra màn hình
void SortElements(string filename, int n) {
	FILE *file = fopen(filename, "r");
	
	int arr[100];
	
	if (!file) {
		printf("Cannot open this file");
	}
	
	int i=0;
	fscanf(file, "%d\n", &arr[i++]);
	while (fscanf(file, "%d\n", &arr[i]) != EOF) {
		i++;
	}
	
	fclose(file);
}


int main() {
    std::string fn = "Numbers01.txt";
	int n = 10;
	SortElements(fn,n);

    return 0;
}

void ReadData(char filename[],int arr[],int &n) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Cannot open this file");
        return;
    }
    int i=0;
    fscanf(file, "%d\n", &arr[i]);
    ++i;
    while (fscanf(file, "%d\n", &arr[i]) != EOF) {
        i++;
    }
    n = i;
    fclose(file);
}

void BubbleSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void output_arr(int arr[], int n) {    
    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void main1(char filename[]) {
    int n = 0;
    int arr[100];

    ReadData(filename, arr, n);
    BubbleSort(arr, n);
    output_arr(arr, n);
}
