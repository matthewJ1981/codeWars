#include "path_finder.h"
#include <algorithm>
#include <vector>
#include <stack>
#include <iostream>
#include <exception>

//x and y struct to remember position and move from square to square
struct vector
{
	int x;
	int y;
	vector operator+(const vector& rhs)
	{
		return { x + rhs.x, y + rhs.y };
	}
	bool operator == (const vector& rhs)
	{
		return x == rhs.x && y == rhs.y;
	}
	bool operator != (const vector& rhs)
	{
		return !(*this == rhs);
	}

	friend std::ostream& operator << (std::ostream& out, const vector& vec);
};

//direction has a name, a vector that would be applied to current position and if the movement is going to be valid
struct direction
{
	std::string name;
	vector move;
	bool hasPath;
};

//Output vector
std::ostream& operator << (std::ostream& out, const vector& vec)
{
	out << "x: " << vec.x << ", y: " << vec.y;
	return out;
}

//Check if a square is on the traversed path to avoid going in circles
bool alreadyTraversed(std::vector<int> path, int index)
{
	return std::find(path.begin(), path.end(), index) != path.end();
}

//each square has 4 directions, whether it is a wall, the direction moved from the square and to the square
struct square
{
	std::vector<direction> directions;
	bool isWall;
	direction cameFrom;
	int dirMoved;
	int availableMoves();
};

//get count of available moves for a square
int square::availableMoves()
{
	int moves = 0;
	for (direction dir : directions)
		moves += int(dir.hasPath);

	return moves;
}
//Output square
std::ostream& operator << (std::ostream& out, const square& square)
{
	for (direction dir : square.directions)
		out << dir.name << ": " << dir.hasPath << " ";
	out << square.isWall;
	return out;
}

//Return opposite direction of an input direction
direction opposite(const direction& dir)
{
	if (dir.name == "north")
		return { "south", {0, 1}, true };
	else if (dir.name == "south")
		return { "north", {0, -1}, true };
	else if (dir.name == "east")
		return { "west", {-1, 0}, true };
	else if (dir.name == "west")
		return { "east", {1, 0}, true };
	else throw std::runtime_error("unrecognized direction");
}

bool path_finder(std::string maze)
{
	//width, height, and total squares in maze
	size_t width = maze.find('\n');
	size_t height = width;
	size_t size = width * height;

	// Remove new lines from maze string to line up indices
	maze.erase(std::remove(maze.begin(), maze.end(), '\n'), maze.end());

	//vector of squares
	std::vector<square> squares;
	for (int i = 0; i < int(size); i++)
	{
		squares.push_back({
							{
								{"north", { 0, -1}, true},
								{"east",  { 1,  0}, true},
								{"south", { 0,  1}, true},
								{"west",  {-1,  0}, true}  
			                },
			                maze[i] == 'W',
							{ "none", { 0, 0}, true },
							-1
			              });

	}

	//debug output for squares
	//for (int i = 0; i < size; i++)
		//std::cerr << "Square: " << i << "\n" << squares[i] << "\n";

	//vector of index traveresed
	std::vector<int> path;

;

	//Add starting square to path
	path.push_back(0);

	//debug output for maze
	//std::cerr << maze << "\n\n";

	//Starting position
	vector currPos{ 0, 0 };
	vector nextPos{ -1, -1 };


	bool goal = false;
	bool traversing = true;
	while (traversing)
	{
		//debug output for position
		//std::cerr << currPos << "\n";

		//index of current square
		int currSquare = currPos.x + currPos.y * int(width);

		//Check all directions 
		for (int i = 0; i < 4; i++)
		{
			direction & dir = squares[currSquare].directions[i];

			//Ignore direction if it has been checked already
			if (!dir.hasPath)
				continue;

			//Temporarily move to the next square and see if the move is valid
			nextPos = currPos + dir.move;

			//Mark path as invalid If x or y is out of the maze, the square has already been traverresd, or the square is a wall
			int nextSquare = nextPos.x + nextPos.y * int(width);
			if (nextPos.x < 0 || nextPos.x > int(width) - 1 ||
				nextPos.y < 0 || nextPos.y > int(height) - 1 ||
				alreadyTraversed(path, nextSquare) ||
				squares[nextSquare].isWall
				)
			{
				dir.hasPath = false;
			}
			//Otherwise move to the next square
			else
			{
				currPos = nextPos;
				//Remember the index of the direcion moved to update hasPath later
				squares[currSquare].dirMoved = i;
				//Rember the direction came from for the next square
				squares[nextSquare].cameFrom = opposite(dir);
				//Add nextSquare to the traversed path;
				path.push_back(nextSquare);
				break;
			}
		}

		//Made it to the goal
		if (currPos == vector{ int(width) - 1, int(height) - 1 })
		{
			goal = true;
			traversing = false;
		}

		//Exhausted directions
		if (squares[currSquare].availableMoves() == 0)
		{
			//Go back a square
			if (path.size() > 1)
			{
				path.pop_back();
				//Move position to the last square traversed
				currPos = currPos + squares[currSquare].cameFrom.move;
				//mark the previous path as invalid because it didn't reach the goal
				int lastSquare = path.back();
				squares[lastSquare].directions[squares[lastSquare].dirMoved].hasPath = false;
			}
			//No path found
			else
				traversing = false;
		}
	}
	return goal;
}