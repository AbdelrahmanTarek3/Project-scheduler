#pragma once
#include "Processor.h"
# include "Process.h"
#include "LinkedQueue.h"
class RR : public Processor
{
private:
	LinkedQueue <Process*> ready;
	int TimeSlice;
public:

	RR(int id, int rtf, int maxw, int stl, int fp, int TimeSlice);
	RR();
	~RR();
	void setTimeSlice(int TimeSlice);
	int getTimeSlice();
	virtual void ScheduleAlgo(int current_time, PriorityQueue <Process*>& blocked, LinkedQueue <Process*>& terminate);
	void setready(Process* p1);

	std::string getRDYPIDs();
	virtual int GetReadyCount();
};