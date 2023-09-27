#include <iostream>
#include <deque>
using namespace std;

int main()
{
    int N;
    cin >> N;

    deque<pair<int, int>> dq;

    for (int i = 1; i <= N; i++)
    {
        int n;
        cin >> n;
        dq.push_back({ i,n });
    }

    while (!dq.empty())
    {
		if (dq.front().second > 0)
		{
			int n = dq.front().second;
			cout << dq.front().first << ' ';

			//터뜨리기
			dq.pop_front();
			//이동
			if (!dq.empty())
			{
				for (int i = 0; i < n - 1; i++)
				{
					dq.push_back(dq.front());
					dq.pop_front();
				}
			}
		}
		else if (dq.front().second < 0)
		{
			int n = - dq.front().second;
			cout << dq.front().first << ' ';

			//터뜨리기
			dq.pop_front();
			if (!dq.empty())
			{
				for (int i = 0; i < n; i++)
				{
					dq.push_front(dq.back());
					dq.pop_back();
				}
			}
		}

    }

}