#ifndef POINT_H
#define POINT_H

#include "MyTronBot.h"
#include "Direction.h"

class Point {
public:
	int x, y;
	Point();
	Point(int,int);
	bool operator==(const Point&) const;
	std::string Print() const;
	Point Relative(Direction) const;
	void Move(Direction); // does not change the map. Use Map::MovePlayer to do that
	int ManhattanDistance(const Point) const;
	int EuclideanDistance(const Point) const;
};

#endif