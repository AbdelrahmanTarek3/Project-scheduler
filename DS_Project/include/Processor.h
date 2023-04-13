#pragma once
using namespace std;


class Processor
{
private:
	int ID, RTF, MaxW, STL, FP;
	int totalCT;


public:
	Processor();
	Processor(int id, int rtf, int maxw, int stl, int fp);

	
	void setID(int id);
	void setRTF(int rtf);
	void setMaxW(int max);
	void setSTL(int stl);
	void setFP(int fp);
	void settotal(int t);

	int getID();
	int getRTF();
	int getMaxW();
	int getSTL();
	int getFP();
	int gettotal();
};