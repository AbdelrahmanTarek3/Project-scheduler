#pragma once
class Process
{
private:
	// PID:
	// AT:
	// RT:
	// CT:
	// TT: Termination Time
	// TRT: 
	// WT:
	int PID, AT, RT, CT, TT, TRT, WT;
	// IO_number:
	// remaining_time:
	int IO_number, remaining_time;
	
	Process* next;
public:
	Process();
	Process(int at, int pid, int ct, int nio);
	
	void setPID(int i);
	int getPID();

	void setAT(int a);
	int getAT();
	
	void setRT(int r);
	int getRT();
	
	void setCT(int c);
	int getCT();
	
	void setTT(int t);
	int getTT();
	
	void setTRT(int tr);
	int getTRT();
	
	void setWT(int w);
	int getWT();
	
	void setIO_number(int io);
	int getIO_number();
	
	void setremaining_time(int rt);
	int getremaining_time(int time);
};

