
#include "Creature.h"

Creature::Creature()
{
	/*
		每个武士的编号是当前该司令部的生物总数
	*/
	m_number = pHead->getCreatureNumber();
}


Dragon::Dragon(int _life, Headquarter* _pHead)
{
	m_lifevalue = _life;
	pHead = _pHead;
	/*
		武器的属性是编号n%3
	*/
	m_weapon = m_number % 3;

	m_morale = pHead->getLifeElement() / m_lifevalue;

	if (m_lifevalue != 0)
		pHead->Usage(m_lifevalue);
	else
		std::cout << "Error Creating Dragon, its life value is 0!" << std::endl;
}


Ninjia::Ninjia(int _life, Headquarter* _pHead)
{
	m_lifevalue = _life;
	pHead = _pHead;
	/*
		武器w1的属性是编号n%3
	*/
	m_weapon1 = m_number % 3;

	/*
		武器w2的属性是编号n%3+1
		*/
	m_weapon2 = (m_number + 1) % 3;

	if (m_lifevalue != 0)
		pHead->Usage(m_lifevalue);
	else
		std::cout << "Error Creating Ninjia, its life value is 0!" << std::endl;
}	

Iceman::Iceman(int _life, Headquarter* _pHead)
{
	m_lifevalue = _life;
	pHead = _pHead;
	/*
		武器的属性是编号n%3
	*/
	m_weapon = m_number % 3;

	if (m_lifevalue != 0)
		pHead->Usage(m_lifevalue);
	else
		std::cout << "Error Creating Iceman, its life value is 0!" << std::endl;
}

Lion::Lion(int _life, Headquarter* _pHead)
{
	m_lifevalue = _life;
	pHead = _pHead;
	/*
		Lion武士的忠诚度是和司令部的生命元数量有关的
	*/
	m_loyalty = pHead->getLifeElement();

	if (m_lifevalue != 0)
		pHead->Usage(m_lifevalue);
	else
		std::cout << "Error Creating Lion, its life value is 0!" << std::endl;
}

Wolf::Wolf(int _life, Headquarter* _pHead)
{
	m_lifevalue = _life;
	pHead = _pHead;

	if (m_lifevalue != 0)
		pHead->Usage(m_lifevalue);
	else
		std::cout << "Error Creating Wolf, its life value is 0!" << std::endl;
}