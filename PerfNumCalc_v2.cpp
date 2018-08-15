/*

ID block
+---------------------------------------------------+
+ Programmer  : Esther Choi						    +
+ Course      : Computer Science 1	    			+
+ Lab Section :	0101 (MW at 10 am)	       		    +
+ Grader      :	M. Ghyam							+
+ Assignment  :	Perfect Number Finder			  	+
+ Due Date    : October 19, 2015					+
+---------------------------------------------------+

Program statement:		This program finds and lists all perfect
						numbers that fall between two user input
						values.

******************** Beginning of Algorithm ********************
Step 1: Input

	Prompt user for:
		- First positive integer value (startVal)
		- Second positive integer value (endVal)

	Set countPerfNum variable to 0 (long integer)

Step 2: Process

				*** Beginning of Outer Loop ***
	This portion will execute as long as reply is not equivalent
		to 'n' or 'N'
	As long as startVal is a character or negative value:
		- Print error message
		- Clear the buffer
		- Ask for re-entry
	As long as endVal is a character or negative value, or endVal
	is less than or equal to startVal:
		If endVal is a character or negative value:
			Print appropriate error message
		Else if endVal is less than or equal to startVal:
			Print appropriate error message
		Clear the buffer
		Ask for re-entry

				*** Beginning of First Inner Loop ***
	This loop steps through the values between startVal and endVal
		Set sumPerfNum to 0 for next iteration

				*** Beginning of Second Inner Loop ***
	This loop steps through the values between 1 and (outerVal / 2)
		Set innerVal to 1
		As long as innerVal is less than or equal to outerVal
			If outerVal divided by innerVal returns a remainder of 0
				Accumulate innerVal into sumPerfNum
		Increment innerVal by 1
				*** End of Second Inner Loop ***

		If sumPerfNum is equivalent to outerVal
			- Print the perfect number
			- Increment countPerfNum by 1
		Increment outerVal
				*** End of First Inner Loop ***

	If countPerfNum is equivalent to 0
		Print a message stating that there are no perfect numbers
	Else (not necessary for school computers, but I think older systems like the one
	at my home, need the countPerfSum to be reset to print "None" so I left it in)
		Set countPerfNum equal to 0
	Ask user to enter 'Y' to rerun the program or 'N' to terminate it
	As long as the input is not equivalent to 'Y' or 'y':
		- If the reply is equivalent to 'y', 'Y', 'n', or 'N'
			Break out of this loop
		- Clear the reply buffer
		- Tell user to enter either 'Y' or 'N'
	If reply is 'N' or 'n':
		- Print a message stating that the program has terminated
		- Exit the program

Step 3: Output

	If perfect numbers exist within stated range:
		Print the perfect number(s) with informative label
			indicating the range
	If no perfect numbers found within stated range:
		Print an informative label informing user that there are
			no perfect numbers within the stated range
	If user enters 'N' or 'n' to end the program:
		Print an informative message that the program
			has been terminated

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