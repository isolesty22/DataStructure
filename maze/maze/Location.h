#pragma once
class Location
{
public:
	int x;
	int y;
public:
	Location(int X = 0, int Y = 0) { x = X; y = Y; };

	bool isNeighbor(Location& p) 
	{
		return (x == p.x && (y == p.y + 1 || y == p.y - 1)) || (y == p.y && (x == p.x + 1 || x == p.x - 1));
	};

	bool operator==(Location& p)
	{
		return x == p.x && y == p.y;
	}
};

