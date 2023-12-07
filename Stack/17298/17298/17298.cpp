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
	stack<int> st;
	stack<int> result;

	for (int i = 0; i < N; i++)
		cin >> seq[i];

	for (int i = N - 1; i >= 0; i--)
	{
		if (st.empty())
		{
			result.push(-1);
			st.push(seq[i]);
		}
		else
		{
			//현재값과 스택 비교 
			// 2 7 3 5

			//스택에서 우큰수 탐색
			while (!st.empty() && seq[i] >= st.top())
			{
				//없으면 계속 pop, 만약 내가 큰것이라면 어차피 내가 우큰수가 됨.
				st.pop();
			}

			//해당 원소가 우큰수가 될 수도 있으니 stack에 push
			//pop 다 했는데 스택이 비었으면 우큰수가 없는 것, 스택이 있으면 그게 우큰수.
			if (st.empty())
				result.push(-1);
			else
				result.push(st.top());

			st.push(seq[i]);
		}
	}

	//결과 출력
	while (!result.empty())
	{
		cout << result.top() << ' ';
		result.pop();
	}

	delete[] seq;
}