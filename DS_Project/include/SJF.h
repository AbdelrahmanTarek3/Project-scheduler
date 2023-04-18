#pragma once
#include "Processor.h"
# include "Process.h"
#include"PriorityQueue.h"
class SJF : public Processor
{
private:
	PriorityQueue<Process*> ready;
	// Process* run;
public:
	SJF(int id, int rtf, int maxw, int stl, int fp);
	SJF();
	~SJF();
	virtual void ScheduleAlgo(int current_time, PriorityQueue <Process*>& blocked, LinkedQueue <Process*>& terminate);
	virtual void setready(Process* p1);
	// bool isBusy(Process* run);

	std::string getRDYPIDs();
	virtual int GetReadyCount();
};