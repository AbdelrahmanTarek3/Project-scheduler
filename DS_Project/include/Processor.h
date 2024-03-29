#pragma once
# include "LinkedQueue.h"
# include "PriorityQueue.h"
# include "LinkedList.h"
# include "Process.h"

class Processor
{
protected:
	Process* run;
private:
	int ID, RTF, MaxW, STL, FP;
	// Total CPU Time gettotal, settotal
	int totalCT;	
	int processid = 0;
	std::string name;
public:
	Processor();

	void setpid(int idd);
	virtual void setready(Process* p2) = 0;// the set ready pure virtual
	void setID(int id);
	void setRTF(int rtf);
	void setMaxW(int max);
	void setSTL(int stl);
	void setFP(int fp);
	void settotal(int t, int op);
	void setname(std::string name);
	void readydel();

	virtual void ScheduleAlgo(int time, PriorityQueue <Process*>& blocked, LinkedQueue <Process*>& terminate) = 0; // added the pure virtual function
	void print();
	virtual std::string getRDYPIDs() = 0;
	std::string getname();
	bool isBusy(Process*& run);

	int getpid();
	int getID();
	int getRTF();
	int getMaxW();
	int getSTL();
	int getFP();
	int gettotal();
	virtual int GetReadyCount() = 0;

};