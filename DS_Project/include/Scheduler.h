#pragma once
# include <string>
# include <iostream>
# include "UI.h"
# include <fstream>

using namespace std;

class Scheduler
{
private:
	UI* points = new UI;
	ifstream input;

public:
	void simulate();
	void openfile();
};