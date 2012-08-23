#include "MyTronBot.h"
#include "Map.h"
#include "Point.h"
#include <cmath>
#include <cstdlib>
#include <sstream>

using namespace std;

Point::Point(int xin, int yin)
{
	x = xin;
	y = yin;
}

Point::Point()
{
	x = 0;
	y = 0;
}

bool Point::operator== (const Point &comp) const
{
	return (x == comp.x) and (y == comp.y);
}

Point Point::Relative(Direction dir) const
{
	Point output = *this;
	output.x += dir.xadd;
	output.y += dir.yadd;
	return output;
}

string Point::Print() const
{
	stringstream outstring;
	outstring << "("<<x<<", "<<y<<")";
	return outstring.str();
}

void Point::Move(Direction dir)
{
	*this = this->Relative(dir);
}

// The manhattan distance is used for some searches
int Point::ManhattanDistance(Point far) const
{
	return abs(far.x - x) + abs(far.y - y);
}

// The crow's flight distance between two points, rounded to an int
// If you want real path distance you're going to have to work for it.
int Point::EuclideanDistance(Point far) const
{
	return (int) sqrt((far.x - x)*(far.x - x)+(far.y - y)*(far.y - y));
}