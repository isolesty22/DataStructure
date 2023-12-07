#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    int count[26]{ 0 };

    cin >> str;

    for (int i = 0; i < str.length(); i++)
    {
        count[str[i] - 'a']++;
    }  

    for (int i = 0; i < 26; i++)
    {
        cout << count[i] << ' ';
    }

}