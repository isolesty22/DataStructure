#include <iostream>
#include <queue>

int main()
{
    using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    queue<int> Q;
    queue<int> result;

    int N; int K;
    cin >> N >> K;

    for (int i = 1; i <= N; i++)
    {
        Q.push(i);
    }

    while (!Q.empty())
    {
        int T = K - 1;

        while (T--)
        {
            Q.push(Q.front());
            Q.pop();
        }
        result.push(Q.front());
        Q.pop();
    }

    cout << '<';
    while (result.size() != 1)
    {
        cout << result.front() << ", " ;
        result.pop();
    }
    cout << result.front() << '>';
}