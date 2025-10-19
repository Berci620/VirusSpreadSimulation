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


//------------------------------------------------------------------------
//Getters

const InfectionStatus& Person::GetInfectionStatus() const 
{
	return _infectionStatus;
}

const Position& Person::GetPosition() const
{
	return _position;
}

//------------------------------------------------------------------------
//Setters

void Person::SetInfectionStatus(InfectionStatus status)
{
	_infectionStatus = status;
}