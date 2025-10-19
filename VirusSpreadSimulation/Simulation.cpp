#include <random>

#include "Simulation.h"


std::random_device rnd;
std::mt19937 generator{ rnd() };

//------------------------------------------------------------------------
//Constructors

Simulation::Simulation(const unsigned int size, const int nPersons, const int nSamplePlace,
	const int nQuarantineDays, const float& pInfected, const float& pInfects,
	const float& pMove)
	: _size(size), _nPersons(nPersons), _nSamplePlace(nSamplePlace), 
	_nQuarantineDays(nQuarantineDays), _pInfected(pInfected), _pInfects(pInfects),
	_pMove(pMove)
{
	Position::SetMaxXY(_size);

	std::uniform_int_distribution<int> rnd100(1, 100);

	for (int i = 0; i < _nPersons; ++i)
	{
	Person p = Person{ (rnd100(generator) / (float)100 < _pInfected) ? InfectionStatus::fertõzött
	: InfectionStatus::normál, _size };
	_persons.push_back(p);
	}
}