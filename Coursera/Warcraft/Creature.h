#pragma once

#include <iostream>

#include "Headquarter.h"

/*
	��ʿ�ǿ���ӵ�е���������
*/
enum Weapon
{
	Sword,
	Bomb,
	Arrow
};

/*
���е���ʿ��������Creature��
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
	dragon ����ӵ��һ�����������Ϊn��dragon����ʱ����ñ��Ϊ n%3 ��������
	dragon���С�ʿ����������ԣ��Ǹ�����������ֵΪ����������˾�ʣ������Ԫ������������dragon���������Ԫ������
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
	ninjia����ӵ���������������Ϊn��ninjia����ʱ����ñ��Ϊ n%3 �� (n+1)%3��������
*/
class Ninjia : public Creature
{
public:
	Ninjia(int _life, Headquarter* _pHead);

private:
	int m_weapon1, m_weapon2;
};

/*
	iceman��һ�����������Ϊn��iceman����ʱ����ñ��Ϊ n%3 ������
*/

class Iceman : public Creature
{
public:
	Iceman(int _life, Headquarter* _pHead);

private:
	int m_weapon;
};

/*
	Lion �С��ҳ϶ȡ�������ԣ���ֵ��������������˾�ʣ������Ԫ����Ŀ��
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