#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    queue<int> queue;

    int cmdNum;
    cin >> cmdNum;

	while (cmdNum--)
	{
		string command;
		cin >> command;

		if (command == "push")
		{
			int num;
			cin >> num;
			queue.push(num);
		}
		else if (command == "pop")
		{
			if (queue.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << queue.front() << '\n';
				queue.pop();
			}
		}
		else if (command == "size")
			cout << queue.size() << '\n';
		else if (command == "empty")
			cout << queue.empty() << '\n';
		else if (command == "front")
		{
			if (queue.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << queue.front() << '\n';
			}
		}
		else if (command == "back")
		{
			if (queue.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << queue.back() << '\n';
			}
		}
	}

	return 0;
}
