#include <random>

#include "Simulation.h"


std::random_device rnd;
std::mt19937 generator{ rnd() };
std::uniform_int_distribution<int> rnd100(1, 100);

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

	for (int i = 0; i < _nPersons; ++i)
	{
	Person p = Person{ (rnd100(generator) / (float)100 < _pInfected) ? InfectionStatus::fertõzött
	: InfectionStatus::normál, _size };
	_persons.push_back(p);
	}
}


//-----------------------------------------------------------------------
//Simulation steps

void Simulation::Infecting()
{
	for (const auto& it : _persons)
	{
		if (it.GetInfectionStatus() == InfectionStatus::fertõzött ||
			it.GetInfectionStatus() == InfectionStatus::megerõsített)
		{
			for (auto toInfect : _persons)
			{
				if (toInfect.GetPosition() == it.GetPosition() &&
					toInfect.GetInfectionStatus() == InfectionStatus::normál)
				{
					if (rnd100(generator) / (float)100 < _pInfects)
					{
						toInfect.SetInfectionStatus(InfectionStatus::fertõzött);
					}
				}
			}
		}
	}
}

