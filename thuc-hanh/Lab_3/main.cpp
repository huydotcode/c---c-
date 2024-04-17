#include<stdio.h>

struct Node
{
    int    data;
    Node*     pNext;
};

struct List
{
    Node* pHead;
    Node* pTail;
};

void Init(List &L) {
    L.pHead = L.pTail = NULL;
}

Node *getNode(int x) {
    Node *node = new Node;

    if (node == NULL) return NULL;

    node->data = x;
    node->pNext = NULL;
    return node;
}
void addHead(List &list, Node* new_node) {
    if (list.pHead == NULL) {
        list.pHead = list.pTail = new_node;
    } else {
        new_node->pNext = list.pHead;
        list.pHead = new_node;
    }
}

void InsertFirst(List &L, int x) {
    Node* node = getNode(x);
    if (node == NULL) return;

    addHead(L, node);
}

void ShowFirst(List list) {
    printf("%d", list.pHead->data);
}

void addTail(List &list, Node *new_node) {
    if (list.pHead == NULL) {
        list.pHead = list.pTail = new_node;
    } else {
        list.pTail->pNext = new_node;
        list.pTail = new_node;
    }
}

void InsertLast(List &L, int x) {
    Node* node = getNode(x);
    if (node == NULL) return;
    addTail(L, node);
}

void addAfter(List &list, Node* q, Node* new_node) {
    if (q != NULL) {
        new_node -> pNext = q -> pNext;
        q -> pNext = new_node;
        if (q == list.pTail) list.pTail = new_node;
    } else {
        addHead(list, new_node);
    }
}

void InsertAfter(List &list, Node*q, int x) {
    Node *new_node = getNode(x);
    if (new_node == NULL) return;
    addAfter(list, q, new_node);
}

void ShowLast(List list) {
    printf("%d", list.pTail->data);
}

int SumLinkedList(List list) {
    int sum = 0;
    Node *curNode = list.pHead;
    while (curNode != NULL) {
        sum += curNode->data;
        curNode = curNode->pNext;
    }

    return sum;
}

void AppendList(List &list, int arr[5], int n) {
    for (int i=0; i<n; i++) {
        InsertLast(list, arr[i]);
    }
}

int SearchKey(List list, int x) {
    Node *node = list.pHead;

    while (node != NULL) {
        if (node->data == x)
            return 1;

        node = node->pNext;
    }

    return -1;
}

void FindAndInsert(List &list, int x, int y) {
    if (SearchKey(list, x) == 1) {
        Node*node = getNode(x);
        InsertAfter(list, node)
    }
}

int main() {
}


