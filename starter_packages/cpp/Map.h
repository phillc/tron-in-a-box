// Map.h
//
// Handles the Tron map. Also handles communicating with the Tron game engine.
// You don't need to change anything in this file.

#ifndef MAP_H
#define MAP_H

#include "MyTronBot.h"
#include "Point.h"
#include "Direction.h"
#include <string>
#include <set>
#include <vector>
#include <fstream>

class Map {
 public:
	// Constructs a Map by reading an ASCII representation from the console
	// (stdin).
	Map();

	// Returns the width of the Tron map.
	int Width() const;

	// Returns the height of the Tron map.
	int Height() const;

	// Returns whether or not the given cell is a wall or not. TRUE means it's
	// a wall, FALSE means it's not a wall, and is passable. Any spaces that are
	// not on the board are deemed to be walls.
	bool IsWall(Point location) const;
	
	// Get my X and Y Point
	Point me();

	// Get the opponent's Point
	Point them();
	
	void MovePlayer(Player player, Direction dir);
	
	std::set<Direction> GetMoves(Point player_point);

	// Sends your move to the contest engine. The four possible moves are
	//	 * 1 -- North. Negative Y direction.
	//	 * 2 -- East. Positive X direction.
	//	 * 3 -- South. Positive X direction.
	//	 * 4 -- West. Negative X direction.
	static void MakeMove(int move);
	
	std::string Print() const;

 private:
	// Load a board from an open file handle. To read from the console, pass
	// stdin, which is actually a (FILE*).
	//	 file_handle -- an open file handle from which to read.
	//
	// If there is a problem, the function returns NULL. Otherwise, a valid
	// Board structure is returned.
	//
	// The file should be an ascii file. The first line contains the width and
	// height of the board, separated by a space. subsequent lines contain visual
	// representations of the rows of the board, using '#' and space characters.
	// The starting positions of the two players are indicated by '1' and '2'
	// characters. There must be exactly one '1' character and one '2' character
	// on the board. For example:
	// 6 4
	// ######
	// #1# 2#
	// #   ##
	// ######
	void ReadFromFile(FILE *file_handle);

 private:
	// Indicates whether or not each cell in the board is passable.
	std::vector<std::vector<bool> > is_wall;
	// The locations of both players.
	Point my_point;
	Point their_point;	

	
	// Map dimensions.
	int map_width, map_height;
};


#endif