# include <iostream>
using namespace std;
# include <string>
# include "../include/UI.h"
# include <Windows.h>
void UI::startscreen()
{
	cout << endl << "					Welcome to the super processor" << endl << endl;
	int n;
	cout << "Please choose the printing mode you want by writing its number only: " << endl;
	cout << "1.Interactive Mode       2.Step By Step Mode               3.Silent Mode" << endl;
	cout << "Number: ";
	cin >> n;
	cout << endl;
	setmode(n);

	cout << "Please enter the input file of your data in the following format (filename.txt): ";
	string filee;
	cin >> filee;
	setfile(filee);
	
	//cout << "Thanks for your patience,";
	//cout << endl << "Your file name is : " << filename << " and the print mode is : ";
	//if (mode == 1)
	//{
	//	cout << "Interactive Mode";
	//}
	//else if (mode == 2)
	//{
	//	cout << "Step By Step Mode";
	//}
	//else
	//{
	//	cout << "Silent Mode";
	//}
	cout << endl;
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

void UI::setfile(string file)
{
	filename = file;
}

string UI::getfile()
{
	return filename;
}

void UI::stepbystep()
{
	Sleep(1000);
}

void UI::interactive()
{

}

void UI::silent()
{
	cout << "Silent Mode.........	Simulation Starts..." << endl;
	cout << "Simulation ends, Output file created" << endl;
}

void UI::detectenter()
{
	cin.get() == '\n';
}


