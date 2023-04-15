#include"SJF.h"
#include "Scheduler.h"
# include "Process.h"
#include "PriorityQueue.h"
SJF::SJF(int id, int rtf, int maxw, int stl, int fp)
{
	setID(id);
	setRTF(rtf);
	setMaxW(maxw);
	setSTL(stl);
	setFP(fp);

}

SJF::SJF()
{

}

SJF::~SJF()
{

}

void SJF::setready(Process* px)
{
	
	ready.enqueue(px, px->getAT());

}

void SJF::ScheduleAlgo()
{
	ready.dequeue(*&run);
}

void SJF::printRDY()
{

}
