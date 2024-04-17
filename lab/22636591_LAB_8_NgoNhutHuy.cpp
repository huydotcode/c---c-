#include<stdio.h>

struct Node {
	Node *pLeft;
	Node *pRight;
	int idata;
};
typedef Node* Tree;

Node* TaoNode(int X) {
	Node *p = new Node;
	if (p == NULL) return NULL;
	p->pLeft = NULL;
	p->pRight = NULL;
	p->idata = X;
	return p;
}

void ThemNodeVaoCay (Node *p, Tree &c) {
	if (c == NULL) {
		c = p;
	} else {
		if ( p->idata < c->idata ) {
			ThemNodeVaoCay(p, c->pLeft);
		} else if ( p->idata > c->idata) {
			ThemNodeVaoCay(p, c->pRight);
		} else {
			return;
		}
	}
}

void Nhap(Tree &c) {
	int chon;
	do {
		int x;
		printf("Nhap x: ");
		scanf("%d", &x);
		Node *p = TaoNode(x);
		ThemNodeVaoCay(p, c);
		printf("Nhap 0 de thoat");
		scanf("%d", &chon);
	} while (chon != 0);
}

void Xuat (Tree c) {
	if (c != NULL) {
		if (c->pLeft != NULL) {
			Xuat(c->pLeft);
		}
		printf("%4d", c->idata);
		if (c->pRight != NULL) {
			Xuat(c->pRight);
		}
	}
}

int main() {
	Tree c = NULL;
	Nhap(c);
	printf("Xuat cay LNR (Tang dan): ");
	Xuat(c);
	return 0;
}
