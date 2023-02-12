#include "C:\Users\nguye\Desktop\New project\include\vectorHd.h"
using namespace std;
void readHd(vector<Hopdong> &v, int mode) {
    if (mode == 1) {
        ifstream file("hdngay.txt");
        if (file.is_open()) {
            int i = 0;
            while (!file.eof()) {
                v.push_back(Hd_ngay(file));
                i++;
            }
        }
        else {
            //cout << "File du lieu hop dong bi loi!";
        }
        file.close();
    }
    if (mode == 2) {
        ifstream file("hdthang.txt");
        if (file.is_open()) {
            int i = 0;
            while (!file.eof()) {
                v.push_back(Hd_thang(file));
                i++;
            }
        }
        else {
            //cout << "File du lieu hop dong bi loi!";
        }
        file.close();
    }
}

void searchHd(vector<Hopdong> &v, string s, vector<int> &rank, int mode) {
    //cout << "Ket qua tim kiem: \n";
    switch (mode) {
    case 1:
        for (int i = 0; i < v.size(); i++)
        {
            if ((v.at(i).hoten.find(s)) != string::npos)
            {
                rank.push_back(i);
                //cout << rank.size() + 1 << "\n";
                v.at(i).show();
            }
        }
        break;
    case 2:
        for (int i = 0; i < v.size(); i++)
        {
            if ((v.at(i).bienso.find(s)) != string::npos)
            {
                rank.push_back(i);
                //cout << rank.size() + 1 << "\n";
                v.at(i).show();
            }
        }
        break;
    case 3:
        for (int i = 0; i < v.size(); i++)
        {
            if ((v.at(i).loaixe.find(s)) != string::npos)
            {
                rank.push_back(i);
                //cout << rank.size() + 1 << "\n";
                v.at(i).show();
            }
        }
        break;
    }
}

void changeHd(vector<Hopdong> &v, vector<int> &rank)
{
    int stt;
    //cout << "Chon hop dong ban muon sua (Nhap so thu tu hien thi cua hop dong):\n";
    //cout << "Lua chon cua ban: ";
    //cin >> stt;
    v.at(rank.at(stt - 1)).getdata();
    cout << "Sua hop dong thanh cong!";
}

void deleteHd(vector<Hopdong> &v, vector<int> &rank)
{
    int stt;
    //cout << "Chon hop dong ban muon xoa (Nhap so thu tu hien thi cua hop dong):\n";
    //cout << "Lua chon cua ban: ";
    //cin >> stt;
    v.erase(v.begin() + rank.at(stt - 1));
    //cout << "Xoa hop dong thanh cong!";
}

unsigned int sum(vector<Hopdong*> v, struct tm start_time, struct tm end_time) {
    unsigned int sum;
    time_t x = mktime(&start_time);
    time_t y = mktime(&end_time);
    for ( int i = 0; i < v.size(); i++ ) {
        if ( x <=  mktime(&(v.at(i)->start_time)) && mktime(&(v.at(i)->end_time)) <= y ) {
            sum = sum + v.at(i)->cost();
        }
    }
}