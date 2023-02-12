#include "C:\Users\nguye\Desktop\New project\include\ftxt.h"
using namespace std;
void txt_extract(string &destination, const string spare, const string filename)
{
    /**
     * Remove s spare within a line in a text file named filename, then extract that line to destination
     */
    ifstream file;
    file.open(filename);
    ofstream ftemp("temp.txt");
    if (file.is_open())
    {
        string temp;
        bool flag = true;
        while (!file.eof())
        {
            getline(file, temp);
            if (flag == true)
            {
                deletesubstr(temp, spare);
                destination = temp;
                flag = false;
            }
            else
            {
                ftemp << temp << "\n";
            }
        }
        file.close();
        ftemp.close();
        remove(filename.c_str());
        rename("temp.txt", filename.c_str());
    }
    else
    {
        cout << "File du lieu xe bi loi!";
        exit(1);
    }
}

void update_price() {
    int choice;
    string temp, unchange, newprice;
    ifstream file("price.txt"); 
    ofstream ftemp("temp.txt");
    cout << "Chon loai hop dong can cap nhat gia:\n";
    cout << "1. Hop dong ngay\n";
    cout << "2. Hop dong thang\n";
    cout << "Lua chon cua ban: "; fflush(stdin); cin >> choice;
    switch (choice) {
        case 1:
        if ( file.is_open() ) {
            while ( !file.eof() ) {
                getline(file, temp);
                if( (temp.find("monthly price: ")) != string::npos ){
                unchange = temp;
                }
            }
        }
        else {
            cout << "File du lieu gia bi loi!";
        }
        cout << "Nhap gia thue ngay moi: "; getline(cin, newprice);
        ftemp << "daily price: " << newprice;
        ftemp << unchange;
        break;
        case 2:
        if ( file.is_open() ) {
            while ( !file.eof() ) {
                getline(file, temp);
                if( (temp.find("daily price: ")) != string::npos ){
                unchange = temp;
                }
            }
        }
        else {
            cout << "File du lieu gia bi loi!";
        }
        cout << "Nhap gia thue ngay moi: "; getline(cin, newprice);
        ftemp << unchange;
        ftemp << "monthly price: " << newprice;
        break;
    }
}