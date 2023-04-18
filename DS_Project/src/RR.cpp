# include <sstream>
# include "RR.h"
# include "Scheduler.h"
# include "Process.h"
# include "LinkedQueue.h"

RR::RR(int id, int rtf, int maxw, int stl, int fp, int TimeSlice)
 : Processor()
{
	setID(id);
	setRTF(rtf);
	setMaxW(maxw);
	setSTL(stl);
	setFP(fp);
	setTimeSlice(TimeSlice);

}

RR::RR()
{

}

RR::~RR()
{

}

void RR::setTimeSlice(int TimeSlice) 
{
	this->TimeSlice = TimeSlice;
}

int RR:: getTimeSlice()
{
	return TimeSlice;
}

void RR::setready(Process* px)
{
	ready.enqueue(px);
}

void RR::ScheduleAlgo(int time, PriorityQueue <Process*>& blocked, LinkedQueue <Process*>& terminate)
{
	ready.dequeue(*&run); 
}
std::string RR::getRDYPIDs()
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

int RR::GetReadyCount()
{
	int ReadyCount;
	ReadyCount = ready.getcount();
	return ReadyCount;
}