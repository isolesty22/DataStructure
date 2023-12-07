#include <iostream>
#include <string>	
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string str;

	while (getline(cin, str))
    {
		if (str.size() == 0)
			break;

        int lower = 0;
        int upper = 0;
        int num = 0;
        int blank = 0;

		for (int i = 0; i < str.size(); i++)
		{
			if ('a' <= str[i] && str[i] <= 'z')
				lower++;
			else if ('A' <= str[i] && str[i] <= 'Z')
				upper++;
			else if ('0' <= str[i] && str[i] <= '9')
				num++;
			else if (str[i] == ' ')
				blank++;
			else
				break;
		}
		cout << lower << ' ' << upper << ' ' << num << ' ' << blank << '\n';
    }
}