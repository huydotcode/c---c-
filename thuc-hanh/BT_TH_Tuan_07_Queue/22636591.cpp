#include <cstdio>
#define MAX_QUEUE 100;

typedef struct MatHang {
    int maMh;
    char tenMh[12];
};

struct Queue {
    int front, rear;
    MatHang nodes[];
};

void Init(Queue &q);
int isEmpty(Queue q);
void Insert(Queue &q, MatHang x);
MatHang Remove(Queue &q);
void Traverse(Queue q);

int main() {
    Queue q;
    int choice, front1;
    char c;
    MatHang mh;

    Init(q);
    do {
        printf("\n\n\t\tCHUONG TRINH QUAN LY KHO");
        printf("\n\t\t\tNHAP TRUOC - XUAT TRUOC");
        printf("\nCac chuc nang cua chuong trinh: \n");
        printf("1. Nhap mot mat hang\n");
        printf("2. Xuat mot mat hang\n");
        printf("3. Xem mat hang chuan bi xuat\n");
        printf("4. Xem mat hang moi nhap\n");
        printf("5. Xem cac mat hang co trong kho\n");
        printf("6. Xuat toan bo kho hang\n");
        printf("0. Ket thuc chuong trinh\n");
        printf("Chuc nang ban chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nMa mat hang: ");
                scanf("%d", &mh.maMh);

                printf("\nTen mat hang: ");
                scanf("%s", &mh.tenMh);

                Insert(q, mh);
                break;
            case 2:
                if (!isEmpty(q)) {
                    mh = Remove(q);
                    printf("\nMa hang xuat: Ma: %d Ten: %s", mh.maMh, mh.tenMh);
                } else {
                    printf("\nKho khong con hang");
                }
                break;
            case 3:
                front1 = q.front == MAX_QUEUE - 1 ? 0 : q.front - 1;
                printf("\nMat hang chuan bi xuat: Ma: %d Ten: %s", q.nodes[front1].maMh, q.nodes[front1].tenMh);
                break;
            case 4:
                printf("\nMat hang moi nhap: Ma: %d Ten: %s", q.nodes[front1].maMh, q.nodes[front1].tenMh);
                break;
            case 5:
                printf("\nCac mat hang co trong kho:");
                printf("\n%11s%15s","MA MAT HANG", "TEN MAT HANG");
                Traverse(q);
                break;
            case 6:
                printf("\nBan co chac khong (c/k): ");
                c = getchar();

                if (c == 'c' || c == 'C') {
                    Init(q);
                }
                break;
        }
    } while (choice != 0);
}

void Init(Queue &q) {
    q.front = q.rear = MAX_QUEUE - 1;
}
int isEmpty(Queue q) {
    return q.front == q.rear ? 1 : 0;
}
void Insert(Queue &q, MatHang x) {
    if (q.rear = MAX_QUEUE - 1) {
        q.rear = 0;
    } else {
        q.rear++;
    }

    if (q.rear == q.front) {
        printf("Queue is full");
    } else {
        q.nodes[q.rear] = x;
    }
}
MatHang Remove(Queue &q) {
    if (isEmpty(q)) {
        printf("Kho trong");
    } else {
        if (q.front == MAX_QUEUE - 1) q.front = 0;
        else {
            q.front++;
        }
    }
    return q.nodes[q.front];
}
void Traverse(Queue q) {
    int i;
    if (isEmpty(q)) {
        printf("Kho trong");
        return;
    }

    i = q.front == MAX_QUEUE -1 ? 0 : q.front + 1;

    while (i != q.rear) {
        printf("\n%11d%15s", q.nodes[i].maMh, q.nodes[i].tenMh);
    }
}
