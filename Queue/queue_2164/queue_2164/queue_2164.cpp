#include <iostream>
#include <queue>   

int main()
{
    using namespace std;

    queue<int> Q;

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        Q.push(i);
    }

    while (Q.size() != 1)
    {
        Q.pop();
        Q.push(Q.front());
        Q.pop();
    }

    cout << Q.front();

}