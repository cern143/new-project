#include "C:\Users\nguye\Desktop\New project\include\str.h"
using namespace std;
void encryptstr(string &s)
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] < 90)
        {
            s[i] = s[i] + 1;
        }
        if (s[i] > 91)
        {
            s[i] = s[i] - 1;
        }
    }
}

void decryptstr(string &s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] <= 90)
        {
            s[i] = s[i] - 1;
        }
        if (s[i] >= 91)
        {
            s[i] = s[i] + 1;
        }
    }
}

void lowerstr(string &s)
{
    /**
     * Lowercase all character of a s
     */
    for (int i = 0; i < s.length(); i++)
    {
        s[i] = tolower(s[i]);
    }
}

void upperstr(string &s)
{
    /**
     * Uppercase all character of a s
     */
    for (int i = 0; i < s.length(); i++)
    {
        s[i] = toupper(s[i]);
    }
}

void deletesubstr(string &mainstr, const string &substr)
{
    size_t pos;
    while ((pos = mainstr.find(substr)) != string::npos)
    {
        mainstr.erase(pos, substr.length());
    }
}

int str_toint(string s)
{
    int temp = 0;
    for ( int i = 0; i < s.length(); i++ ) {
        temp = temp * 10 + (s[i] - '0');
    }
    return temp;
}