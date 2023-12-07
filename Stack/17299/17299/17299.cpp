#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	int* seq = new int[N];
	int* count = new int[1000001]{ 0 };
	stack<int> st;
	stack<int> result;

	for (int i = 0; i < N; i++)
	{
		cin >> seq[i];
		count[seq[i]]++;
	}

	for (int i = N - 1; i >= 0; i--)
	{
		if (st.empty())
		{
			result.push(-1);
			st.push(seq[i]);
		}
		else
		{
			while (!st.empty() && count[seq[i]] >= count[st.top()])
			{
				st.pop();
			}

			if (st.empty())
				result.push(-1);
			else
				result.push(st.top());

			st.push(seq[i]);
		}
	}

	while (!result.empty())
	{
		cout << result.top() << ' ';
		result.pop();
	}

	delete[] seq;
	delete[] count;

}