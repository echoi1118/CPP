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

Program statement:	This program reads students' grades
			and calculates their GPAs.

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
