#include<stdio.h>

struct Node {
    int data;
    Node* pNext;
    Node* pPrev;
};
struct List {
    Node* head;
    Node* tail;
};

void Init(List &list);
Node* getNode(int x);
int FindNode(List list, Node* node);
void addHead(List &list, Node* new_node);
void InsertFirst(List &list, int x);
void addTail(List &list, Node* new_node);
void InsertLast(List &list, int x);
void addBefore(List &list, Node* q, Node* new_node);
void InsertBefore(List &list, Node* q, int x);
void addAfter(List &list, Node *q, Node* new_node);
void InsertAfter(List &list, Node* q, int x);

void DeleteBefore(List &list, int x);
void DeleteAfter(List &list, int x);

void output(List list);

int main() {
    List list;
    Init(list);

    Node* node = getNode(99);
    addTail(list, node);

    InsertAfter(list, node, 70);

    output(list);
    return 0;
}

void Init(List &list) {
    list.head = list.tail = NULL;
}
Node* getNode(int x) {
    Node* p = new Node();
    if (p == NULL) return NULL;

    p->data = x;
    p->pNext = p->pPrev = NULL;
    return p;
}
int FindNode(List list, Node* node) {
    Node* q = list.head;
    while (q != NULL) {
        if (q->data == node->data)
            return 1;
        q = q->pNext;
    }

    return -1;
}
void addHead(List &list, Node* new_node) {
    if (list.head == NULL) {
        list.head = list.tail = new_node;
    } else {
        new_node->pNext = list.head;
        list.head->pPrev = new_node;
        list.head = new_node;
    }
}
void InsertFirst(List &list, int x) {
    Node* new_node = getNode(x);
    if (new_node == NULL) return;
    addHead(list, new_node);
}
void addTail(List &list, Node* new_node) {
    if (list.head == NULL) {
        list.head = list.tail = new_node;
    } else {
        new_node->pPrev = list.tail;
        list.tail->pNext = new_node;
        list.tail = new_node;
    }
}
void InsertLast(List &list, int x) {
    Node* new_node = getNode(x);
    if (new_node == NULL) return;
    addTail(list, new_node);
}
void addBefore(List &list, Node* q, Node* new_node) {
    if (q != NULL) {
        Node *p = q->pPrev;
        new_node->pNext = q;
        new_node->pPrev = p;
        q->pPrev = new_node;
        if (p != NULL) p->pNext = new_node;
        if (q == list.head) list.head = new_node;
    } else {
        addTail(list, new_node);
    }
}
void InsertBefore(List &list, Node* q, int x) {
    Node* new_node = getNode(x);
    if (new_node == NULL) return;
    addBefore(list, q, new_node);
}
void addAfter(List &list, Node *q, Node* new_node) {
    if (FindNode(list, q) == -1) return;
    if (q != NULL) {
        Node* p = q->pNext;
        new_node->pNext = p;
        new_node->pPrev = q;
        q->pNext = new_node;
        if (p != NULL) p->pPrev = new_node;
        if (q == list.tail) list.tail = new_node;
    } else {
        addHead(list, new_node);
    }
}
void InsertAfter(List &list, Node* q, int x) {
    Node *new_node = getNode(x);
    if (new_node == NULL) return;
    addAfter(list, q, new_node);
}

void DeleteBefore(List &list, int x) {
    Node *tmp = list.head;

    while (tmp != NULL) {
        if (tmp->data == x)
            break;
        tmp = tmp -> pNext;
    }

    if (tmp == NULL) return;


}

void DeleteAfter(List &list, int x);


void output(List list) {
    Node* node = list.head;
    printf("Xuat danh sach\n");
    while (node != NULL) {
        printf("%d\t", node->data);
        node = node->pNext;
    }
}

