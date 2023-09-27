#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num;
    cin >> num;

    while (num--)
    {
		int N;
		int M;

        int count = 0;

        cin >> N >> M;

        queue<pair<int,int>> Q;
        priority_queue<int> pq;

        for (int i = 0; i < N; i++)
        {
			int n;
			cin >> n;
			Q.push({ n, i });
			pq.push(n);
        }

		while (!Q.empty())
		{
			if (Q.front().first < pq.top())
			{
				Q.push(Q.front());
				Q.pop();
			}
			else
			{
				count++;
                if (Q.front().second == M)
                    cout << count << '\n';
				
                Q.pop();
				pq.pop();
			}
		}

    }
}
