#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> queue;

    unsigned int cmdNum;
    cin >> cmdNum;

	string command;

	while (cmdNum--)
	{
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
				cout << -1 << endl;
			}
			else
			{
				cout << queue.front() << endl;
				queue.pop();
			}
		}
		else if (command == "size")
			cout << queue.size() << endl;
		else if (command == "empty")
			cout << queue.empty() << endl;
		else if (command == "front")
		{
			if (queue.empty())
			{
				cout << -1 << endl;
			}
			else
			{
				cout << queue.front() << endl;
			}
		}
		else if (command == "back")
		{
			if (queue.empty())
			{
				cout << -1 << endl;
			}
			else
			{
				cout << queue.back() << endl;
			}
		}
		/*else
			cmdNum++;*/
	
	}

		
}
