/*

ID block
+---------------------------------------------------+
+ Programmer  : Esther Choi
+ Course      : Computer Science 1
+ Lab Section :	0101 (MW at 10 am)
+ Grader      :	M. Ghyam
+ Assignment  :	GPA Calculator
+ Due Date    : Oct 7, 2015
+---------------------------------------------------+

Program statement:		This program reads students' grades
						and calculates their GPAs.

******************** Beginning of Algorithm ********************
Step 1: Input

	Prompt user for student's name or *** symbols to stop
		entering student names (means similar statement must
		be called up again later inside a loop)
	Prompt user for letter grade or * to stop entering grades
		(must be called up again later within a loop)

	Set the following variables:
		- gradePointSubTotal to 0.0 (float)
		- gradePointGrandTotal to 0.0 (float)
		- counter to 0 (integer)
		- grandCounter to 0 (integer)

Step 2: Process

				*** Beginning of First Loop ***
	So long as student's name is not equivalent to sentinel
		value (***), call up prompt asking for letter grade
		or sentinel value (*)
			
				*** Beginning of Second Loop ***
	Increment the subCounter; this will reset for every student

	If letterGrade is equivalent to:
		- a or A, assign 4 to gradePoint
		- b or B, assign 3 to gradePoint
		- c or C, assign 2 to gradePoint
		- d or D, assign 1 to gradePoint
		- f or F, assign 0 to gradePoint
		- * (sentinel value), assign 0 to gradePoint
	Else (if none of the above are entered)
		- Display error message
		- Set gradePoint equal to 0
		- Decrement subCounter by 1 (this will undo
			the count of the bad letter input so it
			does not figure into any calculations)

	Accumulate gradePoint into gradePointSubTotal
	Accumulate gradePoint into gradePointGrandTotal

	Must call up the prompt asking for grade input or
		sentinel value (*) once again from within this
		second loop (this will be the one to be called
		up repeatedly until * is entered)
				*** End of Second Loop ***

	If subCounter is equivalent to 0
		Set totalGpa equal to 0
	Else
		totalGpa = gradePointSubTotal / subCounter
	
	Print the GPA for the student with appropriate label
		(detailed in "Step 3: Output")
	Call up a prompt asking for another student's name or
		sentinel value (***) to exit
	Clear out the studentName buffer (this must be done in
		order to reuse the variable for the next studentName)
	Accumulate subCounter into grandCounter (this makes grandCounter
		retain all acceptable grade inputs for the final averaging
		at the end of the program)
	Reset subCounter and gradePointSubTotal to 0 for next student's
		input (NOTE: This reset does not affect the grandCounter
		accumulation that took place just prior)
				*** End of First Loop ***

	If grandCounter is equivalent to 0 (this means no grades
	have been entered for a student)
		Set totalGpa equal to 0
	Else
		totalGpa = gradePointGrandTotal / grandCounter

Step 3: Output

	*** THIS output repeats for however many students there
					are (part of first loop) ***
		Print student's name and totalGpa with informative
			label
		Print pound sign separators for readability

	*** THIS output executes once at the very end of the program
				and so is not part of a loop ***
		Print asterisk separators for readability
		Print label stating that the program is being terminated
		Show the average GPA for all entered grades with informative
			label
		Print two newline characters for readability

*/

#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	char letterGrade;											// Variable declarations
	int subCounter = 0,
		grandCounter = 0,
		gradePoint;
	float totalGpa,
		gradePointSubTotal = 0,
		gradePointGrandTotal = 0;
	string studentName;

	cout << fixed << showpoint << setprecision(2);
	cout << "\tEnter the student's name or '***' to terminate: ";
	getline(cin, studentName);

	while (studentName != "***")
	{
		cout << "\tEnter a grade or '*' to terminate: ";
		cin >> letterGrade;
		while (letterGrade != '*')
		{
			subCounter++;										// This counter must be reset for each new student

			switch (letterGrade)
			{
				case 'a':
				case 'A': gradePoint = 4;
					break;
				case 'b':
				case 'B': gradePoint = 3;
					break;
				case 'c':
				case 'C': gradePoint = 2;
					break;
				case 'd':
				case 'D': gradePoint = 1;
					break;
				case 'f':
				case 'F': gradePoint = 0;
					break;
				case '*': gradePoint = 0;
					break;
				default: cout << "\t\tILLEGAL LETTER GRADE!\n";
					gradePoint = 0;
					subCounter--;
			}

			gradePointSubTotal += gradePoint;					// This accumulation must be reset for each new student
			gradePointGrandTotal += gradePoint;					// This accumulation will not be reset; used at the very end

			cout << "\tEnter a grade or '*' to terminate: ";
			cin >> letterGrade;
		}
		if (subCounter == 0)
			totalGpa = 0;
		else
			totalGpa = gradePointSubTotal / subCounter;

		cout << "\tThe GPA for " << studentName << " is " << totalGpa << endl;
		cout << "\t#########################################" << endl;
		cout << "\tEnter another name or '***' to terminate: ";
		cin.ignore(100, '\n');
		getline(cin, studentName);
		grandCounter += subCounter;								// grandCounter has only the acceptable subCounter values now; used at the very end
		subCounter = 0;											// Reset of subCounter and gradePointSub for next student
		gradePointSubTotal = 0;
	}
	if (grandCounter == 0)
		totalGpa = 0;
	else
		totalGpa = gradePointGrandTotal / grandCounter;
	cout << "\t***************************************************" << endl;
	cout << "\tPROGRAM TERMINATED ON REQUEST" << endl;
	cout << "\tThe average GPA for all entered grades is " << totalGpa << "\n\n";

	return 0;
}
