#pragma once
# include <iostream>
# include <string>
# include "LinkedList.h"
# include "Processor.h"
#include"PriorityQueue.h"

class UI
{
private:
	std::string filename;
	int mode;
	LinkedList <Processor*> check;
public:
	UI();
	void startscreen();
	void printscreen();
	void interactive();
	void stepbystep();
	void silent();
	void setmode(int s);
	void setcheck(LinkedList <Processor*> check);
	void setfile(std::string file);
	std::string getfile();
	void detectenter();


	void printRDY(PriorityQueue<Processor*>& processors, int TOTALprocessors);
	void printBLK();
	void printRUN(PriorityQueue<Processor*>& processors, int TOTALprocessors);
	void printTRM(PriorityQueue<Processor*>& processors, int TOTALprocessors, LinkedQueue <Process*>& terminate );
	void printNextTimeStep();
	void printProcessorProceesesRDY(Processor*processor);

};