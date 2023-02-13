#include "../include/ftxt.h"
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
    ifstream file("D:\\price.txt"); 
    ofstream ftemp("temp.txt");
    switch (choice) {
        case 1:
        if ( file.is_open() ) {
            while ( !file.eof() ) {
                getline(file, temp);
                if( (temp.find("daily price: ")) == string::npos ) {
                unchange = temp;
                ftemp << temp << "\n";
                }
                else {
                    ftemp << "daily price: " << newprice << "\n";
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
                ftemp << temp << "\n";
                }
                else {
                    ftemp << "monthly price: " << newprice << "\n";
                }
            }
        }
        else {
            //cout << "File du lieu gia bi loi!";
        }
        break;
        case 3:
        if ( file.is_open() ) {
            while ( !file.eof() ) {
                getline(file, temp);
                if( (temp.find("extra: ")) == string::npos ) {
                unchange = temp;
                ftemp << temp << "\n";
                }
                else {
                    ftemp << "extra: " << newprice << "\n";
                }
            }
        }
        else {
            //cout << "File du lieu gia bi loi!";
        }
        break;
    }
    file.close();
    ftemp.close();
    remove("D:\\price.txt");
    rename("temp.txt", "D:\\price.txt");
}