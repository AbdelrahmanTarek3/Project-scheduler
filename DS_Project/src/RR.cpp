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

void RR::SetReady(Process* px)
{
	ready.enqueue(px);
}

void RR::ScheduleAlgo()
{
	ready.dequeue(*&run); 
}

