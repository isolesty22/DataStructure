#include <iostream>
#include <stack>
using namespace std;

const int maxsize = 51;

bool VPS();

int main()
{
	int cmdNum;
	cin >> cmdNum;
	cin.get();

	for (int i = 0; i < cmdNum; i++)
	{
		if (VPS())
			cout << "YES" << endl;
		else
		{
			cout << "NO" << endl;
		}
	}
} 

bool VPS()
{
	stack<char> stack;

	char ch;
	while (cin.get(ch))
	{
		if (ch == '\n')
			break;

		if (ch == '(')
		{
			stack.push(ch);
		}
		else if (ch == ')')
		{
			if (stack.empty())
			{
				while (cin.get()!='\n')
				{
					continue;
				}

				return false;
			}
			else
			{
				stack.pop();
			}
		}
	}

	return stack.empty();
}
