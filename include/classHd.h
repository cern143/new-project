#pragma once
#include "ftxt.h"
#include "date.h"
using namespace std;

class Hopdong {
public:
    string hoten, cmt, loaixe, bienso;
    unsigned int price;
    struct tm start_time, end_time;
    Hopdong();
    virtual unsigned int cost() = 0;
    virtual void savetofile() = 0;
    virtual void getdata() = 0;
    void getbienso();
    virtual void getprice() = 0; 
    virtual void show() = 0;
};

class Hd_ngay : public Hopdong
{
public:
    Hd_ngay();
    ~Hd_ngay();
    Hd_ngay(istream &source);
    virtual unsigned int cost();
    virtual void savetofile();
    virtual void getdata();
    virtual void getprice(); 
    virtual void show();
};

class Hd_thang : public Hopdong
{
public:
    Hd_thang();
    ~Hd_thang();
    Hd_thang(istream &source);
    virtual unsigned int cost();
    virtual void savetofile();
    virtual void getdata();
    virtual void getprice(); 
    virtual void show();
};

class Xe {
public:
    string loaixe, bienso;
    Xe();
    void savetofile();
};