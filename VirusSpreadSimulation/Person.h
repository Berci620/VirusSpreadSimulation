#pragma once

#include "Position.h"
#include "InfectionStatus.h"
#include "LifeStatus.h"

class Person
{
private:	//Variables
	Position _position;
	InfectionStatus _infectionStatus;

public:		//Constructors
	Person(InfectionStatus infectionStatus, const unsigned int positionSize);
};

