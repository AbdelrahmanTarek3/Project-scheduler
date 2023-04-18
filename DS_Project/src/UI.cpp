# include <iostream>
// using namespace std;
# include <string>
# include "../include/UI.h"
# include <Windows.h>
#include"PriorityQueue.h"
#include"Processor.h"

UI::UI()
{
	setmode(1);
}

void UI::startscreen()
{
	//std::cout << std::endl << "					Welcome to the super processor" << std::endl << std::endl;
	//int n;
	//std::cout << "Please choose the printing mode you want by writing its number only: " << std::endl;
	//std::cout << "1.Interactive Mode       2.Step By Step Mode               3.Silent Mode" << std::endl;
	//std::cout << "Number: ";
	//std::cin >> n;
	//std::cout << std::endl;
	//setmode(n);

	std::cout << "Please enter the input file of your data in the following format (filename.txt): ";
	std::string filee;
	// std::cin >> filee;
	filee = "fcfs.txt";
	setfile(filee);
	
	//std::cout << "Thanks for your patience,";
	//std::cout << std::endl << "Your file name is : " << filename << " and the print mode is : ";
	//if (mode == 1)
	//{
	//	std::cout << "Interactive Mode";
	//}
	//else if (mode == 2)
	//{
	//	std::cout << "Step By Step Mode";
	//}
	//else
	//{
	//	std::cout << "Silent Mode";
	//}
	std::cout << std::endl;
	printscreen();
}

void UI::printscreen()
{
	if (mode == 1)
	{
		interactive();
	}
	else if (mode == 2)
	{
		stepbystep();
	}
	else
	{
		silent();
	}
}

void UI::setmode(int ss)
{
	mode = ss;
}

void UI::setfile(std::string file)
{
	filename = file;
}

std::string UI::getfile()
{
	return filename;
}

void UI::stepbystep()
{
	Sleep(1000);
}

void UI::setcheck(LinkedList <Processor*> check)
{
	this->check = check;
}

void UI::interactive()
{
	
}

void UI::silent()
{
	std::cout << "Silent Mode.........	Simulation Starts..." << std::endl;
	std::cout << "Simulation ends, Output file created" << std::endl;
}

void UI::detectenter()
{
	std::cin.get();
}




void UI::printRDY(PriorityQueue<Processor*>& processors, int TOTALprocessors){
	std::cout << "------------- RDY Processes -------------" << std::endl;
	for (int i = 0; i < TOTALprocessors; i++)
	{
		Processor* p;
		processors.dequeue(p);
		// p->printRDY(); goes to another function in ui from FCFS
		// printProcessorProcesses(processor )					// function inside ui : takes processor , print processes inside processor
		printProcessorProceesesRDY(p);

		processors.enqueue(p, p->gettotal());
	}
}
void UI::printBLK(PriorityQueue<Processor*>& processors, int TOTALprocessors, PriorityQueue <Process*>& block){
	std::cout << "------------- BLK Processes -------------" << std::endl;
	std::cout << block.getcount() << " BLK: ";
	for (int i = 0; i < block.getcount(); i++)
	{
		Process* proc;
		block.peek(proc);
		std::cout << proc->getPID() << ", ";
		block.dequeue(proc);
		block.enqueue(proc, 0);
	}
	std::cout << std::endl;

}
void UI::printRUN(PriorityQueue<Processor*>& processors, int TOTALprocessors){
	std::cout << "------------- RUN Processes -------------" << std::endl;
	int running_count = 0;
	for (int i = 0; i < TOTALprocessors; i++)
	{
		Processor* p;
		processors.dequeue(p);
		Process* running;
		if (p->isBusy(running))
			running_count += 1;
		processors.enqueue(p, p->gettotal());
	}
	std::cout << running_count << " RUN: ";
	for (int i = 0; i < TOTALprocessors; i++)
	{
		Processor* p;
		processors.dequeue(p);
		Process* running;
		if (p->isBusy(running))
			std::cout << running->getPID() << "(P" << p->getID() << "), ";
		processors.enqueue(p, p->gettotal());
	}
	std::cout << std::endl;
}
void UI::printTRM(PriorityQueue<Processor*>& processors, int TOTALprocessors, LinkedQueue <Process*>& terminate){
	std::cout << "------------- TRM Processes -------------" << std::endl;
	std::cout << terminate.getcount() << " TRM: ";
	for (int i = 0; i < terminate.getcount(); i++)
	{
		Process* proc;
		terminate.peek(proc);
		std::cout << proc->getPID() << ", ";
		terminate.dequeue(proc);
		terminate.enqueue(proc);
	}
	std::cout << std::endl;
}
void UI::printNextTimeStep(){
	std::cout << "PRESS ANY KEY TO MOVE TO NEXT STEP !" << std::endl;
    // std::cin.get();

}
void UI::printProcessorProceesesRDY(Processor* processor)
{

	// print 	processor 1 [FCFS]: 7 RDY: 12, 113, 116, 245, 9, 105, 75
	std::cout << "processor " << processor->getID() << " [FCFS]: " << processor->GetReadyCount() << " RDY: ";
	// ready.PrintList();
	if (processor->GetReadyCount() > 0)
	{
		Node<Process*>* p;
		std::string pids = processor->getRDYPIDs();
		std::cout << pids;
		// ready.peekHead(p);
		// while (p)
		// {
		// 	std::cout << p->getItem()->getPID();
		// 	std::cout << ", ";
		// 	p = p->getNext();
		// }
	}
	std::cout << std::endl;

}
