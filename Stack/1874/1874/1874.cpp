#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	stack<int> st;
	int* input = new int[N];
	queue<char> Q;
	int stNum = 1;

	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		input[i] = n;
	}

	for (int i = 0; i < N; i++)
	{
		int n = input[i];

		if (n >= stNum)
		{
			int r = n - stNum;
			for (int j = 0; j <= r; j++)
			{
				st.push(stNum++);
				Q.push('+');
			}
			st.pop();
			Q.push('-');
		}
		else if (n == st.top())
		{
			st.pop();
			Q.push('-');
		}
		else
		{
			cout << "NO";
			delete[] input;
			return 0;
		}
	}

	while (!Q.empty())
	{
		cout << Q.front() << '\n';
		Q.pop();
	}

	delete[] input;
}