# include <iostream>
using namespace std;
# include <string>
# include "Scheduler.h"
# include <fstream>
# include "Processor.h"
# include <cstdlib>

Scheduler::Scheduler()
{

}

void Scheduler::simulate()
{
	Process* p1;
	Processor* pp;
	int i = 1;
	points->startscreen();
	openfile();
	int count = 0;
	while (terminate.getcount() == NP)
	{
		while (newprocesses.peek(p1) && p1->getAT() == i)
		{
			if (FCFSN != 0)
			{
				FCFS.peek(pp);
				pp->setready(p1);
				pp->settotal(p1->getCT());
				FCFS.dequeue(pp);
				FCFS.enqueue(pp, pp->gettotal());
				check.InsertBeg(pp);
				newprocesses.dequeue(p1);
			}
			else if (SJFN != 0)
			{
				SJF.peek(pp);
				pp->setready(p1);
				pp->settotal(p1->getCT());
				SJF.dequeue(pp);
				SJF.enqueue(pp, pp->gettotal());
				check.InsertBeg(pp);
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
						check.DeleteFirst();
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

			}
		}

		i++;
	}


}


void Scheduler::openfile()
{
	string inputname = points->getfile();
	input.open(inputname, ios::in);
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
	Processor* p3;
	for (int i = 1; i <= FCFSN; i++)
	{
		pointer = new Processor(i, RTF, MAXW, STL, FP);
		FCFS.enqueue(pointer,0);
		FCFS.peek(p3);
	}
	for (int i = FCFSN; i <= (SJFN+FCFSN); i++)
	{
		pointer = new Processor(i, RTF, MAXW, STL, FP);
		SJF.enqueue(pointer, 0);
	}
	//for (int i = 1; i <= RRN; i++)
	//{

	//}
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

