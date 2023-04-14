#include"RR.h"
#include "Scheduler.h"
# include "Process.h"
#include "LinkedQueue.h";
RR::RR(int id, int rtf, int maxw, int stl, int fp, int TimeSlice)
{
	setID(id);
	setRTF(rtf);
	setMaxW(maxw);
	setSTL(stl);
	setFP(fp);
	setTimeSlice(TimeSlice);

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

void RR::ScheduleAlgo()
{
	ready.dequeue(*&run); 
}

