#pragma once
class Location
{
public:
	void Add(const Location& b) {
		x += b.x;
		y += b.y;
	}

	bool operator==(const Location& b) const {
		return x == b.x && y == b.y;
	}

	int x;
	int y;
};

