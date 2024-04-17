#include<stdio.h>
#include<string.h>

struct Ngay {
    int ngay, thang, nam;
};

struct SinhVien {
    char maSV[8];
    char hoTen[50];
    int gioiTinh;
    Ngay ngaySinh;
    char diaChi[100];
    char lop[12];
    char khoa[7];
};

struct Node {
    SinhVien data;
    Node *link;
};

struct List {
    Node *first;
    Node *last;
};

Node *getNode(SinhVien x);
void Init(List &list);
void AddFirst(List &list, Node *new_node);
void InsertFirst(List &list, SinhVien x);
void AddLast(List &list, Node *new_node);
void InsertLast(List &list, SinhVien x);
void AddAfter(List &list, Node *q, Node* new_node);
void InsertAfter(List &list, Node *q, SinhVien sv);
void NhapDSSV(List &list);
int NhapSinhVien(SinhVien &sv);
void XuatSinhVien(SinhVien sv);
void XuatDSSV(List list);
int InsertFirst_KhongTrung(List &list, SinhVien sv);
Node* Search(List list, char maSv[]);
int RemoveHead(List &list);
Node* TimXoa(List list, char x[]);
int RemoveAfter(List &list, Node *q);
int XoaSinhVien(List &list, char x[]);
void InterchangeSort(List &list);
void Swap(SinhVien &sv1, SinhVien &sv2);
Node *TimThem(List list, SinhVien sv);
void ThemCoThuTu(List &list, SinhVien sv);
int ThemCoThuTu_KhongTrungMa(List &list, SinhVien sv);

int main() {
    List l;
    Init(l);
    SinhVien sv;
    NhapDSSV(l);
    XuatDSSV(l);
    return 0;
}

Node *getNode(SinhVien x) {
    Node *p = new Node;
    p->data = x;
    p->link = NULL;

    return p;
}
void Init(List &list) {
    list.first = list.last = NULL;
}
void AddLast(List &list, Node *new_node) {
    if (list.last == NULL) list.first = list.last = new_node;
    list.last -> link = new_node;
    list.last = new_node;
}
void InsertLast(List &list, SinhVien x) {
    XuatSinhVien(x);
    Node *new_node = getNode(x);
    AddLast(list, new_node);
}
void NhapDSSV(List &list) {
    printf("\nBat dau nhap DSSV, Nhap MASV = 0 de dung\n");
    SinhVien sv;
    int flag = NhapSinhVien(sv);
    while(flag) {
    	InsertLast(list, sv);
    	flag = NhapSinhVien(sv);
    }
    printf("\nKet thc nhap DSSV");
}
int NhapSinhVien(SinhVien &sv) {
    printf("Ma so sinh vien: ");
    fflush(stdin);
    gets(sv.maSV);

    if (strcmp(sv.maSV, "0") == 0) return 0;
    printf("Ho va ten: ");
    fflush(stdin);
    gets(sv.hoTen);
    printf("Gioi tinh: ");
    fflush(stdin);
    scanf("%d", &sv.gioiTinh);
    printf("Ngay thang nam sinh: ");
    fflush(stdin);
    scanf("%d %d %d", &sv.ngaySinh.ngay,
          &sv.ngaySinh.thang, &sv.ngaySinh.nam);
    printf("Dia chi: ");
    fflush(stdin);
    gets(sv.diaChi);
    printf("Lop: ");
    fflush(stdin);
    gets(sv.lop);
    printf("Khoa: ");
    fflush(stdin);
    gets(sv.khoa);
    return 1;
}
void XuatDSSV(List list) {
    Node *p = list.first;
    while (p != NULL) {
        XuatSinhVien(p->data);
        p = p->link;
    }
}
void XuatSinhVien(SinhVien sv) {
    char gt[4];
    if (sv.gioiTinh == 0) {
    	strcpy(gt, "Nam");
    } else {
    	strcpy(gt, "Nu");
    }
    printf("\n%10s %20s %5d/%d/%d %5s %10s %8s %8s", 
	sv.maSV, sv.hoTen, sv.ngaySinh.ngay, sv.ngaySinh.thang, 
	sv.ngaySinh.nam, gt, sv.diaChi, sv.khoa, sv.lop );
};
int InsertFirst_KhongTrung(List &list, SinhVien sv) {
    if (Search(list, sv.maSV) != NULL) {
        printf("Ma sinh vien trung");
        return 0;
    } else {
        InsertFirst(list, sv);
        return 1;
    }
}
Node* Search(List list, char maSv[]) {
    Node *p = list.first;

    while(p != NULL) {
        if (strcmpi(p->data.maSV, maSv) == 0) {
            return p;
        }
        p = p->link;
    }

    return NULL;
}
void AddFirst(List &list, Node *new_node) {
    if (list.first == NULL) {
        list.first = list.last = new_node;
    } else {
        new_node->link = list.first;
        list.first = new_node;
    }
}
void InsertFirst(List &list, SinhVien x) {
    Node *new_node = getNode(x);
    AddFirst(list, new_node);
}
void AddAfter(List &list, Node *q, Node* new_node) {
    if (q != NULL) {
        new_node->link = q->link;
        q->link = new_node;
        if (q == list.last) list.last = new_node;
    } else {
        AddFirst(list, new_node);
    }
}
void InsertAfter(List &list, Node *q, SinhVien sv) {
    Node *p = getNode(sv);
    if (p == NULL) return;
    AddAfter(list, q, p);
}
int RemoveHead(List &list) {
    if (list.first == NULL) return 0;
    Node *p = list.first;
    list.first = p->link;
    if (list.first == NULL) list.last = NULL;
    delete p;
    return 1;
}
int RemoveAfter(List &list, Node *q) {
    if (q != NULL && q->link != NULL) {
        Node *p = q->link;
        q -> link = p->link;
        if (p == list.last) list.last = q;
        delete p;
        return 1;
    }

    return 0;
}
Node* TimXoa(List list, char x[]) {
    Node *p = list.first;
    while (p != list.last && strcmpi(p->link->data.maSV, x) != 0) {
        p = p->link;
    }

    if (p != list.last) {
        return p;
    } else {
        return NULL;
    }
}
int XoaSinhVien(List &list, char x[]) {
    if (strcmpi(list.first->data.maSV,x) == 0) {
        RemoveHead(list);
    } else {
        Node *q = TimXoa(list, x);
        if (q == NULL) {
            return  0;
        } else {
            RemoveAfter(list, q);
        }
    }

    return 1;
}
void Swap(SinhVien &sv1, SinhVien &sv2) {
    SinhVien temp = sv1;
    sv1 = sv2;
    sv2 = temp;
}
void InterchangeSort(List &list) {
    for (Node* i = list.first; i != list.last; i = i->link) {
        for (Node* j = i->link; j != NULL; j=j->link) {
            if (strcmpi(i->data.hoTen, j->data.hoTen) > 0) {
                Swap(i->data, j->data);
            }
        }
    }

}
Node *TimThem(List list, SinhVien sv) {
    Node *p = list.first;
    while (p != list.last && strcmpi(p->link->data.hoTen, sv.hoTen) < 0) {
        p = p->link;
    }

    return p;
}
void ThemCoThuTu(List &list, SinhVien sv) {
    if (strcmpi(sv.hoTen, list.first->data.hoTen) < 0) {
        InsertFirst(list, sv);
    } else {
        Node *p = TimThem(list, sv);
        InsertAfter(list, p, sv);
    }
}
int ThemCoThuTu_KhongTrungMa(List &list, SinhVien sv) {
    if (strcmpi(sv.maSV, list.first->data.maSV) == 0) return 0;
    if (strcmpi(sv.maSV, list.first->data.maSV) < 0) {
        InsertFirst(list, sv);
        return 1;
    }

    Node *p = TimThem(list, sv);
    if (strcmpi(p->data.maSV, sv.maSV) != 0) {
        InsertAfter(list, p, sv);
        return 1;
    }

    return 0;
}