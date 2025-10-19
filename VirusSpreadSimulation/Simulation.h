#pragma once

#include "Person.h"

class Simulation
{
private:	//Variables
	const unsigned int _size;
	const int _nPersons;
	const int _nSamplePlace;
	const int _nQuarantineDays;
	const float _pInfected;
	const float _pInfects;
	const float _pMove;
	std::vector<Person> _persons;
	std::vector<Position> _quarantines;


public:		//Constructors
	Simulation(const unsigned int size, const int nPersons, const int nSamplePlace,
		const int nQuarantineDays, const float& pInfected, const float& pInfects,
		const float& pMove);

private:	//Simulation steps
	void Infecting();

};

