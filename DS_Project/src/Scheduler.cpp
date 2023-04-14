# include <iostream>
// using namespace std;
# include <string>
# include "Scheduler.h"
# include <fstream>
# include "Processor.h"
# include <cstdlib>
# include "FCFS.h"

Scheduler::Scheduler()
{

}

void Scheduler::simulate()
{
	Process* p1;
	Processor* pp;
	int i = 1;
	points->setcheck(check);
	points->startscreen();
	openfile();
	int count = 0;


	while (terminate.getcount() != NP)
	{
		while (newprocesses.peek(p1) && p1->getAT() == i)
		{
			if (TOTALprocessors != 0)
			{
				processors.peek(pp);
				pp->setready(p1);
				pp->settotal(p1->getCT(), 1);
				processors.dequeue(pp);
				processors.enqueue(pp, pp->gettotal());			
				if (check.isEmpty() == true)
				{
					check.InsertBeg(pp);
				}
				else
				{
					check.InsertEnd(pp);
				}
				newprocesses.dequeue(p1);
			}

		}
		if (check.isEmpty() == false)
		{
			while(check.peekFront(pp))
			{
				if (pp->getpid() == 0)
				{
					pp->setpid((pp->getready())->getPID());
					check.InsertEnd(pp);
					check.DeleteFirst();
				}
				else
				{
					srand(time(0));
					int random = ((rand() % (100 + 1)));
					if (random >= 1 && random <= 15)
					{
						blocked.enqueue(pp->getready());
						pp->readydel();
						pp->setpid(0);
						check.DeleteFirst();
						//change the total ct
					}
					else if (random >= 20 && random <= 30)
					{
						pp->setpid(0);
						check.DeleteFirst();
					}
					else if (random >= 50 && random <= 60)
					{
						terminate.enqueue(pp->getready());
						pp->readydel();
						pp->setpid(0);
						check.DeleteFirst();
					}
				}
			}
		}
		if (blocked.peek(p1))
		{
			srand(time(0));
			int random = ((rand() % (100 + 1)));
			if (random < 10)
			{
				if (FCFSN != 0)	// need to add another condiiton if all have process
				{
					FCFS.peek(pp);
					pp->setready(p1);
					pp->settotal(p1->getCT(),1);
					FCFS.dequeue(pp);
					FCFS.enqueue(pp, pp->gettotal());
					check.InsertBeg(pp);
					blocked.dequeue(p1);
				}
				else if (SJFN != 0)
				{
					SJF.peek(pp);
					pp->setready(p1);
					pp->settotal(p1->getCT(),1);
					SJF.dequeue(pp);
					SJF.enqueue(pp, pp->gettotal());
					check.InsertBeg(pp);
					blocked.dequeue(p1);
				}
			}
		}

		i++;
	}


}


void Scheduler::openfile()
{
	std::string inputname = points->getfile();
	input.open(inputname, std::ios::in);
	if (input.is_open() == true)
	{
		processordata();
		processesdata();
	}
	input.close();
}

void Scheduler::processordata()
{
	input >> FCFSN >> SJFN >> RRN >> TS >> RTF >> MAXW >> STL >> FP;
	Processor* pointer;
	TOTALprocessors = FCFSN + SJFN + RRN;

	for (int i = 1; i <= FCFSN; i++)
	{
		pointer = new FCFS(i, RTF, MAXW, STL, FP);
		processors.enqueue(pointer,0);
	}
	for (int i = FCFSN; i <= (SJFN+FCFSN); i++)
	{
		pointer = new SJF(i, RTF, MAXW, STL, FP);
		processors.enqueue(pointer, 0);
	}
	for (int i = (SJFN + FCFSN); i <= (SJFN + FCFSN + RRN); i++)
	{
		pointer = new RR(i, RTF, MAXW, STL, FP, TS);
		processors.enqueue(pointer, 0);
	}
}

void Scheduler::processesdata()
{
	Process* pointerr;
	input >> NP;
	for (int i = 0; i < NP; i++)
	{
		input >> AT >> PID >> CT >> NIO;
		pointerr = new Process(AT, PID, CT, NIO);
		newprocesses.enqueue(pointerr);
		newprocesses.peek(pointerr);
		//if (NIO != 0)
		//{
		//	for (int j = 0; j < NIO; j++)
		//	{

		//	}
		//}
	}
}

