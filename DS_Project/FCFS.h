#pragma once
#include "Processor.h"
# include "Process.h"
class FCFS : public Processor
{
private:
	LinkedList <Process*> ready;
	LinkedList <Process*> run;

public:

	FCFS(int id, int rtf, int maxw, int stl, int fp);
	FCFS() {}
	~FCFS();
	virtual void ScheduleAlgo();
	void SetReady(Process* p1);





};