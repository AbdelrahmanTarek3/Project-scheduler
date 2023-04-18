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
# include "MyPair.h"
# include "RR.h"
# include "FCFS.h"
# include "SJF.h"
// using namespace std;

class Scheduler
{
private:
	UI* ui = new UI;
	// input:	input file
	std::ifstream input;
	// FCFSN:	Count of FCFS processors
	// SJFN:	Count of SJFN processors
	// RRN:		Count of RRN processors
	// TOTALprocessors:		FCFSN+SJFN+RRN
	int FCFSN, SJFN, RRN, TOTALprocessors;
	// TS:		Timeslice for RR
	int TS;
	// RTF:		
	// MAXW:	
	// STL:		
	// FP:		
	int RTF, MAXW, STL, FP;
	// NP:		Count of processes
	// AT:		Arrival time of the process
	// PID:		Process ID
	// CT:		CPU time for the process
	// NIO:		Numer of I/O pairs	
	int NP, AT, PID, CT, NIO;

	LinkedQueue <Process*> newprocesses;	// new processes list
	PriorityQueue <Process*> blocked;	    //key is finishing time
	LinkedQueue <Process*> terminate;		//done
	LinkedList <Process*> orphan;			//done

	LinkedList <Processor*> check;
	
	PriorityQueue<Processor*>processors;
	LinkedList <MyPair> pairs;


public:
	Scheduler();

	void simulate();
	void openfile();
	void processordata();
	void processesdata();
	
};