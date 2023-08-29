#include <iostream>
#include "Location.h"  
#include <stack>
using namespace std;

const int mapSize = 6;

char map[mapSize][mapSize] =
{
	{'1','1','1','1','1','1'},
	{'e','0','1','0','0','1'},
	{'1','0','0','0','1','1'},
	{'1','0','1','0','1','1'},
	{'1','0','1','0','0','x'},
	{'1','1','1','1','1','1'}
};

bool isValid(int x, int y)
{
	if (x<0 || y<0 || x>mapSize || y>mapSize) return false;
	else return map[x][y] == '0' || map[x][y] == 'x';
}

int main()
{
	stack<Location> stack;
	Location entry(1, 0);
	stack.push(entry);

	while (!stack.empty())
	{
		Location here = stack.top();
		stack.pop();

		int x = here.x;
		int y = here.y;

		cout << x << ',' << y<<'/';

		if (map[x][y] == 'x') {
			cout << "success!" << endl;
			return 0;
		}
		else
		{
			map[x][y] = '.';
			if (isValid(x - 1, y)) stack.push(Location(x - 1, y));
			if (isValid(x + 1, y)) stack.push(Location(x + 1, y));
			if (isValid(x, y - 1)) stack.push(Location(x, y - 1));
			if (isValid(x, y + 1)) stack.push(Location(x, y + 1));
		}
	}

}

