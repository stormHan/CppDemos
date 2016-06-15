#pragma once

#include <iostream>

#include "Headquarter.h"

/*
	武士们可以拥有的三种武器
*/
enum Weapon
{
	Sword,
	Bomb,
	Arrow
};

/*
所有的武士都派生于Creature类
*/
class Creature
{
public:
	Creature();

	//const int getNumber(){ return m_number; }
	//Headquarter* getMyHeadQuarter() { return pHead; }
protected:
	int m_lifevalue;
	int m_number;
	Headquarter* pHead;
};

/*
	dragon 可以拥有一件武器。编号为n的dragon降生时即获得编号为 n%3 的武器。
	dragon还有“士气”这个属性，是个浮点数，其值为它降生后其司令部剩余生命元的数量除以造dragon所需的生命元数量。
*/
class Dragon : public Creature
{
public:
	Dragon(int _life, Headquarter* _pHead);
private:
	int m_weapon;
	float m_morale;
};

/*
	ninjia可以拥有两件武器。编号为n的ninjia降生时即获得编号为 n%3 和 (n+1)%3的武器。
*/
class Ninjia : public Creature
{
public:
	Ninjia(int _life, Headquarter* _pHead);

private:
	int m_weapon1, m_weapon2;
};

/*
	iceman有一件武器。编号为n的iceman降生时即获得编号为 n%3 的武器
*/

class Iceman : public Creature
{
public:
	Iceman(int _life, Headquarter* _pHead);

private:
	int m_weapon;
};

/*
	Lion 有“忠诚度”这个属性，其值等于它降生后其司令部剩余生命元的数目。
*/
class Lion : public Creature
{
public:
	Lion(int _life, Headquarter* _pHead);

private:
	int m_loyalty;
};

class Wolf : public Creature
{
public:
	Wolf(int _life, Headquarter* _pHead);

private:

};