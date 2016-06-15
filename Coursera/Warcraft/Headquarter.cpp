
#include "Headquarter.h"
#include "Creature.h"

Headquarter::Headquarter(int _lifeElement, std::string _name, int _lifevalue[5])
{
	m_lifeElement = _lifeElement;
	creature_nb = 0;
	m_name = _name;

	m_lifevalue[dragon] = _lifevalue[dragon];
	m_lifevalue[ninjia] = _lifevalue[ninjia];
	m_lifevalue[iceman] = _lifevalue[iceman];
	m_lifevalue[lion] = _lifevalue[lion];
	m_lifevalue[wolf] = _lifevalue[wolf];
}

/*
	ÿ�δ����µ���ʿ���������������������˾�����
*/
void Headquarter::Usage(int _useup)
{
	creature_nb++;
	m_lifeElement -= _useup;
	Dragon *a = new Dragon(1);
}

/*
	���ݲ�ͬ�����ͣ����첻ͬ����ʿ
*/
void Headquarter::CreateWarrior(CreatureType _ct, int _life)
{
	switch (_ct)
	{
	case dragon:	m_creatures[creature_nb] = new Dragon(_life, this);	m_count[dragon]++;
		break;
	case ninjia:	m_creatures[creature_nb] = new Ninjia(_life, this);	m_count[ninjia]++;
		break;
	case iceman:	m_creatures[creature_nb] = new Iceman(_life, this);	m_count[iceman]++;
		break;
	case lion:		m_creatures[creature_nb] = new Lion(_life, this);		m_count[lion]++;
		break;
	case wolf:		m_creatures[creature_nb] = new Wolf(_life, this);		m_count[wolf]++;
		break;
	default:
		break;
	}
}