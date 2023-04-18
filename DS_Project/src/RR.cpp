# include <sstream>
# include "RR.h"
# include "Scheduler.h"
# include "Process.h"
# include "LinkedQueue.h"

RR::RR(int id, int rtf, int maxw, int stl, int fp, int TimeSlice)
 : Processor()
{
	setID(id);
	setRTF(rtf);
	setMaxW(maxw);
	setSTL(stl);
	setFP(fp);
	setTimeSlice(TimeSlice);

}

RR::RR()
{

}

RR::~RR()
{

}

void RR::setTimeSlice(int TimeSlice) 
{
	this->TimeSlice = TimeSlice;
}

int RR:: getTimeSlice()
{
	return TimeSlice;
}

void RR::setready(Process* px)
{
	ready.enqueue(px);
}

void RR::ScheduleAlgo(int current_time, PriorityQueue <Process*>& blocked, LinkedQueue <Process*>& terminate)

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
}


std::string RR::getRDYPIDs()
{
	std::ostringstream oss;
    // bool first = true;
    // for (auto it = ready.begin(); it != ready.end(); ++it) {
    //     if (!first) {
    //         oss << ",";
    //     }
    //     oss << (*it)->getPID();
    //     first = false;
    // }
    return oss.str();
}

int RR::GetReadyCount()
{
	int ReadyCount;
	ReadyCount = ready.getcount();
	return ReadyCount;
}