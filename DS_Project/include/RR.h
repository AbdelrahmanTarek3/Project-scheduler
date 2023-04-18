#pragma once
#include "Processor.h"
# include "Process.h"
#include "LinkedQueue.h"
class RR : public Processor
{
private:
	LinkedQueue <Process*> ready;
	// Process* run;
	int TimeSlice;
public:

	RR(int id, int rtf, int maxw, int stl, int fp, int TimeSlice);
	RR();
	~RR();
	void setTimeSlice(int TimeSlice);
	int getTimeSlice();
	virtual void ScheduleAlgo(int time, PriorityQueue <Process*>& blocked, LinkedQueue <Process*>& terminate);
	void setready(Process* p1);
	bool isBusy(Process* run);

	std::string getRDYPIDs();
	virtual int GetReadyCount();
};