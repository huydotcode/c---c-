#include <cstdio>
#include <cstring>

struct SinhVien {
    char masv[20];
    char name[20];
    double diem;
};

struct Node {
    SinhVien data;
    Node *pLeft, *pRight;
};

typedef Node *Tree;

void Init (Tree &c);
Node* TaoNode (SinhVien sv);
int ThemNodeVaoCay(Tree &c, Node* p);
void Nhap (Tree c);
void NhapSV (SinhVien &sv);
void LNR (Tree c);
void XuatSV(SinhVien sv);
int DemSoNutLa(Tree c);
int ChieuCaoCay(Tree c);
Node* TimKiemNode(Tree c, char masv[]);
Node* TimNodeTheMang(Node* &p);
void DuyetCayVaLuuVaoMang(Tree c, SinhVien mang[], int &index);
void SapXepMang(SinhVien mang[], int n);
void XayDungCayTuMang(Tree &c, SinhVien mang[], int left, int right);
void SapXepCay(Tree &c);


int XoaNode(Tree &c, char masv[]);

int main() {
    Tree c;
    Init(c);
    Nhap(c);
    LNR(c);
    return 0;
}

void Init (Tree &c) {
    c = nullptr;
}
Node* TaoNode (SinhVien sv) {
    Node* p = new Node;
    if (p == nullptr) return NULL;
    p->data = sv;
    p->pLeft = p->pRight = NULL;
    return p;
}
int ThemNodeVaoCay(Tree &c, Node* p) {
    if (c) {
        if (strcmpi(c->data.masv, p->data.masv) == 0) return 0;
        if (strcmpi(c->data.masv, p->data.masv) > 0) {
            ThemNodeVaoCay(c->pLeft, p);
        } else {
            ThemNodeVaoCay(c->pRight, p);
        }
    }

    c = new Node;
    if (c == nullptr) return -1;
    c->data = p->data;
    c->pLeft = c->pRight = nullptr;
    return 1;
}
void Nhap (Tree c) {
    int chon = -1;
    do {
        SinhVien sv;
        NhapSV(sv);
        Node* p = TaoNode(sv);
        ThemNodeVaoCay(c, p);
        printf("Nhap 0 de thoat: ");
        scanf("%d", &chon);
    } while (chon != 0);
}
void NhapSV (SinhVien &sv) {
    printf("Nhap ma sv: ");
    fflush(stdin);
    gets(sv.masv);

    printf("Nhap ten sv: ");
    fflush(stdin);
    gets(sv.name);

    printf("Nhap diem: ");
    fflush(stdin);
    scanf("%lf", &sv.diem);
}
void LNR (Tree c) {
    if (c) {
        LNR(c->pLeft);
        XuatSV(c->data);
        LNR(c->pRight);
    }
}
void XuatSV(SinhVien sv) {
    printf("Sinh vien%s %s %lf\n", sv.masv, sv.name, sv.diem);
}
int DemSoNutLa(Tree c) {
    if (c == nullptr) return 0;
    if (c->pLeft == nullptr && c->pRight == nullptr) return 1;
    return DemSoNutLa(c->pLeft) + DemSoNutLa(c->pRight);
}
int ChieuCaoCay(Tree c) {
    if (c == nullptr) return 0;
    int chieuCaoBenTrai = ChieuCaoCay(c->pLeft);
    int chieuCaoBenPhai = ChieuCaoCay(c->pRight);
    return (chieuCaoBenTrai > chieuCaoBenPhai) ? chieuCaoBenTrai + 1 : chieuCaoBenPhai + 1;
}
Node* TimKiemNode(Tree c, char masv[]) {
    // TODO: Tìm kiếm một Node có giá trị được nhập từ bàn phím
    if (c == nullptr || strcmpi(c->data.masv, masv) == 0) return c;
    if (strcmpi(c->data.masv, masv) > 0) {
        return TimKiemNode(c->pLeft, masv);
    } else {
        return TimKiemNode(c->pRight, masv);
    }
}
int XoaNode(Tree &c, char masv[]) {
    // TODO: Xóa một Node có giá trị được nhập từ bàn phím
    if (c == nullptr) return 0;

    if (strcmpi(c->data.masv, masv) > 0) {
        return XoaNode(c->pLeft, masv);
    } else if (strcmpi(c->data.masv, masv) < 0) {
        return XoaNode(c->pRight, masv);
    } else {
        Node* p = c;
        if (c->pLeft == nullptr) {
            c = c->pRight;
            delete p;
        } else if (c->pRight == nullptr) {
            c = c->pLeft;
            delete p;
        } else {
            Node* theMang = TimNodeTheMang(c->pRight);
            c->data = theMang->data;
            XoaNode(c->pRight, theMang->data.masv);
        }
        return 1;
    }
}
Node* TimNodeTheMang(Node* &p) {
    // Tìm Node có giá trị nhỏ nhất (trái nhất) trong cây con phải
    if (p->pLeft == nullptr) return p;
    return TimNodeTheMang(p->pLeft);
}
void DuyetCayVaLuuVaoMang(Tree c, SinhVien mang[], int &index) {
    if (c) {
        DuyetCayVaLuuVaoMang(c->pLeft, mang, index);
        mang[index++] = c->data;
        DuyetCayVaLuuVaoMang(c->pRight, mang, index);
    }
}
void SapXepMang(SinhVien mang[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmpi(mang[j].masv, mang[j + 1].masv) > 0) {
                // Hoán đổi hai phần tử nếu thứ tự sai
                SinhVien temp = mang[j];
                mang[j] = mang[j + 1];
                mang[j + 1] = temp;
            }
        }
    }
}
void XayDungCayTuMang(Tree &c, SinhVien mang[], int left, int right) {
    if (left > right) return;

    int mid = (left + right) / 2;
    ThemNodeVaoCay(c, TaoNode(mang[mid]));

    XayDungCayTuMang(c, mang, left, mid - 1);
    XayDungCayTuMang(c, mang, mid + 1, right);
}
void SapXepCay(Tree &c) {
    int soLuongSV = DemSoNutLa(c);
    if (soLuongSV <= 1) return;

    SinhVien *mang = new SinhVien[soLuongSV];
    int index = 0;

    // Duyệt cây và lưu dữ liệu vào mảng
    DuyetCayVaLuuVaoMang(c, mang, index);

    // Sắp xếp mảng theo trường masv
    SapXepMang(mang, soLuongSV);

    // Xây dựng lại cây từ mảng đã sắp xếp
    XayDungCayTuMang(c, mang, 0, soLuongSV - 1);

    delete[] mang;
}

