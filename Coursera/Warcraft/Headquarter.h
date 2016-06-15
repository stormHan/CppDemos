#pragma once 

#include <string>

#include "Creature.h"

enum CreatureType
{
	dragon,
	ninjia,
	iceman,
	lion,
	wolf
};

#define MAX_CREATURE_NUMBER 1000


/*
司令部类，每个Creature所属于一个司令部
*/
class Headquarter
{
public:
	Headquarter(int _lifeElement, std::string _name, int _lifevalue[5]);

	void Usage(int _useup);

	void CreateWarrior(CreatureType _ct, int _life);

	const int getCreatureNumber() { return creature_nb; }
	const int getLifeElement() { return m_lifeElement; }

private:
	int creature_nb;
	int m_lifeElement;
	int m_count[5];
	int m_lifevalue[5];

	std::string m_name;
	/*friend Creature;
	friend Dragon;*/
	
	Creature* m_creatures[MAX_CREATURE_NUMBER];
	
};