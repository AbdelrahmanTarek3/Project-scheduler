# include <iostream>
using namespace std;
# include <string>
# include "Scheduler.h"
# include <fstream>

void Scheduler::simulate()
{
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
	}
}

