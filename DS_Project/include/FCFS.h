#pragma once
#include "Processor.h"
# include "Process.h"
class FCFS : public Processor
{
private:
	LinkedList <Process*> ready;
	// Process* run;

public:

	FCFS(int id, int rtf, int maxw, int stl, int fp);
	FCFS();
	~FCFS();
	virtual void ScheduleAlgo(int time, LinkedQueue <Process*>& terminate);
	void setready(Process* p1);
	// bool isBusy(Process* run);
	virtual int GetReadyCount();
	std::string getRDYPIDs();
};