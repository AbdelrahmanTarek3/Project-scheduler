#pragma once
# include <string>
# include <iostream>
# include "UI.h"
# include <fstream>
# include "LinkedQueue.h"
# include "QueueADT.h"
# include "Processor.h"
# include "Process.h"
# include "LinkedList.h"
# include "PriorityQueue.h"
using namespace std;

class Scheduler
{
private:
	UI* points = new UI;
	ifstream input;
	int FCFSN, SJFN, RRN, TOTALprocessors;
	int TS;
	int RTF, MAXW, STL, FP;
	int NP, AT, PID, CT, NIO;

	LinkedQueue <Process*> newprocesses;
	LinkedQueue <Process*> blocked;
	LinkedQueue <Process*> terminate;
	LinkedList <Process*> orphan;
	LinkedList <Processor*> check;
	PriorityQueue<Processor*>FCFS;
	PriorityQueue<Processor*>RR;
	PriorityQueue<Processor*>SJF;
	//PriorityQueue <Process*>ss;

public:
	Scheduler();

	void simulate();
	void openfile();
	void processordata();
	void processesdata();
	
};