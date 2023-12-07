#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<string> vec;
    string str;
    string temp;

    cin >> str;

    for (int i = 0; i < str.size(); i++)
    {
        temp = str.substr(i);
        vec.push_back(temp);
    }

    sort(vec.begin(), vec.end());
    
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << '\n';
    }
}