# include <sstream>
# include "SJF.h"
# include "Scheduler.h"
# include "Process.h"
# include "PriorityQueue.h"

SJF::SJF(int id, int rtf, int maxw, int stl, int fp)
 : Processor()
{
	setID(id);
	setRTF(rtf);
	setMaxW(maxw);
	setSTL(stl);
	setFP(fp);
	setname("SJF");
}

SJF::SJF()
{

}

SJF::~SJF()
{

}

void SJF::setready(Process* px)
{
	
	ready.enqueue(px, 0);

}

void SJF:: ScheduleAlgo(int current_time, PriorityQueue <Process*>& blocked, LinkedQueue <Process*>& terminate)

{
	int random = std::rand() % 100 + 1;
	if (1 <= random && random <= 10)
	{
		// Move randomly blocked to ready
		// BEGIN: BLK
		if (!blocked.isEmpty())
		{
			Process* blocked_process;
			blocked.dequeue(blocked_process);
			setready(blocked_process);
		}
		// END: RDY
	}
	Process* running_process;
	if (isBusy(running_process))
	{
		if (1 <= random && random <= 15)
		{
			// Move randomly run to blocked
			// BEGIN: BLK
			run = nullptr;
			// Add to blocked queue
			blocked.enqueue(running_process, 0);
			// END: BLK
		}
		else if (20 <= random && random <= 30)
		{
			// Move randomly new to ready "Done"

		}
		else if (50 <= random && random <= 60)
		{
			// Move randomly run to terminate
			// BEGIN: TRM
			run = nullptr;
			running_process->setTT(current_time);
			// Add to terminate queue
			terminate.enqueue(running_process);
			// END: TRM
		}
		else {
			// BEGIN: RUN
			running_process->setremaining_time(running_process->getremaining_time(current_time) - 1);
			if (running_process->getremaining_time(current_time) == 0)
			{
				// BEGIN: TRM
				run = nullptr;
				running_process->setTT(current_time);
				// Add to terminate queue
				terminate.enqueue(running_process);
				// END: TRM
			}
			// END: RUN
		}
	}
	// moving from rdy to run by checking if the processor is busy
	if (!isBusy(running_process))
	{
		// First come "Front" First serve
		ready.dequeue(*&run);
	}
}

std::string SJF::getRDYPIDs()
{
	std::ostringstream oss;
	for (int i = 0; i < ready.getcount(); i++)
	{
		Process *p;
		ready.dequeue(p);
		oss << p->getPID();
		oss << ",";
		ready.enqueue(p, 0);
	}
    return oss.str();
}
int SJF::GetReadyCount()
{
	 int ReadyCount;
	 ReadyCount = ready.getcount();
	 return ReadyCount;
}
