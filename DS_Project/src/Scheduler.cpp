# include <iostream>
using namespace std;
# include <string>
# include "Scheduler.h"
# include <fstream>

void Scheduler::simulate()
{

	int i = 1;
	//while (i != 0)	
	//{


	//	i++;
	//}

	points->startscreen();
	openfile();
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
		if (NIO != 0)
		{
			for (int j = 0; j < NIO; j++)
			{

			}
		}
	}
}

