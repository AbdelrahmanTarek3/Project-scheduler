#include <sstream>
#include <cstdlib>
#include "FCFS.h"
#include "Scheduler.h"
# include "Process.h"
#include "LinkedList.h"
FCFS::FCFS(int id, int rtf, int maxw, int stl, int fp)
 : Processor()
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
std::string FCFS::getRDYPIDs()
{
	std::ostringstream oss;
	Node<Process*>* curr;
	ready.peekHead(curr);
    while (curr != nullptr)
    {
        Process* p = curr->getItem();
		oss << p->getPID();
		if (curr->getNext() != nullptr)
			oss << ",";
        curr = curr->getNext();
    }
    return oss.str();
}


void FCFS::ScheduleAlgo(int current_time, PriorityQueue <Process*>& blocked, LinkedQueue <Process*>& terminate)
{
	int kill_process_id = std::rand();
	if (!ready.isEmpty())
	{
		Node<Process*>* iter;
		ready.peekHead(iter);
		while (iter != nullptr)
		{
			Process* p = iter->getItem();
			if (p->getPID() == kill_process_id)
			{
				// BEGIN: TRM
				// Add to terminate queue
				terminate.enqueue(p);
				// END: TRM
				ready.DeleteNode(p);
			}
			iter = iter->getNext();
		}
	}


	int random = std::rand() % 100 + 1;
	if (1 <= random && random <= 10)
	{
		// Move randomly blocked to ready
		// BEGIN: RDY
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
	if (!isBusy(running_process))
	{
		ready.peekFront(*&run); // should we peek and then delete?
		ready.DeleteFirst();
		if (run != nullptr)
			run->setremaining_time(run->getCT());
	}


}
int FCFS::GetReadyCount()
{
	int ReadyCount;
	ReadyCount = ready.getCount();
	return ReadyCount;
}