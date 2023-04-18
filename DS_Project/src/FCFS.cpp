#include <sstream>
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


void FCFS::ScheduleAlgo(int time, LinkedQueue <Process*>& terminate)
{
	// if (time == 3) {
	// 	std::cout << "2process in ready";
	// }
	// else if (time == 4) {
	// 	std::cout << "1pc in run, 1 rdy";
	// }
	// else if (time == 5) {
	// 	std::cout << "1 new, 2 trm";
	// }
	// else if (time == 6) {
	// 	std::cout << "1new, 1 run, 2 trm";
	// }
	// else if (time == 7) {
	// 	std::cout << "test";
	// }
	// else if (time == 8) {
	// 	std::cout << "test";
	// }
	// else if (time == 9) {
	// 	std::cout << "test";
	// }
	// else if (time == 10) {
	// 	std::cout << "test";
	// }
	// else if (time == 11) {
	// 	std::cout << "test";
	// }
	// else if (time == 12) {
	// 	std::cout << "test";
	// }
	// else if (time == 13) {
	// 	std::cout << "1 run, 3 trm";
	// }
	// else if (time == 14) {
	// 	std::cout << "4 trm";
	// }
	// else if (time == 15) {
	// 	std::cout << "4 trm";
	// }
	// else if (time == 16) {
	// 	std::cout << "4 trm";
	// }
	// else if (time == 17) {
	// 	std::cout << "4 trm";
	// }
	// else if (time == 18) {
	// 	std::cout << "4 trm";
	// }

	Process* current_process;
	if (isBusy(current_process))
	{
		current_process->setremaining_time(current_process->getremaining_time(time) - 1);
		if (current_process->getremaining_time(time) == 0)
		{
			// terminate
			run = nullptr;
			current_process->setTT(time);
			// Add to terminate queue
			terminate.enqueue(current_process);
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