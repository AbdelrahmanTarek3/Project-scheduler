#pragma once
# include <iostream>
// using namespace std;
# include <string>

class UI
{
private:
	std::string filename;
	int mode;

public:
	void startscreen();
	void printscreen();
	void interactive();
	void stepbystep();
	void silent();
	void setmode(int s);
	void setfile(std::string file);
	std::string getfile();
	void detectenter();

};