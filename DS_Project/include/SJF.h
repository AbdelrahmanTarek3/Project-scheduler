#pragma once
#include "Processor.h"
# include "Process.h"
#include"PriorityQueue.h"
class SJF : public Processor
{
private:
	PriorityQueue<Process*> ready;
	Process* run;
public:
	SJF(int id, int rtf, int maxw, int stl, int fp);
	SJF();
	~SJF();
	virtual void ScheduleAlgo();
	virtual void SetReady(Process* p1);

};