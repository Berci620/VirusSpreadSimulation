#pragma once

#include <vector>

class Position
{
private: //Variables
	unsigned int _x;
	unsigned int _y;
	static unsigned int maxX;
	static unsigned int maxY;


public:	//Constructors
	Position() = default;
	Position(const unsigned int size);


public: //Operators
	bool operator==(Position other) const;


public:	//Static functions
	static void SetMaxXY(const unsigned int x, const unsigned int y);


public: //Neighbors
	std::vector<Position> GetNeighbors();
};

