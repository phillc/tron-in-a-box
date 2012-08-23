#ifndef DIRECTION_H
#define DIRECTION_H

#include <string>
#include <set>
#include <iostream>

enum Directs {North, South, East, West};

class Direction
{
public:
	Direction();
	Direction(Directs);
	std::string WriteMove() const;
	Directs dir;
	bool operator<(Direction const& rhs) const;
	std::string name; // a user readable string
	int value; //what is sent to the Tron engine
	int xadd,yadd; // relative moves associated with this direction
};

typedef std::set<Direction> DirectionSet;

#endif