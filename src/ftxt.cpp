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

void update_price(string newprice, int choice) {
    string temp, unchange;
    ifstream file("price.txt"); 
    ofstream ftemp("temp.txt");
    switch (choice) {
        case 1:
        if ( file.is_open() ) {
            while ( !file.eof() ) {
                getline(file, temp);
                if( (temp.find("daily price: ")) == string::npos ) {
                unchange = temp;
                ftemp << temp;
                }
                else {
                    ftemp << "daily price: " << newprice;
                }
            }
        }
        else {
            //cout << "File du lieu gia bi loi!";
        }
        break;
        case 2:
       if ( file.is_open() ) {
            while ( !file.eof() ) {
                getline(file, temp);
                if( (temp.find("monthly price: ")) == string::npos ) {
                unchange = temp;
                ftemp << temp;
                }
                else {
                    ftemp << "monthly price: " << newprice;
                }
            }
        }
        else {
            //cout << "File du lieu gia bi loi!";
        }
        case 3:
        if ( file.is_open() ) {
            while ( !file.eof() ) {
                getline(file, temp);
                if( (temp.find("extra: ")) == string::npos ) {
                unchange = temp;
                ftemp << temp;
                }
                else {
                    ftemp << "extra: " << newprice;
                }
            }
        }
        else {
            //cout << "File du lieu gia bi loi!";
        }
    }
}