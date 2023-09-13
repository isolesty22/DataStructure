#include <iostream>
#include <deque>

int main()
{
	using namespace std;

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	deque<int> deque;
	string cmd;

	while (N--)
	{
		cin >> cmd;

		if (cmd == "push_front")
		{
			int num;
			cin >> num;
			deque.push_front(num);
		}
		else if (cmd == "push_back")
		{
			int num;
			cin >> num;
			deque.push_back(num);
		}
		else if (cmd == "pop_front")
		{
			if (deque.empty())	cout << -1 << '\n';
			else
			{
				cout << deque.front() << '\n';
				deque.pop_front();
			}
		}
		else if (cmd == "pop_back")
		{
			if (deque.empty())	cout << -1 << '\n';
			else
			{
				cout << deque.back() << '\n';
				deque.pop_back();
			}
		}
		else if (cmd == "size")
			cout << deque.size() << '\n';
		else if (cmd == "empty")
			cout << deque.empty() << '\n';
		else if (cmd == "front")
		{
			if (deque.empty())	cout << -1 << '\n';
			else cout << deque.front() << '\n';
		}
		else if (cmd == "back")
		{
			if (deque.empty())	cout << -1 << '\n';
			else cout << deque.back() << '\n';
		}
	}
}