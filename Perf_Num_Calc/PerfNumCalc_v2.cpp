/*

ID block
+---------------------------------------------------+
+ Programmer  : Esther Choi
+ Course      : Computer Science 1
+ Lab Section :	0101 (MW at 10 am)
+ Grader      :	M. Ghyam
+ Assignment  :	Perfect Number Finder
+ Due Date    : October 19, 2015
+---------------------------------------------------+

Program statement:	This program finds and lists all perfect
			numbers that fall between two user input
			values.

*/

#include <iomanip>
#include <iostream>
using namespace std;

bool isAFactor(long int, long int);
bool checkValue(long int);

int main()
{
	char reply;
	bool factorCheck;
	long int outerVal,
			 innerVal,
			 startVal,
			 endVal,
			 countPerfNum = 0;
	double sumPerfNum;

	cout << left << setw(26) << "" << "Perfect Number Finder\n\n";

	cout << "This program accepts two positive integer inputs and returns all Perfect\n"
		 << "Numbers within the two ranges, if any.\n";

	do {
		cout << "\n" << setw(30) << "Enter minimum value:";
		cin >> startVal;

		while (checkValue(startVal) == false)
		{
			cout << "\n" << setw(14) << "" << "Input must be a positive integer!\n\n";
			cout << setw(30) << "Enter minimum value:";
			cin.clear();
			cin.ignore(100, '\n');
			cin >> startVal;
		}
		cout << setw(30) << "Enter maximum value:";
		cin >> endVal;

		while (checkValue(endVal) == false || endVal <= startVal)
		{
			if (checkValue(endVal) == false)
			{
				cout << "\n" << setw(14) << "" << "Input must be a positive integer!\n\n";
			}
			else if (endVal <= startVal)
			{
				cout << "\n" << setw(14) << "" << "Maximum value must be larger\n"
					 << setw(14) << "" << "than the minimum value!\n\n";
			}
			cout << setw(30) << "Enter maximum value:";
			cin.clear();
			cin.ignore(100, '\n');
			cin >> endVal;
		}
		cout << setw(15) << "\n" << "Perfect Numbers between " << startVal
			 << " and " << endVal << ": " << endl;

		for (outerVal = startVal; outerVal <= endVal; outerVal++)
		{
			sumPerfNum = 0;

			for (innerVal = 1; innerVal <= (outerVal / 2); innerVal++)
			{
				factorCheck = isAFactor(outerVal, innerVal);

				if (factorCheck)
					sumPerfNum += innerVal;
			}
			if (sumPerfNum == outerVal)
			{
				cout << left << setw(14) << "" << outerVal << endl;
				countPerfNum++;
			}
		}

		if (countPerfNum == 0)
			cout << setw(14) << "" << "None :(" << endl;
		else
			countPerfNum = 0;

		cout << "\n" << setw(30) << "Rerun the program? (Y/N)";
		cin >> reply;

		while (reply != 'y' || reply != 'Y')
		{
			if (reply == 'y' || reply == 'n' || reply == 'Y' || reply == 'N')
				break;
			cout << setw(30) << "Enter 'Y' or 'N':";
			cin.ignore(100, '\n');
			cin >> reply;
		}
		if (reply == 'n' || reply == 'N')
		{
			cout << "\n\n" << setw(22) << "" << "Program has been terminated.\n"
				 << setw(31) << "" << "Goodbye!\n\n";
			exit(0);
		}
	} while (reply != 'n' || reply != 'N');

	return 0;
}

bool checkValue(long int inputValue)
{
	bool result;

	if (!cin || inputValue <= 0)
		result = false;
	else
		result = true;

	return result;
}

bool isAFactor(long int outerValue, long int innerValue)
{
	bool result;

	if (outerValue % innerValue == 0)
		result = true;
	else
		result = false;

	return result;
}
