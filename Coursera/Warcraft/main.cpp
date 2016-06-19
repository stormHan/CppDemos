#include <iostream>

#include "Headquarter.h"

int main()
{
	int cases;
	int lifevalue[5];
	int totallife;

	std::cin >> cases;

	while (cases--)
	{
		std::cin >> totallife;
		std::cin >> lifevalue[dragon] >> lifevalue[ninjia] >> lifevalue[iceman]
			>> lifevalue[lion] >> lifevalue[wolf];

		Headquarter RedHq(totallife, "red headquarter", lifevalue);
		Headquarter BlueHq(totallife, "blue headquarter", lifevalue);
		
		
	}

	return 0;
}