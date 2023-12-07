#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string str1, str2, str3, str4;

	cin >> str1 >> str2 >> str3 >> str4;

	string a = str1 + str2;
	string b = str3 + str4;

	cout << stol(a) + stol(b);
}