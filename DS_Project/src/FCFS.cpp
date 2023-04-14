#include "FCFS.h"
#include "Scheduler.h"
# include "Process.h"
#include "LinkedList.h"
FCFS::FCFS(int id, int rtf, int maxw, int stl, int fp)
{
	setID(id);
	setRTF(rtf);
	setMaxW(maxw);
	setSTL(stl);
	setFP(fp);

}

FCFS::FCFS()
{

}

FCFS::~FCFS()
{

}

void FCFS::setready(Process* px)
{
	
	if(ready.isEmpty() == true)
	{
		ready.InsertBeg(px);
	}
	else
	{
		ready.InsertEnd(px);
	}
}

void FCFS::ScheduleAlgo()
{
	ready.peekFront(*&run); // should we peek and then delete?
}

