#include "Point.h"
#include "MyTronBot.h"
#include "Map.h"
#include <cstdio>
#include <cstdlib>
#include <string>
#include <sstream>
#include <vector>
#include <set>

using namespace std;

Map::Map() {
  ReadFromFile(stdin);
}

int Map::Width() const {
  return map_width;
}

int Map::Height()  const {
  return map_height;
}

bool Map::IsWall(Point location) const {
  if (location.x < 0 || location.y < 0 || location.x >= map_width || location.y >= map_height) {
	return true;
  } else {
	return is_wall[location.x][location.y];
  }
}

Point Map::me()
{
	return my_point;
}
Point Map::them()
{
	return their_point;
}

void Map::MovePlayer(Player player, Direction dir)
{
	Point *player_point;
	if(player == Me)
	{
		player_point = &my_point;
	} else {
		player_point = &their_point;
	}		
	// fill in the wall and move the player's Point
	is_wall[player_point->x][player_point->y] = true;
	player_point->Move(dir);
}


set<Direction> Map::GetMoves(Point player_point)
{
	set<Direction> moves;
	Direction dirs [4] = {North,South,East,West};
	for(int i = 0; i < 4; i++)
	{
		Point destination = player_point.Relative(dirs[i]);
		if (!(IsWall(destination) or destination == their_point or destination == my_point))
		{
			logfile << IsWall(destination) << destination.Print() << endl;
			moves.insert(dirs[i]);
		}
	}
	return moves;
}

string Map::Print() const
{
	stringstream output;
	
	//using iterators here isn't worth it (have to keep x and y anyway)
	for(int y = 0; y < map_height; ++y)
	{
		for(int x = 0; x < map_width; ++x)
		{
			if(is_wall[x][y])
			{
				output << '#';
				} else if(my_point.x == x and my_point.y == y) output << '1';
					else if(their_point.x == x and their_point.y == y) output << '2';
						else output << ' ';
		}
		output << endl;
	}
	
	return output.str();
}


void Map::ReadFromFile(FILE *file_handle) {

  int x, y, c;
  int num_items = fscanf(file_handle, "%d %d\n", &map_width, &map_height);
  if (feof(file_handle) || num_items < 2) {
	exit(0); // End of stream means end of game. Just exit.
  }
  is_wall =	vector<vector<bool> >(map_width,vector<bool>(map_height, false));
  x = 0;
  y = 0;
  while (y < map_height && (c = fgetc(file_handle)) != EOF) {
	  
	switch (c) {
	case '\r':
	  break;
	case '\n':
	  if (x != map_width) {
	fprintf(stderr, "x != width\n");
	return;
	  }
	  ++y;
	  x = 0;
	  break;
	case '#':
	  if (x >= map_width) {
	fprintf(stderr, "x >= width\n");
	return;
	  }
	  is_wall[x][y] = true;
	  ++x;
	  break;
	case ' ':
	  if (x >= map_width) {
	fprintf(stderr, "x >= width\n");
	return;
	  }
	  is_wall[x][y] = false;
	  ++x;
	  break;
	case '1':
	  if (x >= map_width) {
	fprintf(stderr, "x >= width\n");
	return;
	  }
	  is_wall[x][y] = false;
			my_point.x=x;
			my_point.y=y;
	  ++x;
	  break;
	case '2':
	  if (x >= map_width) {
	fprintf(stderr, "x >= width\n");
	return;
	  }
	  is_wall[x][y] = false;
			their_point.x=x;
			their_point.y=y;
	  ++x;
	  break;
	default:
	  fprintf(stderr, "unexpected character %d", c);
	  return;
	}
  }
}
