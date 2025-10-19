#include "Position.h"


unsigned int Position::maxX = 100;
unsigned int Position::maxY = 100;

//--------------------------------------------------------------------------
//Constructors

Position::Position(const unsigned int x, const unsigned int y)
{
	this->_x = x;
	this->_y = y;
}


//--------------------------------------------------------------------------
//Operators

bool Position::operator==(Position other) const
{
	return _x == other._x && _y == other._y;
}


//--------------------------------------------------------------------------
//Static functions

unsigned int Position::MaxX()
{
	return Position::maxX;
}

unsigned int Position::MaxY()
{
	return Position::maxY;
}


//--------------------------------------------------------------------------
//Static functions

void Position::SetMaxXY(const unsigned int size)
{
	maxX = size;
	maxY = size;
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
