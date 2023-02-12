#include "C:\Users\nguye\Desktop\New project\include\classHd.h"
using namespace std;

Hopdong::Hopdong() {}

void Hopdong::getbienso() {
        txt_extract(bienso, loaixe, "xe.txt");
}

class Hd_ngay : public Hopdong
{
public:
    Hd_ngay() {}
    ~Hd_ngay() {
        delete this;
    }
    Hd_ngay(istream &source) {
        getline(source, this->hoten);
        getline(source, this->cmt);
        getline(source, this->loaixe);
        getline(source, this->bienso);
        getline(source, (string&)this->price);
        getline(source, (string&)this->start_time.tm_mday);
        getline(source, (string&)this->start_time.tm_mon);
        getline(source, (string&)this->start_time.tm_year);
        getline(source, (string&)this->end_time.tm_mday);
        getline(source, (string&)this->end_time.tm_mon);
        getline(source, (string&)this->end_time.tm_year);
    }
    virtual void savetofile() {
        ofstream file;
        file.open("hdngay.txt", ios::app);
        file << hoten << "\n";
        file << cmt << "\n";
        file << loaixe << "\n";
        file << bienso << "\n";
        file << cost << "\n";
        file << start_time.tm_mday << "\n";
        file << start_time.tm_mon << "\n";
        file << start_time.tm_year << "\n";
        file << end_time.tm_mday << "\n";
        file << end_time.tm_mon << "\n";
        file << end_time.tm_year << "\n";
        file.close();
    }
    virtual void getdata() {
        fflush(stdin);
        //getline(cin, hoten);
        //getline(cin, cmt);
        //cin.ignore();
        //cout << "Nhap loai xe: ";
        //getline(cin, loaixe);
        //cin.ignore();
        deletesubstr(loaixe, " ");
        lowerstr(loaixe);
        getbienso();
        //cin >> start_time.tm_mon;
        //cout << "nam: ";
        //cin >> start_time.tm_year;
        //cout << "den\n";
        //cout << "ngay: ";
        //cin >> end_time.tm_mday;
        //cout << "thang: ";
        //cin >> end_time.tm_mon;
        //cout << "nam: ";
        //cin >> end_time.tm_year;
    }
    virtual void getprice() {
        ifstream file("price.txt");
        string temp;
        while ( !file.eof() ) {
            getline(file, temp);
            if( (temp.find("daily cost: ")) != string::npos ){
                deletesubstr(temp, "daily cost: ");
                price = str_toint(temp);
            }
        }
    }
    virtual unsigned int cost() {
        unsigned int cost;
        cost = diffdays(start_time, end_time) * cost;
        return cost;
    }
    virtual void show() {
        cout << "Ho ten nguoi thue: " << hoten << "\n";
        cout << "So CMT nguoi thue: " << cmt << "\n";
        cout << "Loai xe: " << loaixe << "\n";
        cout << "Bat dau thue tu:\n";
        cout << "ngay: " << start_time.tm_mday << "\n";
        cout << "thang: " << start_time.tm_mon << "\n";
        cout << "nam: " << start_time.tm_year << "\n";
        cout << "den\n";
        cout << "ngay: " << end_time.tm_mday << "\n";
        cout << "thang: " << end_time.tm_mon << "\n";
        cout << "nam: " << end_time.tm_year;
    }
};

class Hd_thang : public Hopdong
{
public:
    Hd_thang() {
    }
    ~Hd_thang() {
        delete this;
    }
    Hd_thang(istream &source)
    {
        getline(source, this->hoten);
        getline(source, this->cmt);
        getline(source, this->loaixe);
        getline(source, this->bienso);
        getline(source, (string&)this->start_time.tm_mon);
        getline(source, (string&)this->start_time.tm_year);
        getline(source, (string&)this->end_time.tm_mon);
        getline(source, (string&)this->end_time.tm_year);
    }
    virtual unsigned int cost()
    {
        unsigned int cost;
        cost = diffmonths(start_time, end_time) * price + 1000000;
        return cost;
    }
    virtual void savetofile()
    {
        ofstream file;
        file.open("hdngay.txt", ios::app);
        file << hoten << "\n";
        file << cmt << "\n";
        file << loaixe << "\n";
        file << bienso << "\n";
        file << start_time.tm_mon << "\n";
        file << start_time.tm_year << "\n";
        file.close();
    }
    virtual void getdata()
    {
        fflush(stdin);
        cout << "Nhap ho ten nguoi thue: ";
        getline(cin, hoten);
        cin.ignore();
        cout << "Nhap so CMT nguoi thue: ";
        getline(cin, cmt);
        cin.ignore();
        cout << "Nhap loai xe: ";
        getline(cin, loaixe);
        cin.ignore();
        deletesubstr(loaixe, " ");
        lowerstr(loaixe);
        txt_extract(bienso, loaixe, "xe.txt");
        getprice();
        cout << "Bat dau thue tu:\n";
        cout << "thang: ";
        string a,b,c,d;
        cin >> start_time.tm_mon;
        cout << "nam: ";
        cin >> start_time.tm_year;
        cout << "den\n";
        cout << "thang: ";
        cin >> end_time.tm_mon;
        cout << "nam: ";
        cin >> end_time.tm_year;
    }
    virtual void getprice() {
        ifstream file("cost.txt");
        string temp;
        while ( !file.eof() ) {
            getline(file, temp);
            if( (temp.find("monthly cost: ")) != string::npos ){
                deletesubstr(temp, "monthly cost: ");
                price = str_toint(temp);
            }
        }
    }
    virtual void show()
    {
        cout << "Ho ten nguoi thue: " << hoten << "\n";
        cout << "So CMT nguoi thue: " << cmt << "\n";
        cout << "Loai xe: " << loaixe << "\n";
        cout << "Bat dau thue tu:\n";
        cout << "thang: " << start_time.tm_mon << "\n";
        cout << "nam: " << start_time.tm_year << "\n";
        cout << "den\n";
        cout << "thang: " << end_time.tm_mon << "\n";
        cout << "nam: " << end_time.tm_year;
    }
};

class Xe {
public:
    string loaixe, bienso;
    Xe()
    {
        fflush(stdin);
        getline(cin, loaixe);
        deletesubstr(loaixe, " ");
        lowerstr(loaixe);
        getline(cin, bienso);
        deletesubstr(bienso, " ");
        upperstr(bienso);
        savetofile();
    }
    void savetofile()
    {
        ofstream file;
        file.open("xe.txt", ios::app);
        file << loaixe << " " << bienso << "\n";
        file.close();
    }
};

