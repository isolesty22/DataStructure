#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    int pos[26];

    for (int i = 0; i < 26; i++)
    {
        pos[i] = -1;
    }

    cin >> str;

    for (int i = 0; i < str.length(); i++)
    {
		if (pos[str[i] - 'a'] == -1)
			pos[str[i] - 'a'] = i;
    }

    for (int i = 0; i < 26; i++)
    {
        cout << pos[i] << ' ';

    }
}