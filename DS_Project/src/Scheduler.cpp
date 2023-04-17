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
	ui->setcheck(check);
	ui->startscreen();
	openfile();
	// int count = 0;

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
				processors.enqueue(pp, pp->gettotal());	// add as last processor
				
				if (check.isEmpty() == true)
				{
					check.InsertBeg(pp);
				}
				else
				{
					check.InsertEnd(pp);
				}

				newprocesses.dequeue(queuefirstprocess);	// remove the process from the front
			}
			// Print Ready for processors
			ui->printRDY(processors, TOTALprocessors);
			// ui->printRDY(TOTALprocessors, processors, ....);						//done
			// this for loop goes to ui-> printRDY();



			// Check for finished processes
			// Move ready processes to Run   //Call here schedulerAlgo
			for (int i = 0; i < TOTALprocessors; i++)
			{
				Processor *p;
				processors.dequeue(p);
				p->ScheduleAlgo(time, terminate);
				processors.enqueue(p, p->gettotal());
			}

			// ui->printBLK();
			// blocked.print();

			ui->printRUN(processors, TOTALprocessors);							//done
			


			ui->printTRM(processors, TOTALprocessors, terminate);

		// if (check.isEmpty() == false)
		// {
		// 	while(check.peekFront(pp))
		// 	{
		// 		if (pp->getpid() == 0)
		// 		{
		// 			pp->setpid((pp->getready())->getPID());
		// 			check.InsertEnd(pp);
		// 			check.DeleteFirst();
		// 		}
		// 		else
		// 		{
		// 			srand(time(0));
		// 			int random = ((rand() % (100 + 1)));
		// 			if (random >= 1 && random <= 15)
		// 			{
		// 				blocked.enqueue(pp->getready());
		// 				pp->readydel();
		// 				pp->setpid(0);
		// 				check.DeleteFirst();
		// 				//change the total ct
		// 			}
		// 			else if (random >= 20 && random <= 30)
		// 			{
		// 				pp->setpid(0);
		// 				check.DeleteFirst();
		// 			}
		// 			else if (random >= 50 && random <= 60)
		// 			{
		// 				terminate.enqueue(pp->getready());
		// 				pp->readydel();
		// 				pp->setpid(0);
		// 				check.DeleteFirst();
		// 			}
		// 		}
		// 	}
		// }
		// if (blocked.peek(p1))
		// {
		// 	srand(time(0));
		// 	int random = ((rand() % (100 + 1)));
		// 	if (random < 10)
		// 	{
		// 		if (FCFSN != 0)	// need to add another condiiton if all have process
		// 		{
		// 			FCFS.peek(pp);
		// 			pp->setready(p1);
		// 			pp->settotal(p1->getCT(),1);
		// 			FCFS.dequeue(pp);
		// 			FCFS.enqueue(pp, pp->gettotal());
		// 			check.InsertBeg(pp);
		// 			blocked.dequeue(p1);
		// 		}
		// 		else if (SJFN != 0)
		// 		{
		// 			SJF.peek(pp);
		// 			pp->setready(p1);
		// 			pp->settotal(p1->getCT(),1);
		// 			SJF.dequeue(pp);
		// 			SJF.enqueue(pp, pp->gettotal());
		// 			check.InsertBeg(pp);
		// 			blocked.dequeue(p1);
		// 		}
		// 	}
			ui->printNextTimeStep();
			time++;
		}
	}
}


void Scheduler::openfile()
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
		processors.enqueue(pointer,0);
	}
	for (int i = FCFSN; i < (FCFSN+SJFN); i++)
	{
		Processor* pointer = new SJF(i, RTF, MAXW, STL, FP);
		processors.enqueue(pointer, 0);
	}
	for (int i = (FCFSN + SJFN); i < (FCFSN + SJFN + RRN); i++)
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
		// newprocesses.peek(pointerr); / Check with Usama
		//if (NIO != 0)
		//{
		//	for (int j = 0; j < NIO; j++)
		//	{

		//	}
		//}
	}
}

