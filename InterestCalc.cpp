/*

ID block
+---------------------------------------------------+
+ Programmer  : Esther Choi
+ Course      : Computer Science 1
+ Lab Section :	0101 (MW at 10 am)
+ Grader      :	M. Ghyam
+ Assignment  :	Interest Calculation Program
+ Due Date    : November 18, 2015
+---------------------------------------------------+

Program statement:	This program processes the data in an
			input file and calculates interest based
			on the data and displays it to monitor and
			output file.

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
