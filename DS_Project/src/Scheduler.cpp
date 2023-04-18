# include <iostream>
# include <string>
# include <cstdlib>
# include <fstream>
# include <ctime>
# include "Scheduler.h"
# include "Processor.h"
# include "FCFS.h"
# include "MyPair.h"


void Scheduler::simulate()
{
	ui->startscreen();
	readfile();
	srand(time(nullptr));

	if (TOTALprocessors != 0)
	{
		int time = 1;
		while (terminate.getcount() != NP)
		{
			std::cout << "Current Timestep:" << time << std::endl;

			// Move new processes with the arrival time == current time step to ready queue of the processor
			Process* queuefirstprocess;
			while (newprocesses.peek(queuefirstprocess) && queuefirstprocess->getAT() == time)
			{
				Processor* pp;
				processors.peek(pp);	// front processor
				pp->setready(queuefirstprocess);	// Move process to ready queue
				queuefirstprocess->setremaining_time(queuefirstprocess->getCT());
				pp->settotal(queuefirstprocess->getCT(), 1);	// Update total CPU time for the processor
				processors.dequeue(pp);	// remove front processor
				processors.enqueue(pp, 0);	// pp->gettotal() add as last processor
				
				newprocesses.dequeue(queuefirstprocess);	// remove the process from the front
			}
			// for (int i = 0; i < TOTALprocessors; i++)
			// {
			// 	Processor *p;
			// 	processors.dequeue(p);
			// 	if (p->getID() == 1)
				
			// 	processors.enqueue(p, 0); // p->gettotal()
			// }


			// Check for finished processes
			// Move ready processes to Run
			for (int i = 0; i < TOTALprocessors; i++)
			{
				Processor *p;
				processors.dequeue(p);
				p->ScheduleAlgo(time, blocked, terminate);
				processors.enqueue(p, 0); // p->gettotal()
			}

			// Print Ready for processors
			ui->printRDY(processors, TOTALprocessors);

			ui->printBLK(processors, TOTALprocessors, blocked);

			ui->printRUN(processors, TOTALprocessors);

			ui->printTRM(processors, TOTALprocessors, terminate);

			ui->printNextTimeStep();
			time++;
		}
	}
}


void Scheduler::readfile()
{
	std::string inputname = ui->getfile();
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
	TOTALprocessors = FCFSN + SJFN + RRN;

	for (int i = 1; i <= FCFSN; i++)
	{
		Processor* pointer = new FCFS(i, RTF, MAXW, STL, FP);
		processors.enqueue(pointer, 0);
	}
	for (int i = FCFSN+1; i <= (FCFSN+SJFN); i++)
	{
		Processor* pointer = new SJF(i, RTF, MAXW, STL, FP);
		processors.enqueue(pointer, 0);
	}
	for (int i = (FCFSN + SJFN + 1); i <= (FCFSN + SJFN + RRN); i++)
	{
		Processor* pointer = new RR(i, RTF, MAXW, STL, FP, TS);
		processors.enqueue(pointer, 0);
	}
}

void Scheduler::processesdata()
{
	input >> NP;
	for (int i = 0; i < NP; i++)
	{
		input >> AT >> PID >> CT >> NIO;
		Process* pointerr = new Process(AT, PID, CT, NIO);
		newprocesses.enqueue(pointerr);
		newprocesses.peek(pointerr);	// Check
		if (NIO != 0)
		{





			for (int j = 0; j < NIO; j++)
			{
				char c;
				char comma, comma1;
				int IO_R, IO_D;
				if (j != NIO - 1)
				{
					input >> c >> IO_R >> comma >> IO_D >> c >> comma1;
				}
				else
				{
					input >> c >> IO_R >> comma >> IO_D >> c;
				}
				MyPair pair(IO_R, IO_D);
				pairs.InsertBeg(pair);                                    //linked list best option??
			}
		}
	}
}

