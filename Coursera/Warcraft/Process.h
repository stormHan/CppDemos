#pragma once
#include <queue>

#include "Headquarter.h"

class Process
{
public:
	Process(Headquarter *_pHead) : pHead(_pHead){};


private:
	Headquarter *pHead;
	std::queue<int> m_queue; // a queue to determine the sequence
};
