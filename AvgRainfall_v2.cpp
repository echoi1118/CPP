/*

ID block
---------------------------------------------------
+ Programmer  : Esther Choi							
+ Course      : Computer Science 1	    			
+ Lab Section :	0101 (MW at 10 am)	       			
+ Grader      :	M. Ghyam							
+ Assignment  :	Average Rainfall Calculator			
+ Due Date    : December 2, 2015					
---------------------------------------------------

Program statement:	This program calculates the average rainfall
			for one or more cities during a 12-month period.
			
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>
#include <windows.h>

#define CAP 50
#define SIZE 12

using namespace std;

struct CityInfo
{
	int noRainfallCount;
	double avgRainfall,
		inchesOfRain[SIZE],
		lowestRainfall,
		highestRainfall;
	string cityName,
		noRainfall[SIZE],
		lowestRainfallMonth,
		highestRainfallMonth;
};

bool emptyFileCheck(ifstream&);
int processDataFile(CityInfo[], int, ifstream&, ofstream&, string&);
void calcAvgRainfall(CityInfo[], int);
void findHighestAndLowestRainfall(CityInfo[], int, string[]);
void findNoRainfall(CityInfo[], int, string[]);
void openInputFile(ifstream&);
void openOutputFile(ifstream&, ofstream&, string&);
void printFooter();
void printHeadertoMonitor();
void printHeadertoOutputFile(ofstream&);
void printHistogram(ofstream&, CityInfo[], int, string[], int&);
void printIntro(ofstream&, int, string);
void printResults(ofstream&, CityInfo[], int, string[], int&);

int main()
{
	int count = 0,
		citySize;
	ifstream fin;
	ofstream fout;
	CityInfo city[CAP];
	string nameOfPreparer,
		months[SIZE] =
		{ "January", "February", "March", "April",
		"May", "June", "July", "August",
		"September", "October", "November", "December" };

	printHeadertoMonitor();
	openInputFile(fin);
	citySize = processDataFile(city, CAP, fin, fout, nameOfPreparer);
	calcAvgRainfall(city, citySize);
	findHighestAndLowestRainfall(city, citySize, months);
	findNoRainfall(city, citySize, months);
	printIntro(fout, citySize, nameOfPreparer);
	printResults(fout, city, citySize, months, count);
	printFooter();

	return 0;
}

void printHeadertoMonitor()
{
	// This function prints the program name and information to the monitor

	cout << left << fixed << showpoint << setprecision(2);
	cout << "\n" << setw(25) << "" << "Average Rainfall Calculator\n\n";
	cout << "This program calculates the rainfall data for one or more cities during a 12-\n"
		<< "month period." << endl;
}

void printHeadertoOutputFile(ofstream &fout)
{
	// This function prints the program name and information to output.txt

	fout << left << fixed << showpoint << setprecision(2);
	fout << "\n" << setw(25) << "" << "Average Rainfall Calculator\n\n";
	fout << "The following is a compilation of rainfall data for one or more cities during\n"
		<< "a 12-month period." << endl;
}

void openInputFile(ifstream &fin)
{
	// This function verifies that the input file exists and can be accessed

	string fileName;

	cout << "\n" << setw(40) << "Enter input file name including path:";
	getline(cin, fileName);
	fin.open(fileName.c_str());

	while (fin.fail())
	{
		cout << "\n\tA file with that name does not exist. Verify that";
		cout << "\n\tthe name and/or location are correct and try again.\n\n";

		cout << setw(40) << "Enter input file name including path:";
		getline(cin, fileName);
		fin.open(fileName.c_str());
	}
}

int processDataFile(CityInfo city[], int cityCap, ifstream &fin, ofstream &fout, string &nameOfPreparer)
{
	// This function fills the arrays with data from the file

	int outerCount = 0,
		innerCount = 0;

	getline(fin, city[outerCount].cityName);
	openOutputFile(fin, fout, nameOfPreparer);

	while (outerCount < cityCap && !fin.eof())
	{
		for (innerCount = 0; innerCount < SIZE; innerCount++)
			fin >> city[outerCount].inchesOfRain[innerCount];
		outerCount++;
		fin.ignore(100, '\n');
		getline(fin, city[outerCount].cityName);
	}
	fin.close();

	return outerCount;
}

void openOutputFile(ifstream &fin, ofstream &fout, string &nameOfPreparer)
{
	// This function terminates the program on an empty input file or asks for
	// preparer's name and opens output file

	if (emptyFileCheck(fin))
	{
		cout << "\n\tThe specified input file is empty.\n"
			<< "\tProgram has been terminated. :(\n\n";
		exit(0);
	}
	else
	{
		cout << setw(40) << "Enter your name:";
		getline(cin, nameOfPreparer);
		fout.open("output.txt");
		printHeadertoOutputFile(fout);
	}
}

bool emptyFileCheck(ifstream &fin)
{
	// This function returns true if the file is empty

	bool result;

	if (fin.eof())
		result = true;
	else
		result = false;

	return result;
}

void printIntro(ofstream &fout, int citySize, string nameOfPreparer)
{
	// This function prints the report introduction including the name of the preparer
	// to the monitor and output.txt

	cout << "\n" << setw(20) << "" << "_______________________________________" << endl;
	fout << "\n" << setw(20) << "" << "_______________________________________" << endl;

	if (citySize == 1)
	{
		cout << "\n" << setw(25) << "" << "Rainfall Report for " << citySize << " City" << endl;
		fout << "\n" << setw(25) << "" << "Rainfall Report for " << citySize << " City" << endl;
	}
	else
	{
		cout << "\n" << setw(25) << "" << "Rainfall Report for " << citySize << " Cities" << endl;
		fout << "\n" << setw(25) << "" << "Rainfall Report for " << citySize << " Cities" << endl;
	}
	cout << setw(25) << "" << "Prepared by: " << nameOfPreparer << endl;
	fout << setw(25) << "" << "Prepared by: " << nameOfPreparer << endl;
	
	cout << setw(20) << "" << "_______________________________________\n\n";
	fout << setw(20) << "" << "_______________________________________\n\n";
}

void calcAvgRainfall(CityInfo city[], int citySize)
{
	// This function calculates and returns the average rainfall

	double totalRainfall = 0;

	for (int outerCount = 0; outerCount < citySize; outerCount++)
	{
		for (int innerCount = 0; innerCount < SIZE; innerCount++)
			totalRainfall += city[outerCount].inchesOfRain[innerCount];			// Sum all the array elements
		city[outerCount].avgRainfall = totalRainfall / SIZE;					// Calculate the average rainfall
		totalRainfall = 0;														// Reset accumulation for next city
	}
}

void findHighestAndLowestRainfall(CityInfo city[], int citySize, string months[])
{
	// This function finds and returns the highest rainfall and lowest rainfall values

	int innerCount = 0;

	for (int outerCount = 0; outerCount < citySize; outerCount++)
	{
		city[outerCount].highestRainfall = city[outerCount].lowestRainfall = city[outerCount].inchesOfRain[innerCount];
		city[outerCount].highestRainfallMonth = city[outerCount].lowestRainfallMonth = months[innerCount];

		for (innerCount = 0; innerCount < SIZE; innerCount++)
		{
			if (city[outerCount].highestRainfall < city[outerCount].inchesOfRain[innerCount])
			{
				city[outerCount].highestRainfall = city[outerCount].inchesOfRain[innerCount];
				city[outerCount].highestRainfallMonth = months[innerCount];
			}
			else if (city[outerCount].lowestRainfall > city[outerCount].inchesOfRain[innerCount] && city[outerCount].inchesOfRain[innerCount] > 0)
			{
				city[outerCount].lowestRainfall = city[outerCount].inchesOfRain[innerCount];
				city[outerCount].lowestRainfallMonth = months[innerCount];
			}
		}
		innerCount = 0;			// Counter reset
	}
}

void findNoRainfall(CityInfo city[], int citySize, string months[])
{
	// This function determines and stores the months that had no rain

	for (int outerCount = 0; outerCount < citySize; outerCount++)
	{
		city[outerCount].noRainfallCount = 0;

		for (int innerCount = 0; innerCount < SIZE; innerCount++)
		{
			if (city[outerCount].inchesOfRain[innerCount] == 0)
			{
				city[outerCount].noRainfall[city[outerCount].noRainfallCount] = months[innerCount];
				city[outerCount].noRainfallCount++;
			}
		}
	}
}

void printResults(ofstream &fout, CityInfo city[], int citySize, string months[], int &outerCount)
{
	// This function displays the results to monitor and output.txt

	int j = 0;
	HANDLE hConsole;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	for (outerCount = 0; outerCount < citySize; outerCount++)
	{
		cout << "_______________________________________________________________________________" << endl;
		fout << "_______________________________________________________________________________" << endl;

		SetConsoleTextAttribute(hConsole, 48);
		cout << "\n" << setw(35) << "" << setw(45) << city[outerCount].cityName << endl;
		SetConsoleTextAttribute(hConsole, 7);
		fout << "\n" << setw(35) << "" << setw(45) << city[outerCount].cityName << endl;

		cout << "_______________________________________________________________________________\n\n";
		fout << "_______________________________________________________________________________\n\n";

		cout << setw(15) << "" << setw(20) << "Average Rainfall:" << setw(6) << city[outerCount].avgRainfall << " inches" << endl;
		fout << setw(15) << "" << setw(20) << "Average Rainfall:" << setw(6) << city[outerCount].avgRainfall << " inches" << endl;
		cout << setw(15) << "" << setw(20) << "Highest Rainfall:" << setw(6) << city[outerCount].highestRainfall << setw(9) << " inches" << "(" << city[outerCount].highestRainfallMonth << ")" << endl;
		fout << setw(15) << "" << setw(20) << "Highest Rainfall:" << setw(6) << city[outerCount].highestRainfall << setw(9) << " inches" << "(" << city[outerCount].highestRainfallMonth << ")" << endl;
		cout << setw(15) << "" << setw(20) << "Lowest Rainfall:" << setw(6) << city[outerCount].lowestRainfall << setw(9) << " inches" << "(" << city[outerCount].lowestRainfallMonth << ")" << endl;
		fout << setw(15) << "" << setw(20) << "Lowest Rainfall:" << setw(6) << city[outerCount].lowestRainfall << setw(9) << " inches" << "(" << city[outerCount].lowestRainfallMonth << ")" << endl;
		cout << setw(15) << "" << setw(20) << "No Rainfall:";
		fout << setw(15) << "" << setw(20) << "No Rainfall:";

		for (int innerCount = 0; innerCount < city[outerCount].noRainfallCount; innerCount++)
		{
			j++;
			if (city[outerCount].noRainfallCount == j)
			{
				cout << city[outerCount].noRainfall[innerCount] << endl;
				fout << city[outerCount].noRainfall[innerCount] << endl;
			}
			else
			{
				cout << city[outerCount].noRainfall[innerCount] << ", ";
				fout << city[outerCount].noRainfall[innerCount] << ", ";
			}
		}
		j = 0;			// Counter reset

		if (city[outerCount].noRainfallCount == 0)
		{
			cout << "None" << endl;
			fout << "None" << endl;
		}

		cout << "_______________________________________________________________________________" << endl;
		fout << "_______________________________________________________________________________" << endl;

		printHistogram(fout, city, citySize, months, outerCount);
	}
	fout.close();
}

void printHistogram(ofstream &fout, CityInfo city[], int citySize, string months[], int &count)
{
	// This function prints the histogram to monitor and output.txt

	int roundedValueForRain,
		i = 0;

	cout << right << "-------------------------------------------------------------------------------\n";
	fout << right << "-------------------------------------------------------------------------------\n";

	for (int row = 0; row < SIZE; row++)
	{
		cout << setw(10) << months[row] << "| ";
		fout << setw(10) << months[row] << "| ";

		for (int j = 0; j < 20; j++)
		{
			if (city[count].inchesOfRain[i] >= j + 0 && city[count].inchesOfRain[i] <= j + .4)
				roundedValueForRain = floor(city[count].inchesOfRain[i]);
			else if (city[count].inchesOfRain[i] >= j + .5 && city[count].inchesOfRain[i] <= j + .9)
				roundedValueForRain = ceil(city[count].inchesOfRain[i]);
		}

		for (int col = 0; col < 20; col++)
		{
			if (col == roundedValueForRain)
			{
				i++;
				break;
			}
				cout << "*  ";
				fout << "*  ";
		}
		cout << endl;
		fout << endl;
	}
	i = 0;			// Counter reset

	cout << "-------------------------------------------------------------------------------\n";
	fout << "-------------------------------------------------------------------------------\n";
	cout << setw(10) << "Inches" << "| " << "1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20\n";
	fout << setw(10) << "Inches" << "| " << "1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20\n";
	cout << "-------------------------------------------------------------------------------\n";
	fout << "-------------------------------------------------------------------------------\n";

	cout << left << setw(4) << "" << "Each * represents 1 inch of rain (rounded to nearest whole number)\n\n";
	fout << left << setw(4) << "" << "Each * represents 1 inch of rain (rounded to nearest whole number)\n\n";
}

void printFooter()
{
	cout << "\n\nThe following report has been saved to output.txt." << endl;
	cout << "Thank you for using the Average Rainfall Calculator. :)\n\n";
}
