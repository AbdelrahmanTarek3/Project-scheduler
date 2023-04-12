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

	}
	input.close();
}