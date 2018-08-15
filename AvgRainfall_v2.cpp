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

Program statement:		This program calculates the average rainfall
						for one or more cities during a 12-month period.

		******************** Beginning of Algorithm ********************

Step 1: Input

	Prompt user for name of input file
	Prompt user for their name

	Initialize a string array for the months of the year inside
		main function (to be passed to whatever function needs it)
	Create a City structure that contains data pertaining to
		each city (cap it at 50)
	Set defined SIZE for number of months to 12
	Set city array size to 50
	Set all appropriate counter and accumulation variables to 0
		inside the separate functions (Too many and too general to list here)

Step 2: Process

	Main function will be calling the following functions:
		- printHeadertoMonitor
		- openInputFile
		- processDataFile (returns an integer value as the array size)
		- calcAvgRainfall
		- findHighestRainfall
		- findLowestRainfall
		- findNoRainfall
		- printIntro
		- printResults
		- printFooter

	[printHeadertoMonitor function]

	This function prints the necessary header information to the monitor

		Set the output formatting (left, fixed, and show decimal
			precision to 2 places)
		Print title and program information to monitor

	[openInputfile function]

	This function picks up the input file name from user and opens it or loops until a valid file name is given

		Ask for and pick up input file name
		Open input file
		While file fails to open
			- Inform user of the error
			- Ask for and pick up input file name
			- Open input file
		
	[processDataFile function]

	This function cycles through the input file and stores the data in the appropriate arrays

		Set outerCount to 0 (integer)
		Set innerCount to 0 (integer)

		Pick up cityName from file
		Call openOutputFile function
		While end of file is not reached and outerCount is less than cityCap
			As long as innerCount is less than the defined SIZE
				- Pick up the inchesOfRain from input file
				- Increment innerCount
			Increment the outerCount
			Ignore the buffer
			Get the next cityName
		Close input file
		Return outerCount to calling function (main)

	[openOutputFile function]

	This function terminates the program on an empty file or picks up user's name to continue with program execution

		If emptyFileCheck function returns true
			- Print error message
			- Exit the program
		Else
			- Ask for user's name
			- Pick up name
			- Open ofstream ("output.txt")
			- Call printHeadertoOutputFile function

	[emptyFileCheck function]

	This function uses a boolean check to search for an empty file

		If end of input file is reached
			Function returns true to calling function
		Else
			Function returns false to calling function

	[printHeadertoOutputFile function]
	
	This function prints header information to output file

		Set the output file formatting (left, fixed, and show decimal
			precision to 2 places)
		Print title and program information to output file

	[calcAvgRainfall function]

	This function cycles through and accumulates the values in inchesOfRain array and uses accumulation to determine average
		
		Set totalRainfall accumulation variable to 0 (double)
		Set outerCount to 0 (integer)
		Set innerCount to 0 (integer)

		As long as outerCount is less than the citySize
			As long as innerCount less than defined SIZE:
				Accumulate inchesOfRain into totalRainfall
			avgRainfall = totalRainfall / SIZE
			Reset totalRainfall accumulation to 0

	[findHighestAndLowestRainfall function]

	This function cycles through the values in the inchesOfRain array to determine the highest and lowest rainfall values

		Set outerCount to 0 (integer)
		Set innerCount to 0 (integer)

		As long as outerCount is less than the citySize
			Set inchesOfRain equal to lowestRainfall equal to highestRainfall
			Set month equal to lowestRainfallMonth equal to highestRainfallMonth
			As long as innerCount is less than defined SIZE
				If highestRainfall is less than inchesOfRain
					- Set inchesOfRain as highestRainfall
					- Set month as highestRainfallMonth
				Else if lowestRainfall is greater than inchesOfRain and inchesOfRain is greater than 0
					- Set inchesOfRain as lowestRainfall
					- Set month as lowestRainfallMonth
				Increment innerCount
			Reset innerCount to 0
			Increment outerCount

	[findNoRainfall function]

	This function cycles through loops to find all the months that had no rain and picks up those months in an array

		Set outerCount to 0 (integer)
		Set innerCount to 0 (integer)

		As long as outerCount is less than the citySize
			Set noRainfallCount to 0
			As long as innerCount is less than defined SIZE
				If inchesOfRain is equivalent to 0
					- Store than month in the noRainfall array
					- Increment the noRainfallCount
				Increment innerCount
			Increment outerCount

	[printIntro function]

	This function prints the report intro to monitor and output file

		Print the appropriate report introduction based on citySize to monitor and output file
		Print the name of report preparer to monitor and output file
	
	[printResults function]

	This function basically cycles through and displays all the values that were stored in the arrays from the prior functions

		Set outerCount to 0 (integer)
		Set innerCount to 0 (integer)
		Set j (counter for noRainfall display) to 0 (integer)
		Define and set hConsole for coloring of console

		As long as outerCount is less than citySize, print the following to
			monitor and output file with appropriate labels and formatting
				- cityName
				- avgRainfall
				- highestRainfall
				- lowestRainfall
			As long as innerCount is less than noRainfallCount
				Increment j
				If noRainfallCount is equivalent to j
					Print noRainfall array to monitor and output file without comma separator
				Else
					Print noRainfall array to monitor and output file with comma separator
				Increment innerCount
			Reset j counter to 0
			If noRainfallCount is equivalent to 0:
				- Print "None" to monitor and output file
			Call printHistogram function
			Increment outerCount
		Close output file

	[printHistogram function]

	This function cycles through two loops (row and col) to display the star pattern histograms for each city

		Set i (comparison increment) to 0 (integer)
		Set row to 0 (integer)
		Set col to 0 (integer)

		Formatting should be set to right alignment for printing of months

		As long as row is less than defined SIZE
			Print the month to monitor and output file
			As long as j is less than 20
				If inchesOfRain is greather and or equal to j + 0  and inchesOfRain is less than or equal to j + .4
					Call floor function to round down inchesOfRain and store it in roundedValueForRain
				Else if inchesOfRain is greater than or equal to j + .5 and inchesOfRain is less than or equal to j + .9
					Call ceil function to round up inchesOfRain and store it in roundedValueForRain
				Increment j
			As long as col is less than 20
				If col is equivalent to roundedValueForRain
					- Increment i
					- Break
				Else if col is greater than or equal to 9
					Print * to monitor and output file with appropriate spacing for double digit rain values
				Else
					Print * to monitor and output file with appropriate spacing for single digit rain values
				Increment col
			Newline to break the asterisk pattern
			Increment row
		Reset i to 0
		Print the inch markers to monitor and output file
		Reset formatting alignment to left
		Print informative label about how to read the histogram

	[printFooter function]

		This function print closing message to monitor and tells user where output file has been saved

Step 3: Output
	
	Output comes from the following functions:
		- printHeadertoMonitor
				Prints the program name and information to the monitor
		- printHeadertoOutputFile
				Prints the program name and information to output.txt
		- printIntro
				Prints report introduction including the name of preparer to the monitor and output.txt
		- printResults
				Displays the results to monitor and output.txt according to style described in Step 2
		- printHistogram
				Displays the historgram according to style described in Step 2
		- printFooter
				Displays message on monitor informing user where the output file has been saved

			******************** End of Algorithm ********************

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