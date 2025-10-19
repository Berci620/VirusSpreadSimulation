#include <random>

#include "Person.h"


std::random_device rndPos;
std::mt19937 generatorPos{ rndPos() };


//------------------------------------------------------------------------
//Constructors

Person::Person(InfectionStatus infectionStatus, const unsigned int positionSize)
	:_infectionStatus(infectionStatus)
{
	std::uniform_int_distribution<unsigned int> rndPos(0, Position::MaxX());
	_position = Position{ rndPos(generatorPos), rndPos(generatorPos) };
}