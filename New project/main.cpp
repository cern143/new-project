#include "C:\Users\nguye\Desktop\New project\include\classHd.h"
#include "C:\Users\nguye\Desktop\New project\include\date.h"
#include "C:\Users\nguye\Desktop\New project\include\ftxt.h"
#include "C:\Users\nguye\Desktop\New project\include\str.h"
#include "C:\Users\nguye\Desktop\New project\include\vectorHd.h"

void searchHdMenu(vector<Hopdong *> v, vector<int> &rank, vector<Hd_ngay> hd1, vector<Hd_thang> hd2)
{
    int choice1, choice2;
    string hoten, loaixe, bienso;
    ifstream file;
    //cin >> choice1;
    switch (choice1)
    {
    case 1:
        readHd(v, hd1);
        break;
    case 2:
        readHd(v, hd2);
        break;
    }
    //cout << "Nhap phuong thuc ban chon: ";
    //cin >> choice2;
    switch (choice2)
    {
    case 1:
        cout << "Nhap ten chu xe: ";
        getline(cin, hoten);
        searchHd(v, hoten, rank, 1);
        break;
    case 2:
        cout << "Nhap bien so xe: ";
        getline(cin, bienso);
        searchHd(v, bienso, rank, 2);
        break;
    case 3:
        cout << "Nhap loai xe: ";
        getline(cin, loaixe);
        searchHd(v, loaixe, rank, 3);
        break;
    }
}

void menu1()
{
    int choice;
    char ch = 'c';
    Hopdong *p;
    //while (ch == 'c')
    {
        //cin >> choice;
        if (choice == 1)
        {
            Hd_ngay hd1;
            p = &hd1;
            p->getdata();
            p->savetofile();
            //cout << "Tao hop dong thanh cong!";
            //cout << "\nBien so xe la: " << hd1.bienso << "\n";
        }
        if (choice == 2)
        {
            Hd_thang hd2;
            p = &hd2;
            p->savetofile();
            //cout << "Tao hop dong thanh cong!";
            //cout << "\nBien so xe la: " << hd2.bienso << "\n";
        }
    }
}

void menu3(vector<Hopdong *> v, vector<int> rank, vector<Hd_ngay> hd1, vector<Hd_thang> hd2)
{
    char ch = 'c';
    while (ch == 'c')
    {
        system("cls");
        searchHdMenu(v, rank, hd1, hd2);
        changeHd(v, rank);
        cout << "Ban co muon tiep tuc xoa hop dong khong (c/k) ?" << endl;
        cout << "Nhap c (co) hoac k (khong): ";
        ch = getc(stdin);
    }
}

void menu4(vector<Hopdong *> v, vector<int> rank, vector<Hd_ngay> hd1, vector<Hd_thang> hd2)
{
    char ch = 'c';
    while (ch == 'c')
    {
        system("cls");
        searchHdMenu(v, rank, hd1, hd2);
        cout << "Ban co muon tiep tuc tim kiem hop dong khong (c/k) ?" << endl;
        cout << "Nhap c (co) hoac k (khong): ";
        ch = getc(stdin);
    }
}
void menu7()
{
    ofstream file;
    file.open("xe.txt", ios::app);
        Xe xe;
        xe.savetofile();
        //cout << "Them xe thanh cong!\n";
    file.close();
}

void mainmenu()
{
    vector<int> rank;
    Hd_ngay hd1;
    Hd_thang hd2;
    vector<Hd_ngay> v1;
    vector<Hd_thang> v2;
    int choice;
    bool flag = true;
    while (flag)
    {
        system("cls");
        //cout << "Chon thao tac ban muon thuc hien:\n ";
        //cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
            system("cls");
            menu1();
            rank.clear();
            v1.clear();
            v2.clear();
            break;
        case 2:
            system("cls");
            cout << "Tim kiem hop dong can sua:\n";
            searchHdMenu(v, rank, hd1, hd2);
            rank.clear();
            v.clear();
            break;
        case 4:
            menu4(v, rank, hd1, hd2);
            rank.clear();
            v.clear();
            break;
        case 7:
            system("cls");
            menu7();
            break;
        case 0:
            exit(0);
        }
    }
}

int main()
{
    mainmenu();
}