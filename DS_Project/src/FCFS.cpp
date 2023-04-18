#include <sstream>
#include <cstdlib>
#include <ctime>
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
        // if (p->getStatus() == "ready")
        // {
            oss << p->getPID();
            if (curr->getNext() != nullptr)
                oss << ",";
        // }
        curr = curr->getNext();
    }
    return oss.str();
}


void FCFS::ScheduleAlgo(int current_time, PriorityQueue <Process*>& blocked, LinkedQueue <Process*>& terminate)
{
	// if (current_time == 3) {
	// 	std::cout << "2process in ready";
	// }
	// else if (current_time == 4) {
	// 	std::cout << "1pc in run, 1 rdy";
	// }
	// else if (current_time == 5) {
	// 	std::cout << "1 new, 2 trm";
	// }
	// else if (current_time == 6) {
	// 	std::cout << "1new, 1 run, 2 trm";
	// }
	// else if (current_time == 7) {
	// 	std::cout << "test";
	// }
	// else if (current_time == 8) {
	// 	std::cout << "test";
	// }
	// else if (current_time == 9) {
	// 	std::cout << "test";
	// }
	// else if (current_time == 10) {
	// 	std::cout << "test";
	// }
	// else if (current_time == 11) {
	// 	std::cout << "test";
	// }
	// else if (current_time == 12) {
	// 	std::cout << "test";
	// }
	// else if (current_time == 13) {
	// 	std::cout << "1 run, 3 trm";
	// }
	// else if (current_time == 14) {
	// 	std::cout << "4 trm";
	// }
	// else if (current_time == 15) {
	// 	std::cout << "4 trm";
	// }
	// else if (current_time == 16) {
	// 	std::cout << "4 trm";
	// }
	// else if (current_time == 17) {
	// 	std::cout << "4 trm";
	// }
	// else if (current_time == 18) {
	// 	std::cout << "4 trm";
	// }

	srand(time(0));
	int random = ((rand() % (100 + 1)));

	Process* current_process;
	if (isBusy(current_process))
	{
		if (1 <= random && random <= 15)
		{
			// Move randomly run to blocked
			// // BEGIN: BLK
			// run = nullptr;
			// // Add to blocked queue
			// blocked.enqueue(current_process, 0);
			// // END: BLK
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
			current_process->setTT(current_time);
			// Add to terminate queue
			terminate.enqueue(current_process);
			// END: TRM
		}
		else {
			// BEGIN: RUN
			current_process->setremaining_time(current_process->getremaining_time(current_time) - 1);
			if (current_process->getremaining_time(current_time) == 0)
			{
				// BEGIN: TRM
				run = nullptr;
				current_process->setTT(current_time);
				// Add to terminate queue
				terminate.enqueue(current_process);
				// END: TRM
			}
			// END: RUN
		}
	}
	if (!isBusy(current_process))
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
	ReadyCount =ready.getCount();
	return ReadyCount;
}