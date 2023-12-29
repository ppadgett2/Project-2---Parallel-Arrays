// Author: Parker Padgett
// Assignment: Parallel Arrays
// Description: Create array variables to store a persons information and output an unknown number of inputs to the screen
// Date: 1/31/2022


#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <cctype>
#include <fstream>

using namespace std;

// Constants
const int ARRAY_SIZE = 5;

// Function Declaration
void inputCheck(ifstream& inFile);
int getData(ifstream& inFile, string fName[], string lName[], string address[], string city[], string state[], string zip[],
	string phoneNumber[], string movie[], string snack[], string favCity[]);
void output(int counter, string fName[], string lName[], string address[], string city[], string state[], string zip[],
	string phoneNumber[], string movie[], string snack[], string favCity[]);
void closeFile(ifstream& inFile);

int main()
{
	//Variable declaration
	string fName[ARRAY_SIZE];
	string lName[ARRAY_SIZE];
	string address[ARRAY_SIZE];
	string city[ARRAY_SIZE];
	string state[ARRAY_SIZE];
	string zip[ARRAY_SIZE];
	string phoneNumber[ARRAY_SIZE];
	string movie[ARRAY_SIZE];
	string snack[ARRAY_SIZE];
	string favCity[ARRAY_SIZE];
	int counter = 0;
	ifstream inFile;

	//Title and description
	cout << "Title: Parallel Arrays" << endl;
	cout << "Description: Create array variables to store a persons information and output an unknown number of inputs to the screen" << endl << endl;
	//Open input file
	inFile.open("inFile.txt");

	// Check to see if infile was found
	inputCheck(inFile);

	// Input first name, last name, ect into arrays using getline
	counter = getData(inFile, fName, lName, address, city, state, zip, phoneNumber, movie, snack, favCity);

	//Output
	output(counter, fName, lName, address, city, state, zip, phoneNumber, movie, snack, favCity);

	// Close file
	closeFile(inFile);

	return 0;
}

void inputCheck(ifstream& inFile)
{
	if (inFile)
		cout << "Input File was found" << endl << endl;
	else
	{
		cout << "Input File was not found" << endl << endl;
		exit(1);
	}
}

int getData(ifstream& inFile, string fName[], string lName[], string address[], string city[], string state[], string zip[],
	string phoneNumber[], string movie[], string snack[], string favCity[])
{
	int counter = 0;
	while (!inFile.eof())
	{
		getline(inFile, fName[counter]);
		getline(inFile, lName[counter]);
		getline(inFile, address[counter]);
		getline(inFile, city[counter]);
		getline(inFile, state[counter]);
		getline(inFile, zip[counter]);
		getline(inFile, phoneNumber[counter]);
		getline(inFile, movie[counter]);
		getline(inFile, snack[counter]);
		getline(inFile, favCity[counter]);
		counter++;
	}
	return counter;
}

void output(int counter, string fName[], string lName[], string address[], string city[], string state[], string zip[],
	string phoneNumber[], string movie[], string snack[], string favCity[])
{
	for (int i = 0; i < counter; i++)
	{
		if (fName[i] == "Parker")
			cout << "Hey thats my name!" << endl;
		cout << "First Name: " << fName[i] << endl;
		cout << "Last Name: " << lName[i] << endl;
		cout << "Address: " << address[i] << endl;
		cout << "City: " << city[i] << endl;
		cout << "State: " << state[i] << endl;
		cout << "Zip: " << zip[i] << endl;
		cout << "Phone Number: " << phoneNumber[i] << endl;
		cout << "Favorite Movie: " << movie[i] << endl;
		cout << "Favorite Snack: " << snack[i] << endl;
		cout << "Favorite City: " << favCity[i] << endl << endl;
	}
}

void closeFile(ifstream& inFile)
{
	inFile.close();
}