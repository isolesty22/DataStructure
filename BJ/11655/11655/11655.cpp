#include <iostream>
#include <string>  
using namespace std;

int main()
{
    string str;
    getline(cin, str);

    for (int i = 0; i < str.size(); i++)
    {
        if ('A' <= str[i] && str[i] <= 'Z')
            cout << (char)((str[i] - 'A' + 13) % 26 + 'A');
        else if ('a' <= str[i] && str[i] <= 'z')
            cout << (char)((str[i] - 'a' + 13) % 26 + 'a');
        else cout << str[i];
    }
}