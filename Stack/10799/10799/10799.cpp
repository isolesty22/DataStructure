#include <iostream>
#include <stack>

int main()
{
	using namespace std;

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string str;
	stack<char> st;
	int count = 0;

	cin >> str;
	
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(')
			st.push(str[i]);
		else if (str[i] == ')')
		{
			if (!st.empty())
			{
				if (str[i - 1] == '(')
				{
					st.pop();
					count += st.size();
				}
				else
				{
					st.pop();
					count++;
				}
			}
			else
				cout << "error" << '\n';
		}
		else
			cout << "error<<'\n";
	}

	cout << count;
}