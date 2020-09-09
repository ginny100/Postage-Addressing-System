//Khue Dang
//Lab 4 Out
//A postage addressing system 

#include <iostream>
#include <string>
#include <cctype>
#include "graph1.h"
#include <iomanip>

using namespace std;

//Function prototypes
string getString(string prompt);
bool validateName(string name);
bool validateAddress(string address);
bool validateCity(string city);
bool validateState(string state);
bool validateZip(string zip);
string convertToUpper(string input);
void displayLetter(string fn, string ln, string addr, string city, string state, string zip, int weight);

int main()
{
	//Variable Declaration/Initialization
	string f_name = "";
	string l_name = "";
	string dummy;
	string address = "";
	string city = "";
	string state = "";
	string zip = "";
	int weight = 0;
	bool res = false;
	char repeat = 'y';

	//Displays graphics window
	displayGraphics();

	do
	{
		//Processes first name info
		do
		{
			//Prompts for the first and last name 
			f_name = getString("Enter First Name: ");
			//validates the first and last name
			res = validateName(f_name);
		} while (!res);

		//Processes first name info
		do
		{
			//Prompts for the first and last name 
			l_name = getString("Enter Last Name: ");
			//validates the first and last name
			res = validateName(l_name);
		} while (!res);

		//Processes the address info
		do
		{
			//Gets the address
			address = getString("Enter Street Address: ");
			//validates the address
			res = validateAddress(address);
		} while (!res);

		//Processes city info
		do
		{
			//Gets the city name
			city = getString("Enter City: ");
			//validates the city name
			res = validateCity(city);
		} while (!res);

		//Processes state info
		do
		{
			//Gets the state
			state = getString("Enter State: ");
			//validates the state
			res = validateState(state);
		} while (!res);

		//Processes zip code info
		do
		{
			//Gets the zip code
			zip = getString("Enter Zip Code: ");
			//validates the city name
			res = validateZip(zip);
		} while (!res);

		//Prompts for weight
		do
		{
			cout << "Enter weight: ";
			cin >> weight;
			if (weight < 1 || weight > 6)
				cout << "Invalid input. Please re-enter." << endl;
		} while (weight < 1 || weight > 6);

		//Converts the state to all uppercase
		state = convertToUpper(state);

		//Displays the letter
		displayLetter(f_name, l_name, address, city, state, zip, weight);

		//Prompts repeat
		cout << "Repeat program? (y/n) ";
		cin >> repeat;
		cout << endl;
		getline(cin, dummy);

		//Clears the Graphics and Console
		clearGraphics();
		system("cls");

	} while (repeat == 'Y' || repeat == 'y');
	return 0;
}

//Prompts for input based on input parameter prompt
string getString(string prompt)
{
	string user_input = "";
	//Prompts user for name using getline (prompt contains the message displayed to user))
	cout << prompt;
	getline(cin, user_input);
	return user_input;
}

//Validates characters of name
bool validateName(string name)
{
	int i = 0;
	//Validates the name – returns true if valid, false if not
	if (name == "")
	{
		cout << "Invalid input. Please re-enter." << endl;
		return false;
	}
	for (i = 0; i < (int)name.length(); i++)
	{
		if (isalpha(name[i]) == 0)
			if (isspace(name[i]) == 0)
			{
				cout << "Invalid input. Please re-enter." << endl;
				return false;
			}
	}
}

//Validates characters of address
bool validateAddress(string address)
{
	int i = 0;
	//Validates the address – returns true if valid, false if not
	if (address == "")
	{
		cout << "Invalid input. Please re-enter." << endl;
		return false;
	}
	for (i = 0; i < (int)address.length(); i++)
	{
		if (isalnum(address[i]) == 0)
			if (isspace(address[i]) == 0)
			{
				cout << "Invalid input. Please re-enter." << endl;
				return false;
			}
	}
}

//Validates characters of city
bool validateCity(string city)
{
	int i = 0;
	//Validates the address – returns true if valid, false if not
	if (city == "" || isupper(city[0]) == 0)
	{
		cout << "Invalid input. Please re-enter." << endl;
		return false;
	}
	for (i = 0; i < (int)city.length(); i++)
	{
		if (isalnum(city[i]) == 0)
			if (isspace(city[i]) == 0)
			{
				cout << "Invalid input. Please re-enter." << endl;
				return false;
			}
	}
}

//Validates characters of state
bool validateState(string state)
{
	int i = 0;
	//Validates the address – returns true if valid, false if not
	if (state.length() != 2)
	{
		cout << "Invalid input. Please re-enter." << endl;
		return false;
	}
	for (i = 0; i < (int)state.length(); i++)
		if (isalpha(state[i]) == 0)
		{
			cout << "Invalid input. Please re-enter." << endl;
			return false;
		}
}

//Validates characters of zip
bool validateZip(string zip)
{
	int i = 0;
	//Validates the address – returns true if valid, false if not
	if (zip.length() != 5)
	{
		cout << "Invalid input. Please re-enter." << endl;
		return false;
	}
	for (i = 0; i < (int)zip.length(); i++)
		if (isdigit(zip[i]) == 0)
		{
			cout << "Invalid input. Please re-enter." << endl;
			return false;
		}
}

//Converts text to uppercase
string convertToUpper(string input)
{
	//Converts input to all uppercase
	for (int i = 0; i < (int)input.length(); i++)
	{
		input[i] = toupper(input[i]);
	}
	//Returns converted input
	return input;
}

//Displays the letter
void displayLetter(string fn, string ln, string addr, string city, string state, string zip, int weight)
{
	//Computes the cost
	double cost = weight * 0.47;
	//Displays the envelope
	displayBMP("envelope.bmp", 0, 0);
	displayBMP("returnAddress.bmp", 43, 26);
	//Displays entered information
	gout << setPos(315, 210) << setColor(0, 225, 0) << fn << " " << ln << endg;
	gout << setPos(315, 225) << setColor(0, 225, 0) << addr << endg;
	gout << setPos(315, 240) << setColor(0, 225, 0) << city << ", " << state << " " << zip << endg;
	//Displays the stamps
	for (int i = 0; i < weight; i++)
	{
		if (i < 3)
			displayBMP("stamp.bmp", 525 - 75*i, 20);
		else
			displayBMP("stamp.bmp", 525 - 75*(i-3), 99);
	}
	//Displays a summary box
	drawLine(200, 385, 490, 385, 2);
	drawLine(200, 385, 200, 470, 2);
	drawLine(200, 470, 490, 470, 2);
	drawLine(490, 385, 490, 470, 2);
	gout << setPos(205, 400) << setColor(0, 225, 0) << "Weight: " << weight << " ounces" << endg;
	gout << setPos(205, 420) << setColor(0, 225, 0) << "Cost of First Class Stamp: 47 Cents " << endg;
	gout << setPos(205, 440) << setColor(0, 225, 0) << "Total Mailing Cost $" << setPrecision(2) << cost << endg;
}