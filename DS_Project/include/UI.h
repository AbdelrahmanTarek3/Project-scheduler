#pragma once
# include <iostream>
using namespace std;
# include <string>

class UI
{
private:
	string filename;
	int mode;

public:
	void startscreen();
	void printscreen();
	void interactive();
	void stepbystep();
	void silent();
	void setmode(int s);
	void setfile(string file);
	string getfile();
	void detectenter();

};