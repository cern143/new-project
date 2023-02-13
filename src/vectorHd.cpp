#include "../include/vectorHd.h"
using namespace std;
void readHd(vector<Hd_ngay> &v) {
        ifstream file("C:\\hdngay.txt");
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

void readHd(vector<Hd_thang> &v) {
        ifstream file("C:\\hdthang.txt");
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

void searchHd(vector<Hopdong*> v, string s, vector<int> &rank, int mode) {
    //cout << "Ket qua tim kiem: \n";
    switch (mode) {
    case 1:
        for (int i = 0; i < v.size(); i++)
        {
            if ((v.at(i)->hoten.find(s)) != string::npos)
            {
                rank.push_back(i);
                //cout << rank.size() + 1 << "\n";
                v.at(i)->show();
            }
        }
        break;
    case 2:
        for (int i = 0; i < v.size(); i++)
        {
            if ((v.at(i)->bienso.find(s)) != string::npos)
            {
                rank.push_back(i);
                //cout << rank.size() + 1 << "\n";
                v.at(i)->show();
            }
        }
        break;
    case 3:
        for (int i = 0; i < v.size(); i++)
        {
            if ((v.at(i)->loaixe.find(s)) != string::npos)
            {
                rank.push_back(i);
                //cout << rank.size() + 1 << "\n";
                v.at(i)->show();
            }
        }
        break;
    }
}

void changeHd(vector<Hopdong*> &v, vector<int> &rank) {
    int stt;
    //cout << "Chon hop dong ban muon sua (Nhap so thu tu hien thi cua hop dong):\n";
    //cout << "Lua chon cua ban: ";
    //cin >> stt;
    v.at(rank.at(stt - 1))->getdata();
    cout << "Sua hop dong thanh cong!";
}

void deleteHd(vector<Hopdong*> &v, int stt)
{
    //cout << "Chon hop dong ban muon xoa (Nhap so thu tu hien thi cua hop dong):\n";
    //cout << "Lua chon cua ban: ";
    //cin >> stt;
    v.erase(v.begin() + stt);
    //cout << "Xoa hop dong thanh cong!";
}

unsigned int cost_sum(vector<Hopdong*> &v, struct tm start_time, struct tm end_time) {
    unsigned int sum = 0;
    start_time.tm_hour = 0;
    start_time.tm_min = 0;
    start_time.tm_sec = 0;
    if (start_time.tm_year > 1900 ) {
        start_time.tm_year = start_time.tm_year - 1900;
    }
    end_time.tm_hour = 0;
    end_time.tm_min = 0;
    end_time.tm_sec = 0;
    if (end_time.tm_year > 1900 ) {
        end_time.tm_year = end_time.tm_year - 1900;
    }
    time_t x = mktime(&start_time);
    time_t y = mktime(&end_time);
    for ( int i = 0; i < v.size(); i++ ) {
        if (v.at(i)->start_time.tm_year > 1900) {
            v.at(i)->start_time.tm_year = v.at(i)->start_time.tm_year - 1900;
        }
        v.at(i)->start_time.tm_hour = 0;
        v.at(i)->start_time.tm_min = 0;
        v.at(i)->start_time.tm_sec = 0;
        if (v.at(i)->end_time.tm_year > 1900) {
            v.at(i)->end_time.tm_year = v.at(i)->end_time.tm_year - 1900;
        }
        v.at(i)->end_time.tm_hour = 0;
        v.at(i)->end_time.tm_min = 0;
        v.at(i)->end_time.tm_sec = 0;
        if ( x <=  mktime(&(v.at(i)->start_time)) && mktime(&(v.at(i)->end_time)) <= y ) {
            cout << v.at(i)->cost();
            sum = sum + v.at(i)->cost();
        }
    }
    return sum;
}

void cost_search(vector<Hopdong*> v, vector<int> &rank, int cost) {
    for ( int i = 0; i < v.size(); i++ ) {
        if ( v.at(i)->cost() > cost ) {
            rank.push_back(i);
            v.at(i)->show();
        }
    }
}

int stt(vector<Hopdong*> v, string hoten) {
    int stt;
    for (int i = 0; i < v.size(); i++)
        {
            if ((v.at(i)->hoten.find(hoten)) != string::npos)
            {
                stt = i;
                return stt;
            }
        }
}
