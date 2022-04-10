#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;
struct SinhVien
{
    int mssv;
    string ht;
    string ml;
    double dtb;
};
void standardstring(string &a)
{
    int i = 0;
    while (a[i] == ' ')
    {
        a.erase(0, 1);
        i++;
    }
    i = a.size() - 1;
    while (a[i] == ' ')
    {
        a.erase(i, 1);
        i--;
    }
    for (int i = 1; i < a.size() - 1; i++)
    {
        if (a[i] == ' ' and a[i + 1] == ' ')
        {
            a.erase(i, 1);
            i--;
        }
    }
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] >= 'A' and a[i] <= 'Z')
            a[i] += 32;
        if (a[i - 1] == ' ')
            a[i] -= 32;
    }
    a[0] -= 32;
}
void NhapSV(SinhVien *&sv, int &n)
{
    do
    {
        cout << "Nhap so luong sinh vien: ";
        cin >> n;
        if (n > 50 or n <= 0)
        {
            system("cls");
            cout << "Nhap loi! Nhap lai! (1-50)";
            getch();
            system("cls");
        }
    } while (n > 50 or n <= 0);
    sv = new SinhVien[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap ma so sinh vien cua sinh vien thu " << i + 1 << ": ";
        cin >> sv[i].mssv;
        cout << "Nhap ho ten cua sinh vien thu " << i + 1 << ": ";
        cin.ignore();
        getline(cin, sv[i].ht);
        standardstring(sv[i].ht);
        cout << "Nhap ma lop cua sinh vien thu " << i + 1 << ": ";
        getline(cin, sv[i].ml);
        cout << "Nhap diem trung binh cua sinh vien thu " << i + 1 << ": ";
        cin >> sv[i].dtb;
        if (i < n - 1)
            cout << "-----------------------------------------" << endl;
    }
}
void XuatSV(SinhVien *sv, int n)
{
    cout << left << setw(5) << "STT"
         << setw(10) << "MSSV"
         << setw(20) << "Ho ten"
         << setw(13) << "Ma lop"
         << setw(3) << "DTB" << endl;
    for (int i = 0; i < n; i++)
        cout << setw(5) << i + 1 << setw(10) << sv[i].mssv << setw(20) << sv[i].ht << setw(13) << sv[i].ml << sv[i].dtb << endl;
}
void Xuat1SV(SinhVien *sv, int n)
{
    cout << left << setw(5) << "STT"
         << setw(10) << "MSSV"
         << setw(20) << "Ho ten"
         << setw(13) << "Ma lop"
         << setw(3) << "DTB" << endl;
    cout << setw(5) << n << setw(10) << sv[n - 1].mssv << setw(20) << sv[n - 1].ht << setw(13) << sv[n - 1].ml << sv[n - 1].dtb << endl;
}
int DemSVml(SinhVien *sv, int n, string x)
{
    int dem = 0;
    for (int i = 0; i < n; i++)
        if (sv[i].ml == x)
            dem++;
    return dem;
}
int DemSVdtb(SinhVien *sv, int n, int x)
{
    int dem = 0;
    for (int i = 0; i < n; i++)
        if (sv[i].dtb >= x)
            dem++;
    return dem;
}
void HoanviSV(SinhVien &sv1, SinhVien &sv2)
{
    SinhVien temp = sv1;
    sv1 = sv2;
    sv2 = temp;
}
void SortSVmaxtomin(SinhVien *&sv, int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i; j < n; j++)
            if (sv[i].dtb < sv[j].dtb)
                HoanviSV(sv[i], sv[j]);
}
void SortSVmintomax(SinhVien *&sv, int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i; j < n; j++)
            if (sv[i].dtb > sv[j].dtb)
                HoanviSV(sv[i], sv[j]);
}
void SortSV(SinhVien *&sv, int n)
{
    int x;
    do
    {
        cout << "1.Sap xep tu cao xuong thap" << endl;
        cout << "2.Sap xep tu thap len cao" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> x;
        if (x > 2 and x < 1)
        {
            system("cls");
            cout << "Nhap loi! Nhap lai! (1-2)";
            getch();
            system("cls");
        }
    } while (x > 2 and x < 1);
    switch (x)
    {
    case 1:
    {
        SortSVmaxtomin(sv, n);
        cout << "Da sap xep xong!";
        break;
    }
    case 2:
    {
        SortSVmintomax(sv, n);
        cout << "Da sap xep xong!";
        break;
    }
    }
}
void UpdateSV(SinhVien *&sv, int n)
{
    int x, chon;
    cout << "Nhap STT sinh vien can cap nhat: ";
    cin >> x;
    Xuat1SV(sv, x);
    cout << endl;
    cout << "1.Sua MSSV" << endl;
    cout << "2.Sua ho ten sinh vien" << endl;
    cout << "3.Sua ma lop sinh vien" << endl;
    cout << "4.Sua diem trung binh cua sinh vien" << endl;
    cout << "Chon thong tin can sua (1-4): ";
    cin >> chon;
    switch (chon)
    {
    case 1:
    {
        cout << "Nhap MSSV: ";
        cin >> sv[x - 1].mssv;
        break;
    }
    case 2:
    {
        cout << "Nhap ho ten sinh vien: ";
        cin.ignore();
        getline(cin, sv[x - 1].ht);
        standardstring(sv[x - 1].ht);
        break;
    }
    case 3:
    {
        cout << "Nhap ma lop sinh vien: ";
        cin.ignore();
        getline(cin, sv[x - 1].ml);
        break;
    }
    case 4:
    {
        cout << "Nhap diem trung binh cua sinh vien: ";
        cin >> sv[x - 1].dtb;
        break;
    }
    default:
    {
        cout << "Nhap loi!";
        break;
    }
    }
}
void DeleteSV(SinhVien *&sv, int &n)
{
    int x;
    cout << "Nhap STT sinh vien can xoa: ";
    cin >> x;
    for (int i = x - 1; i < n - 1; i++)
        sv[i] = sv[i + 1];
    n--;
}
void AddMemory(SinhVien *&sv, int &n)
{
    SinhVien temp[n];
    for (int i = 0; i < n; i++)
        temp[i] = sv[i];
    delete[] sv;
    sv = NULL;
    sv = new SinhVien[n + 1];
    for (int i = 0; i < n; i++)
        sv[i] = temp[i];
    n++;
}
void AddSV(SinhVien *&sv, int &n)
{
    AddMemory(sv, n);
    cout << "Nhap MSSV: ";
    cin >> sv[n - 1].mssv;
    cout << "Nhap ho ten sinh vien: ";
    cin.ignore();
    getline(cin, sv[n - 1].ht);
    standardstring(sv[n - 1].ht);
    cout << "Nhap ma lop sinh vien: ";
    getline(cin, sv[n - 1].ml);
    cout << "Nhap diem trung binh sinh vien: ";
    cin >> sv[n - 1].dtb;
}
void CutName(string &a)
{
    int i = a.size(), x = 0;
    while (a[i] != ' ')
    {
        x++;
        i--;
    }
    a = a.substr(a.size() - x + 1, x);
}
void Findname(SinhVien *sv, int n)
{
    SinhVien name[50];
    string temp[50];
    string Name;
    int x = 0;
    cout << "Nhap ten can tim: ";
    cin.ignore();
    getline(cin, Name);
    standardstring(Name);
    cout << endl;
    for (int i = 0; i < n; i++)
        temp[i] = sv[i].ht;
    for (int i = 0; i < n; i++)
        CutName(temp[i]);
    for (int i = 0; i < n; i++)
        if (temp[i] == Name)
        {
            name[x] = sv[i];
            x++;
        }
    if (x == 0)
        cout << "Khong co sinh vien nao ten " << Name;
    else
        XuatSV(name, x);
}
int main()
{
    system("cls");
    SinhVien *sv;
    int n, choose;
    bool danhap;
    do
    {
        system("cls");
        cout << "-------------------------------------------------------------" << endl;
        cout << "|1.Nhap danh sach sinh vien                                 |" << endl;
        cout << "|2.Xuat danh sach sinh vien                                 |" << endl;
        cout << "|3.Dem so luong sinh vien cung ma lop                       |" << endl;
        cout << "|4.Dem so luong sinh vien co diem trung binh theo yeu cau   |" << endl;
        cout << "|5.Sap xep danh sach sinh vien                              |" << endl;
        cout << "|6.Cap nhat thong tin sinh vien theo yeu cau                |" << endl;
        cout << "|7.Xoa sinh vien                                            |" << endl;
        cout << "|8.Them sinh vien                                           |" << endl;
        cout << "|9.Xuat sinh vien co cung ten                               |" << endl;
        cout << "|10.Thoat                                                   |" << endl;
        cout << "-------------------------------------------------------------" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> choose;
        system("cls");
        switch (choose)
        {
        case 1:
        {
            NhapSV(sv, n);
            danhap = true;
            getch();
            break;
        }
        case 2:
        {
            if (danhap == true)
                XuatSV(sv, n);
            else
                cout << "Chua nhap danh sach sinh vien!";
            getch();
            break;
        }
        case 3:
        {
            if (danhap)
            {
                string x;
                cout << "Nhap ma lop sinh vien: ";
                cin.ignore();
                getline(cin, x);
                cout << "So sinh vien cung ma lop la: " << DemSVml(sv, n, x);
            }
            else
                cout << "Chua nhap danh sach sinh vien!";
            getch();
            break;
        }
        case 4:
        {
            if (danhap)
            {
                int x;
                cout << "Nhap so diem can kiem tra: ";
                cin >> x;
                cout << "So sinh vien co so diem tu " << x << " tro len la: " << DemSVdtb(sv, n, x);
            }
            else
                cout << "Chua nhap danh sach sinh vien!";
            getch();
            break;
        }
        case 5:
        {
            if (danhap)
                SortSV(sv, n);
            else
                cout << "Chua nhap danh sach sinh vien!";
            getch();
            break;
        }
        case 6:
        {
            if (danhap)
                UpdateSV(sv, n);
            else
                cout << "Chua nhap danh sach sinh vien!";
            getch();
            break;
        }
        case 7:
        {
            if (danhap)
            {
                DeleteSV(sv, n);
                cout << "Da xoa sinh vien!";
            }
            else
                cout << "Chua nhap danh sach sinh vien!";
            getch();
            break;
        }
        case 8:
        {
            if (danhap)
                AddSV(sv, n);
            else
                cout << "Chua nhap danh sach sinh vien!";
            getch();
            break;
        }
        case 9:
        {
            if (danhap)
                Findname(sv, n);
            else
                cout << "Chua nhap danh sach sinh vien!";
            getch();
            break;
        }
        case 10:
            break;
        default:
        {
            cout << "Loi! Nhap lai!";
            getch();
            break;
        }
        }
    } while (choose != 10);
}