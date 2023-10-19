#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	stack<char> st;
	string str;

	int result =0;
	int coefficient = 1;

	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(')
		{
			st.push(str[i]);
			coefficient *= 2;
		}
		else if (str[i] == ')')
		{
			if (st.empty() || st.top() != '(')
			{
				result = 0;
				break;
			}

			if (str[i - 1] == '(')
			{
				coefficient /= 2;
				result += coefficient * 2;
				st.pop();
			}
			else
			{
				coefficient /= 2;
				st.pop();
			}
		}
		else if (str[i] == '[')
		{
			st.push(str[i]);
			coefficient *= 3;
		}
		else if (str[i] == ']')
		{
			if (st.empty() || st.top() != '[')
			{
				result = 0;
				break;
			}

			if (str[i - 1] == '[')
			{
				coefficient /= 3;
				result += coefficient * 3;
				st.pop();
			}
			else
			{
				coefficient /= 3;
				st.pop();
			}
		}
		else
		{
			result = 0;
			break;
		}
	}

	if (!st.empty())
		result = 0;

	cout << result;
}