/*

ID block
+---------------------------------------------------+
+ Programmer  : Esther Choi
+ Course      : Computer Science 1
+ Lab Section :	0101 (MW at 10 am)
+ Grader      :	M. Ghyam
+ Assignment  :	Grade Report Program
+ Due Date    : November 9, 2015	
+---------------------------------------------------+

Program statement:	This program picks up names of students
			and their test scores from student.txt,
			does calculations with those scores, and
			displays the results out to the monitor
			and to an output file.

*/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

bool checkValue(int);
bool emptyFileCheck(ifstream&);
char calcLetterGrade(float);
float averageScores(float, int);
void openInputFile(ifstream&);
void openOutputFile(ifstream&, ofstream&, string&, string&);
void printClassAvg(ofstream&, string, int, float);
void printColumnLabels(ofstream&);
void printHeadingtoMonitor();
void printHeadingtoOutputFile(ofstream &fout);
void printNoScoreList(ofstream&);
void printRangeProbList(ofstream&);
void processScore(ifstream&, ofstream&, ofstream&, ofstream&, string, int&, float&);

int main()
{
	ifstream fin;
	ofstream fout,
		rangeProbOut,
		noScoreOut;
	string studentName,
		outputFileName;
	int studentCount = 0;
	float totalAvg = 0;

	printHeadingtoMonitor();
	openInputFile(fin);
	openOutputFile(fin, fout, outputFileName, studentName);
	processScore(fin, fout, noScoreOut, rangeProbOut, studentName, studentCount, totalAvg);
	printClassAvg(fout, outputFileName, studentCount, totalAvg);

	return 0;
}

void printHeadingtoMonitor()
{
	// This function prints the grade report heading to the monitor

	cout << left << fixed << setprecision(1) << setw(15) << "" << "Grade Report for Introduction to Programming I\n\n";

	cout << "This program will process test scores to provide individuals with letter\n"
		<< "grades according to the following scale:\n\n";

	cout << setw(22) << "" << setw(8) << "100" << setw(15) << "<= average >" << setw(7) << "90" << "A" << endl;
	cout << setw(23) << "" << setw(7) << "90" << setw(15) << ">= average >" << setw(7) << "80" << "B" << endl;
	cout << setw(23) << "" << setw(7) << "80" << setw(15) << ">= average >" << setw(7) << "67.5" << "C" << endl;
	cout << setw(23) << "" << setw(7) << "67.5" << setw(15) << ">= average >" << setw(7) << "55" << "D" << endl;
	cout << setw(23) << "" << setw(7) << "55" << setw(16) << ">= average >=" << setw(6) << "0" << "F\n\n";
}

void openInputFile(ifstream &fin)
{
	// This function verifies that the input file exists and can be accessed

	string fileName;

	cout << left << setw(25) << "Enter input file name:";
	getline(cin, fileName);
	fin.open(fileName.c_str());

	while (fin.fail())
	{
		cout << "\n\tA file with that name does not exist.\n";
		cout << "\tVerify that the name and/or location"
			<< "\n\tare correct and try again.\n\n";

		cout << left << setw(25) << "Enter input file name:";
		getline(cin, fileName);
		fin.open(fileName.c_str());
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

void openOutputFile(ifstream &fin, ofstream &fout, string &outputFileName, string &studentName)
{
	// This function terminates the program on an empty input file
	// or opens output file and prints the heading and column labels

	getline(fin, studentName);

	if (emptyFileCheck(fin))
	{
		cout << "\n\tThe input file 'student.txt' is empty.\n"
			<< "\tProgram has been terminated. :(\n\n";
		exit(0);
	}
	else
	{
		cout << setw(25) << "Enter output file name:";
		getline(cin, outputFileName);
		fout.open(outputFileName);
		printHeadingtoOutputFile(fout);
		printColumnLabels(fout);
	}
}

void printHeadingtoOutputFile(ofstream &fout)
{
	// This function prints the grade report heading to an output file indicated by the user

	fout << left << fixed << setprecision(1) << setw(15) << "" << "Grade Report for Introduction to Programming I\n\n";

	fout << "The Grade Report program processed test scores to provide individuals with\n"
		<< "letter grades according to the following scale:\n\n";

	fout << setw(22) << "" << setw(8) << "100" << setw(15) << "<= average >" << setw(7) << "90" << "A" << endl;
	fout << setw(23) << "" << setw(7) << "90" << setw(15) << ">= average >" << setw(7) << "80" << "B" << endl;
	fout << setw(23) << "" << setw(7) << "80" << setw(15) << ">= average >" << setw(7) << "67.5" << "C" << endl;
	fout << setw(23) << "" << setw(7) << "67.5" << setw(15) << ">= average >" << setw(7) << "55" << "D" << endl;
	fout << setw(23) << "" << setw(7) << "55" << setw(16) << ">= average >=" << setw(6) << "0" << "F\n\n";
}

void printColumnLabels(ofstream &fout)
{
	// This function prints the column headings both to monitor and output file

	cout << "\n===========================================================================" << endl;
	fout << "\n===========================================================================" << endl;
	cout << setw(30) << "Name" << setw(19) << "No. of Tests" << setw(15) << "Average" << "Grade" << endl;
	fout << setw(30) << "Name" << setw(19) << "No. of Tests" << setw(15) << "Average" << "Grade" << endl;
	cout << "---------------------------------------------------------------------------" << endl;
	fout << "---------------------------------------------------------------------------" << endl;
}

void processScore(ifstream &fin, ofstream &fout, ofstream &noScoreOut, ofstream &rangeProbOut, string studentName, int &studentCount, float &totalAvg)
{
	// This function processes scores, and based on the outcome, gives the appropriate output

	char letterGrade;
	int score,
		examCount = 0,
		badExamCount = 0;
	float sum = 0,
		  avg;

	rangeProbOut.open("rangeProbFile.txt");
	noScoreOut.open("noScoreFile.txt");
	
	while (!fin.eof())
	{
		studentCount++;
		fin >> score;

		if (score == -1)
		{
			examCount = 0;
			noScoreOut << studentName << endl;
		}
		while (score != -1)
		{
			if (checkValue(score) == false)
				badExamCount++;
			else
			{
				sum += score;
				examCount++;
			}
			fin >> score;
		}
		if (examCount == 0)
			studentCount--;
		else if (badExamCount > 0)
		{
			rangeProbOut << studentName << endl;
			studentCount--;
			examCount = 0;
			sum = 0;
		}
		else
		{
			avg = averageScores(sum, examCount);
			letterGrade = calcLetterGrade(avg);
			totalAvg += avg;
			cout << setw(35) << studentName << setw(15) << examCount << setw(16) << avg << letterGrade << endl;
			fout << setw(35) << studentName << setw(15) << examCount << setw(16) << avg << letterGrade << endl;
		}

		sum = 0;
		examCount = 0;
		badExamCount = 0;

		fin.clear();
		fin.ignore(1000, '\n');
		getline(fin, studentName);
	}

	rangeProbOut.close();
	noScoreOut.close();
	fin.close();
}

void printClassAvg(ofstream &fout, string outputFileName, int studentCount, float totalAvg)
{
	// This function prints the grand total average for the class for only those students
	// with valid scores and calls the two print error list functions

	float grandAvg;

	grandAvg = averageScores(totalAvg, studentCount);

	cout << "---------------------------------------------------------------------------" << endl;
	fout << "---------------------------------------------------------------------------" << endl;
	cout << "Class average for " << studentCount << " students: " << grandAvg << endl;
	fout << "Class average for " << studentCount << " students: " << grandAvg << endl;
	cout << "---------------------------------------------------------------------------\n\n\n";
	fout << "---------------------------------------------------------------------------\n\n\n";

	printNoScoreList(fout);
	printRangeProbList(fout);

	cout << "\n\nThis grade report has been saved to " << outputFileName << "\n\n";
	fout.close();
}

void printNoScoreList(ofstream &fout)
{
	// This function opens the input file for names of students with no scores
	// and prints them to the monitor and output file

	ifstream fin;
	string noScoreName;

	cout << "The following students had no test scores:" << endl;
	fout << "The following students had no test scores:" << endl;

	fin.open("noScoreFile.txt");
	getline(fin, noScoreName);

	while (!fin.eof())
	{
		cout << setw(7) << "" << ">> " << noScoreName << endl;
		fout << setw(7) << "" << "<> " << noScoreName << endl;
		getline(fin, noScoreName);
	}

	fin.close();
}

void printRangeProbList(ofstream &fout)
{
	// This function opens the input file for names of students with range problems
	// and prints them to the monitor and output file

	ifstream fin;
	string rangeProbName;

	cout << "\nThe following students had score(s) that fell"
		<< "\noutside the allotted range:" << endl;
	fout << "\nThe following students had score(s) that fell"
		<< "\noutside the allotted range:" << endl;

	fin.open("rangeProbFile.txt");
	getline(fin, rangeProbName);

	while (!fin.eof())
	{
		cout << setw(7) << "" << ">> " << rangeProbName << endl;
		fout << setw(7) << "" << "<> " << rangeProbName << endl;
		getline(fin, rangeProbName);
	}

	fin.close();
}

bool checkValue(int score)
{
	// This function checks whether or not the score lies within the allotted range

	bool result;

	if (score >= 0 && score <= 100)
		result = true;
	else
		result = false;

	return result;
}

float averageScores(float sum, int count)
{
	// This function calculates and returns the average of test scores

	float avg;
	avg = sum / count;

	return avg;
}

char calcLetterGrade(float avg)
{
	// This function returns a letter grade based on the average

	char grade;

	if (avg <= 100 && avg > 90)
		grade = 'A';
	else if (avg > 80)
		grade = 'B';
	else if (avg > 67.5)
		grade = 'C';
	else if (avg > 55)
		grade = 'D';
	else if (avg >= 0)
		grade = 'F';

	return grade;
}

// YES! I'm DONE! And. It. Looks. Awesome. ^-^(v)
