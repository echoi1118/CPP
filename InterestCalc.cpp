/*

ID block
+---------------------------------------------------+
+ Programmer  : Esther Choi							+
+ Course      : Computer Science 1	    			+
+ Lab Section :	0101 (MW at 10 am)	       			+
+ Grader      :	M. Ghyam							+
+ Assignment  :	Interest Calculation Program		+
+ Due Date    : November 18, 2015					+
+---------------------------------------------------+

Program statement:		This program processes the data in an
						input file and calculates interest based
						on the data and displays it to monitor and
						output file.

******************** Beginning of Algorithm ********************

Step 1: Input

	Prompt user for input file name
	Prompt user for output file name

	Set the following variables to 0 inside processInputFilefunction:
		- totalDepositAmount (double)
		- count (integer)

Step 2: Process

	Main function will be calling the following functions:
		- printHeadertoMonitor
		- openInputFile
		- openOutputFile
		- printHeadertoOutputFile
		- printColumnLabels
		- processInputFile
		- displayAvgDeposit

	[printHeadertoMonitor function]
		Format output - align left and show decimal precision to 2
		Print the heading (program name, informative message,
			and interest rates) to the monitor

	[openInputFile function]
		Get filename from user
		Open the input file
		While the file fails to open:
			- Give error message
			- Ask for filename again
			- Open the input file

	[openOutputFile function]
		Get the depositorName from file
		If emptyFileCheck function returns true:
			- Print out a detailed error message
			- Exit the program
		Else
			- Get output file name from user
			- Open the output file

	[printHeadertoOutputFile function]
		Format output - align left and show decimal precision to 2
		Print the heading (program name, informative message,
			and interest rates) to the ouput file

	[printColumnLabels function]
		Print column labels to monitor and output file

	[processInputFile function]
		Open the bad_data.txt output file
		Set the handle for the monitor screen (used for font coloring)

							*** Beginning of Loop ***

		As long as the input file does not reach end of file:
		Get principalDepositAmount, interestCompoundedPerYear, and
			numberOfYearsDeposited from input file

		If numberOfYearsDeposited is less than or equal to 0:
			- Set the console text color to red
			- Print depositorName, numberOfYearsDeposited (type cast to
				integer), principalDepositAmount, and detailed error message
			- Print the entire bad record to bad_data.txt
			- Reset console text color to default color
		Else if principalDepositAmount is less than or equal to 0:
			- Set the console text color to red
			- Print depositorName, numberOfYearsDeposited (type cast to
				integer), principalDepositAmount, and detailed error message
			- Print the entire bad record to bad_data.txt
			- Reset console text color to default color
		Else if interestCompoundedPerYear is less than or equal to 0:
			- Set the console text color to red
			- Print depositorName, numberOfYearsDeposited (type cast to
				integer), principalDepositAmount, and detailed error message
			- Print the entire bad record to bad_data.txt
			- Reset console text color to default color
		Else
			- Call returnInterestRate function and pass it numberOfYearsDeposited
				to get back the interestRate
			- Call computeInterest function and pass it principalDepositAmount,
				interestCompoundedPerYear, numberOfYearsDeposited, and interestRate
				to get back the principalPlusInterest
			- interestEarned = principalPlusInterest - principalDepositAmount
			- Print depositorName, numberOfYearsDeposited, principalDepositAmount,
				interestEarned, and principalPlusInterest to monitor and output file
			- Accumulate principalDepositAmount into totalDepositAmount
			- Increment the count
		Clear the input file stream buffer
		Get the next depositorName from input file
			
								*** End of Loop ***

		Call the calcAvgDeposit function and pass it totalDepositAmount and count
			to get back avgDeposit
		Close the "bad_data.txt" output file

	[displayAvgDeposit function]
		Display the avgDeposit with appropriate labels to monitor and output file
		Call the displayBadData function and pass it the output file stream
			to get back list of records with negative values
		Inform user where the output has been saved to
		Appreciative message before closing down the program
		Close the output file stream

	[displayBadData function]
		Open "bad_data.txt" input file
		Print to output file an informative message indicating that the records
			that follow contained negative values and could not be processed
		Print to output file appropriate column labels for bad records
		Get the depositorName from "bad_data.txt" input file
		While the end of file is not reached:
			- Get from file numberOfYearsDeposited, principalDepositAmount,
				and interestCompoundedPerYear
			- Clear input file stream buffer
			- Get the next depositorName
		Close the input file stream
		Close the "bad_data.txt" input file

				** Smaller functions designed to help with processing **

	[emptyFileCheck function]
		If end of file reached for input file
			Assign true to result (returning variable)
		Else
			Assign false to result (returning variable)
		Return result

	[returnInterestRate function]
		If yearsOnDeposit is greater than or equal to 5
			Assign .045 to interestRate
		Else if yearsOnDeposit is greater than or equal to 4
			Assign .040 to interestRate
		Else if yearsOnDeposit is greater than or equal to 3
			Assign .035 to interestRate
		Else if yearsOnDeposit is greater than or equal to 2
			Assign .025 to interestRate
		Else if yearsOnDeposit is greater than or equal to 1
			Assign .020 to interestRate
		Else
			Assign .015 to interestRate
		Return interestRate to calling function

	[computeInterest function]
		principalPlusInterest = principalDepositAmount * (1 + (interestRate / interestCompoundedPerYear)) ^ (interestCompoundedPerYear * numberOfYearsDeposited)
		Return principalPlusInterest to calling function

	[calcAvgDeposit function]
		avgDeposit = totalDepositAmount / count
		Return avgDeposit to calling function

Step 3: Output

				** Displays to monitor and output file **
	Display the appropriate header information with instructional information
	Display the column names with proper spacing
	Display the name, years, deposit amount, interest earned, and the total amount
		for each depositor with proper spacing
	Display the avgDeposit for the depositors in the table with non-negative data
	Tell the user where the output file has been saved (displays to monitor only)
	Appreciative message to user for using program (displays to monitor only)

					** Displays to output file only **
	Display the list of records with negative values as a separate table with
		informative label and columns

******************** End of Algorithm ********************

*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>
#include <windows.h>

using namespace std;

bool emptyFileCheck(ifstream&);
double calcAvgDeposit(double, int);
double computeInterest(double, double, double, double);
double returnInterestRate(double);
void displayAvgDeposit(ofstream&, double, string);
void displayBadData(ofstream&);
void openInputFile(ifstream&);
void openOutputFile(ifstream&, ofstream&, string&, string&);
void printColumnLabels(ifstream&, ofstream&);
void printHeadertoMonitor(ofstream&);
void printHeadertoOutputFile(ofstream&);
void processInputFile(ifstream&, ofstream&, string&, double&, double&, double&, double&);

int main()
{
	ifstream fin;
	ofstream fout;
	string outputFileName,
		depositorName;
	double avgDeposit,
		numberOfYearsDeposited,
		principalDepositAmount,
		interestCompoundedPerYear;

	printHeadertoMonitor(fout);
	openInputFile(fin);
	openOutputFile(fin, fout, depositorName, outputFileName);
	printHeadertoOutputFile(fout);
	printColumnLabels(fin, fout);
	processInputFile(fin, fout, depositorName, numberOfYearsDeposited, principalDepositAmount, interestCompoundedPerYear, avgDeposit);
	displayAvgDeposit(fout, avgDeposit, outputFileName);

	return 0;
}

void printHeadertoMonitor(ofstream &fout)
{
	// This function prints the program header to monitor

	cout << left << fixed << showpoint << setprecision(2);
	cout << setw(25) << "" << "Interest Calculation Program\n\n";
	cout << "This program calculates and displays the interest accrued based on the princi-\n"
		<< "pal amount, compounding period, annual rate of interest, and years of accru-\n"
		<< "al. The program will determine the interest to be paid on the deposit based\n"
		<< "on the following schedule:\n\n";

	cout << setw(17) << "" << setw(25) << "Time on Deposit" << "Interest Rate" << endl;
	cout << setw(16) << "" << "________________________________________\n\n";
	cout << setw(19) << "" << setw(27) << ">= 5 years" << "4.5%" << endl;
	cout << setw(19) << "" << setw(27) << ">= 4 years" << "4.0%" << endl;
	cout << setw(19) << "" << setw(27) << ">= 3 years" << "3.5%" << endl;
	cout << setw(19) << "" << setw(27) << ">= 2 years" << "2.5%" << endl;
	cout << setw(19) << "" << setw(27) << ">= 1 year" << "2.0%" << endl;
	cout << setw(19) << "" << setw(27) << "<  1 year" << "1.5%" << endl;
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
		cout << "\n\tA file with that name does not exist.\n";
		cout << "\tVerify that the name and/or location"
			<< "\n\tare correct and try again.\n\n";

		cout << setw(40) << "Enter input file name including path:";
		getline(cin, fileName);
		fin.open(fileName.c_str());
	}
}

void openOutputFile(ifstream &fin, ofstream &fout, string &depositorName, string &outputFileName)
{
	// This function terminates the program on an empty input file or opens
	// output file and prints the column labels and processes input file

	getline(fin, depositorName);

	if (emptyFileCheck(fin))
	{
		cout << "\n\tThe input file 'interest.txt' is empty.\n"
			<< "\tProgram has been terminated. :(\n\n";
		exit(0);
	}
	else
	{
		cout << setw(40) << "Enter output file name including path:";
		getline(cin, outputFileName);
		fout.open(outputFileName);
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

void printHeadertoOutputFile(ofstream &fout)
{
	// This function prints the program header to output file

	fout << left << fixed << showpoint << setprecision(2);
	fout << setw(25) << "" << "Interest Calculation Program\n\n";
	fout << "This program calculated the interest accrued based on the principal amount,\n"
		<< "compounding period, annual rate of interest, and years of accrual. The pro-\n"
		<< "gram determined the interest to be paid on the deposit based on the follow-\n"
		<< "ing schedule:\n\n";

	fout << setw(17) << "" << setw(25) << "Time on Deposit" << "Interest Rate" << endl;
	fout << setw(16) << "" << "________________________________________\n";
	fout << setw(16) << "" << "----------------------------------------\n";
	fout << setw(19) << "" << setw(27) << ">= 5 years" << "4.5%" << endl;
	fout << setw(19) << "" << setw(27) << ">= 4 years" << "4.0%" << endl;
	fout << setw(19) << "" << setw(27) << ">= 3 years" << "3.5%" << endl;
	fout << setw(19) << "" << setw(27) << ">= 2 years" << "2.5%" << endl;
	fout << setw(19) << "" << setw(27) << ">= 1 year" << "2.0%" << endl;
	fout << setw(19) << "" << setw(27) << "<  1 year" << "1.5%" << endl;
}

void printColumnLabels(ifstream &fin, ofstream &fout)
{
	// This function prints the column labels to monitor and output file

	cout << "\n" << setw(20) << "Name" << setw(10) << "Years" << setw(18) << "Deposit Amount" << setw(20) << "Interest Earned" << "Total" << endl;
	fout << "\n" << setw(20) << "Name" << setw(10) << "Years" << setw(18) << "Deposit Amount" << setw(20) << "Interest Earned" << "Total" << endl;
	cout << "______________________________________________________________________________" << endl;
	fout << "______________________________________________________________________________" << endl;
	fout << "------------------------------------------------------------------------------" << endl;
}

void processInputFile(ifstream &fin, ofstream &fout, string &depositorName, double &numberOfYearsDeposited, double &principalDepositAmount, double &interestCompoundedPerYear, double &avgDeposit)
{
	ofstream foutBadRecord;
	double interestRate,
		principalPlusInterest,
		interestEarned,
		totalDepositAmount = 0;
	int count = 0;

	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
	foutBadRecord.open("bad_data.txt");

	while (!fin.eof())
	{
		fin >> principalDepositAmount >> interestCompoundedPerYear >> numberOfYearsDeposited;

		if (numberOfYearsDeposited <= 0)
		{
			SetConsoleTextAttribute(screen, 12);
			cout << setw(21) << depositorName << setw(11) << static_cast<int>(numberOfYearsDeposited) << "$" << setw(18) << principalDepositAmount << "Error: Negative years" << endl;
			foutBadRecord << depositorName << "\n" << numberOfYearsDeposited << " " << principalDepositAmount << " " << interestCompoundedPerYear << endl;
			SetConsoleTextAttribute(screen, 7);
		}
		else if (principalDepositAmount <= 0)
		{
			SetConsoleTextAttribute(screen, 12);
			cout << setw(22) << depositorName << setw(10) << static_cast<int>(numberOfYearsDeposited) << setw(19) << principalDepositAmount << "Error: Negative deposit amt" << endl;
			foutBadRecord << depositorName << "\n" << numberOfYearsDeposited << " " << principalDepositAmount << " " << interestCompoundedPerYear << endl;
			SetConsoleTextAttribute(screen, 7);
		}
		else if (interestCompoundedPerYear <= 0)
		{
			SetConsoleTextAttribute(screen, 12);
			cout << setw(22) << depositorName << setw(10) << static_cast<int>(numberOfYearsDeposited) << "$" << setw(18) << principalDepositAmount << "Error: Negative compnd per" << endl;
			foutBadRecord << depositorName << "\n" << numberOfYearsDeposited << " " << principalDepositAmount << " " << interestCompoundedPerYear << endl;
			SetConsoleTextAttribute(screen, 7);
		}
		else
		{
			interestRate = returnInterestRate(numberOfYearsDeposited);
			principalPlusInterest = computeInterest(principalDepositAmount, interestCompoundedPerYear, numberOfYearsDeposited, interestRate);
			interestEarned = principalPlusInterest - principalDepositAmount;
			cout << setw(22) << depositorName << setw(10) << static_cast<int>(numberOfYearsDeposited) << "$" << setw(18) << principalDepositAmount << "$" << setw(15) << interestEarned << "$" << principalPlusInterest << endl;
			fout << setw(22) << depositorName << setw(10) << static_cast<int>(numberOfYearsDeposited) << "$" << setw(18) << principalDepositAmount << "$" << setw(15) << interestEarned << "$" << principalPlusInterest << endl;
			totalDepositAmount += principalDepositAmount;
			count++;
		}
		cout << "______________________________________________________________________________" << endl;
		fin.clear();
		fin.ignore(1000, '\n');
		getline(fin, depositorName);
	}
	avgDeposit = calcAvgDeposit(totalDepositAmount, count);
	fin.close();
	foutBadRecord.close();
}

double returnInterestRate(double yearsOnDeposit)
{
	double interestRate;

	if (yearsOnDeposit >= 5)
		interestRate = .045;
	else if (yearsOnDeposit >= 4)
		interestRate = .040;
	else if (yearsOnDeposit >= 3)
		interestRate = .035;
	else if (yearsOnDeposit >= 2)
		interestRate = .025;
	else if (yearsOnDeposit >= 1)
		interestRate = .020;
	else
		interestRate = .015;

	return interestRate;
}

double computeInterest(double principalDepositAmount, double interestCompoundedPerYear, double numberOfYearsDeposited, double interestRate)
{
	// This function calculates and returns the principal amount plus interest accrued

	double principalPlusInterest;

	principalPlusInterest = principalDepositAmount * pow(1 + (interestRate / interestCompoundedPerYear), interestCompoundedPerYear * numberOfYearsDeposited);

	return principalPlusInterest;
}

double calcAvgDeposit(double totalDepositAmount, int count)
{
	double avgDeposit;

	avgDeposit = totalDepositAmount / count;

	return avgDeposit;
}

void displayAvgDeposit(ofstream &fout, double avgDeposit, string outputFileName)
{
	// This function displays the average deposit with appropriate labels
	// to monitor and output file

	fout << "______________________________________________________________________________" << endl;
	fout << "------------------------------------------------------------------------------" << endl;
	cout << setw(32) << "Average Deposit" << "$" << avgDeposit << endl;
	fout << setw(32) << "Average Deposit" << "$" << avgDeposit << "\n\n";

	displayBadData(fout);

	cout << "\n\nOutput has been saved to " << outputFileName << "." << endl;
	cout << "\nThank you for using the interest calculation program.\n"
		<< "Have a nice day. (:\n\n";
	
	fout.close();
}

void displayBadData(ofstream &fout)
{
	ifstream finBadData;
	string depositorName;
	double numberOfYearsDeposited,
		principalDepositAmount,
		interestCompoundedPerYear;

	finBadData.open("bad_data.txt");

	fout << "\nThe following records had negative data value(s) and could not be processed:\n\n";

	fout << setw(20) << "Name" << setw(10) << "Years" << setw(18) << "Deposit Amount" << "Compound Period" << endl;
	fout << "________________________________________________________________" << endl;
	fout << "----------------------------------------------------------------" << endl;

	getline(finBadData, depositorName);

	while (!finBadData.eof())
	{
		finBadData >> numberOfYearsDeposited >> principalDepositAmount >> interestCompoundedPerYear;
		fout << setw(22) << depositorName << setw(10) << static_cast<int>(numberOfYearsDeposited) << setw(22) << principalDepositAmount << static_cast<int>(interestCompoundedPerYear) << endl;
		finBadData.ignore(100, '\n');
		getline(finBadData, depositorName);
	}
	finBadData.close();
}