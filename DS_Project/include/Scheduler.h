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
# include "RR.h"
# include "FCFS.h"
# include "SJF.h"
// using namespace std;

class Scheduler
{
private:
	UI* points = new UI;
	std::ifstream input;
	int FCFSN, SJFN, RRN, TOTALprocessors;
	int TS;
	int RTF, MAXW, STL, FP;
	int NP, AT, PID, CT, NIO;

	LinkedQueue <Process*> newprocesses;		//done
	PriorityQueue <Process*> blocked;			//key is finishing time
	LinkedQueue <Process*> terminate;		//done
	LinkedList <Process*> orphan;			//done

	LinkedList <Processor*> check;
	
	PriorityQueue<Processor*>processors;


public:
	Scheduler();

	void simulate();
	void openfile();
	void processordata();
	void processesdata();
	
};