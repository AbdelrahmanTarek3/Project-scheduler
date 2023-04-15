#pragma once
// using namespace std;
# include "LinkedList.h"
# include "Process.h"

class Processor
{
private:
	int ID, RTF, MaxW, STL, FP;
	int totalCT;	
	int processid = 0;
	Process* p1;
public:
	// Processor();
	// Processor(int id, int rtf, int maxw, int stl, int fp);

	void setpid(int idd);
	virtual void setready(Process* p2) = 0;// the set ready pure virtual
	void setID(int id);
	void setRTF(int rtf);
	void setMaxW(int max);
	void setSTL(int stl);
	void setFP(int fp);
	void settotal(int t, int op);
	void readydel();
	virtual void ScheduleAlgo() = 0; // added the pure virtual function
	void print();
	virtual void printRDY() = 0;

	int getpid();
	int getID();
	int getRTF();
	int getMaxW();
	int getSTL();
	int getFP();
	int gettotal();
	Process* getready();
};