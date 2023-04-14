# include <iostream>
// using namespace std;
# include <string>
# include "../include/UI.h"
# include <Windows.h>

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
	std::cin >> filee;
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
	
	std::cout << "Current Timestep:70" << std::endl;
	std::cout << "------------- RDY Processes -------------" << std::endl;

	std::cout << "------------- BLK Processes -------------" << std::endl;

	std::cout << "------------- RUN Processes -------------" << std::endl;

	std::cout << "------------- TRM Processes -------------" << std::endl;

	std::cout << "PRESS ANY KEY TO MOVE TO NEXT STEP !" << std::endl;
    std::cin.get();
}

void UI::silent()
{
	std::cout << "Silent Mode.........	Simulation Starts..." << std::endl;
	std::cout << "Simulation ends, Output file created" << std::endl;
}

void UI::detectenter()
{
	std::cin.get() == '\n';
}


