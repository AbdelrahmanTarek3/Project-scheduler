#include <sstream>
#include"SJF.h"
#include "Scheduler.h"
# include "Process.h"
#include "PriorityQueue.h"
SJF::SJF(int id, int rtf, int maxw, int stl, int fp)
 : Processor()
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

void SJF::ScheduleAlgo(int time, LinkedQueue <Process*>& terminate)
{
	ready.dequeue(*&run);
}

std::string SJF::getRDYPIDs()
{
	std::ostringstream oss;
    // bool first = true;
    // for (auto it = ready.begin(); it != ready.end(); ++it) {
    //     if (!first) {
    //         oss << ",";
    //     }
    //     oss << (*it)->getPID();
    //     first = false;
    // }
    return oss.str();	
}
int SJF::GetReadyCount()
{
	 int ReadyCount;
	 ReadyCount = ready.getcount();
	 return ReadyCount;
}
