#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath> // Thêm thư viện cho phép toán lũy thừa

struct Node {
    float data;
    Node *pNext;
};

struct Stack {
    Node *top;
};

void Init(Stack &stack);
int Empty(Stack stack);
Node* getNode(float x);
void Push(Stack &stack, float x);
float Pop(Stack &stack);
void DocTu(char s[], char tu[], int &vt);
int LaToanTu(char s[]);
float TinhToan(float toanHang1, float toanHang2, char toanTu);
float tinhBieuThuc(Stack &s, char bieuThuc[]) {
    float kq = 0;
    char t[50];
    int i=0;
    do {
        DocTu(bieuThuc, t, i);
        if (LaToanTu(t)) {
            char toanTu = t[0];
            float toanHang2 = Pop(s);
            float toanHang1 = Pop(s);
            kq = TinhToan(toanHang1, toanHang2, toanTu);
            Push(s, kq);
        } else {
            float toanHang = atof(t);
            Push(s, toanHang);
        }

        i++;
    } while (bieuThuc[i] != '#');

    return Pop(s);
}

int main() {
    Stack s;
    Init(s);
    char bieuThuc[100];
    printf("Nhap bieu thuc: ");
    fflush(stdin);
    gets(bieuThuc);
    float kq = tinhBieuThuc(s, bieuThuc);
    printf("Gia tri cua bieu thuc: %f\n", kq);
    return 0;
}

void Init(Stack &stack) {
    stack.top = NULL;
}

int Empty(Stack stack) {
    return stack.top == NULL ? 1 : 0;
}

Node* getNode(float x) {
    Node *p = new Node;
    p->data = x;
    p->pNext = nullptr;
    return p;
}

void Push(Stack &stack, float x) {
    Node *new_node = getNode(x);
    new_node->pNext = stack.top;
    stack.top = new_node;
}

float Pop(Stack &stack) {
    float x = 0;
    if (!Empty(stack)) {
        Node *p = stack.top;
        stack.top = stack.top->pNext;
        x = p->data;
        delete p;
    }
    return x;
}

void DocTu(char s[], char tu[], int &vt) {
    for (int i = 0; i < strlen(tu); i++) {
        tu[i] = ' ';
    }

    int i = 0;
    while (s[vt] != ' ' && s[vt] != '\0') {
        tu[i] = s[vt];
        vt++;
        i++;
    }
}

int LaToanTu(char s[]) {
    char c = s[0];
    if ((c == '+') || (c == '-') || (c == '*') || (c == '/') || (c == '^')) {
        return 1;
    }
    return 0;
}

float TinhToan(float toanHang1, float toanHang2, char toanTu) {
    float kq;
    switch (toanTu) {
        case '+': kq = toanHang1 + toanHang2; break;
        case '-': kq = toanHang1 - toanHang2; break;
        case '*': kq = toanHang1 * toanHang2; break;
        case '/': kq = toanHang1 / toanHang2; break;
        case '^': kq = pow(toanHang1, toanHang2); break; // Xử lý phép lũy thừa
    }
    return kq;
}
