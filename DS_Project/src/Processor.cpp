// using namespace std;
#include "../include/Processor.h"

Processor::Processor()
{
	run = nullptr;
}

// Processor::Processor(int id, int rtf, int maxw, int stl, int fp)
// {
// 	setID(id);
// 	setRTF(rtf);
// 	setMaxW(maxw);
// 	setFP(fp);
// 	setSTL(stl);
// }

void Processor::setFP(int ff)
{
	FP = ff;
}

void Processor::setID(int id)
{
	ID = id;
}

void Processor::setMaxW(int max)
{
	MaxW = max;
}

void Processor::setRTF(int rtf)
{
	RTF = rtf;
}

void Processor::setSTL(int stl)
{
	STL = stl;
}

void Processor::settotal(int t, int op)
{
	if (op == 1)
	{
		totalCT = totalCT + t;
	}
	else
	{
		totalCT = totalCT - t;
	}
}

int Processor::getFP()
{
	return FP;
}

int Processor::getID()
{
	return ID;
}

int Processor::getMaxW()
{
	return MaxW;
}

int Processor::getRTF()
{
	return RTF;
}

int Processor::getSTL()
{
	return STL;
}

int Processor::gettotal()
{
	return totalCT;
}

void Processor::print()
{

}
// void Processor::setready(Process* p2)
// {
// 	if (ready.isEmpty() == true)
// 	{
// 		ready.InsertBeg(p2);
// 	}
// 	else
// 	{
// 		ready.InsertEnd(p2);
// 	}
// }

// Process* Processor::getready()
// {
// 	ready.peekFront(p1);
// 	return p1;
// }

void Processor::setpid(int idd)
{
	processid = idd;
}

int Processor::getpid()
{
	return processid;
}

// void Processor::readydel()
// {
// 	if (ready.isEmpty() == false)
// 	{
// 		ready.DeleteFirst();
// 	}
// }

bool Processor::isBusy(Process*& run)
{
	if (this->run == nullptr)
		return false;
	run = this->run;
	return true;
}