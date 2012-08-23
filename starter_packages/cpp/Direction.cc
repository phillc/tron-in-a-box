#include "Direction.h"
#include "MyTronBot.h"
#include <iostream>
#include <sstream>

using namespace std;

Direction::Direction()
{
	name = "North";
	yadd = -1;
	xadd = 0;
	value = 1;
}

Direction::Direction(Directs indir)
{
	dir = indir;
	switch (dir) {
		case North:
			name = "North";
			yadd = -1;
			xadd = 0;
			value = 1;
			break;
		case South:
			name = "South";
			yadd = 1;
			xadd = 0;
			value = 3;
			break;
		case East:
			name = "East";
			yadd = 0;
			xadd = 1;
			value = 2;
			break;
		case West:
			name = "West";
			yadd = 0;
			xadd = -1;
			value = 4;
			break;
		default:
			break;
	}
}

// output the move to the Tron Engine
string Direction::WriteMove() const
{
	
	cout << value;
	cout.flush();
	stringstream outstring;
	outstring << "Writing move " << name <<" as Tron value "<< value << endl;
	return outstring.str();
}

// the following is needed for the set implementation
bool Direction::operator<(Direction const& rhs) const
{
	return value < rhs.value;
}
