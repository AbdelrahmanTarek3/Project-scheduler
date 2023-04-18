#pragma once
#include "Processor.h"
# include "Process.h"
class FCFS : public Processor
{
private:
	LinkedList <Process*> ready;

public:

	FCFS(int id, int rtf, int maxw, int stl, int fp);
	FCFS();
	~FCFS();
	virtual void ScheduleAlgo(int time, PriorityQueue <Process*>& blocked, LinkedQueue <Process*>& terminate);
	void setready(Process* p1);
	virtual int GetReadyCount();
	std::string getRDYPIDs();
	void KillProcessId();
};