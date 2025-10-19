#include "Position.h"


unsigned int Position::maxX = 100;
unsigned int Position::maxY = 100;

//--------------------------------------------------------------------------
//Constructors

Position::Position(const unsigned int size)
{
	this->_x = size;
	this->_y = size;
}


//--------------------------------------------------------------------------
//Operators

bool Position::operator==(Position other) const
{
	return _x == other._x && _y == other._y;
}


//--------------------------------------------------------------------------
//Static functions

void Position::SetMaxXY(const unsigned int x, const unsigned int y)
{
	maxX = x;
	maxY = y;
}


//--------------------------------------------------------------------------
//Neighbors

std::vector<Position> Position::GetNeighbors()
{
	std::vector<Position> result;
	unsigned int xLeft = (_x == 0 ? 0 : _x - 1);
	unsigned int xRight = (_x == maxX ? maxX : _x + 1);
	unsigned int yDown = (_y == 0 ? 0 : _y - 1);
	unsigned int yUp = (_y == maxY ? maxY : _y + 1);

	for (auto horizontal = xLeft; horizontal <= xRight; ++horizontal)
	{
		for (auto vertical = yDown; vertical <= yUp; ++vertical)
		{
			if (_x == horizontal && _y == vertical)
			{}
			else
			{
				result.push_back(Position{ horizontal, vertical });
			}
		}
	}

	return result;
}
