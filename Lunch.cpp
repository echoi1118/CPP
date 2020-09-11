/*

-----------------------------------------
Program Description:
	
	Program Lunch calculates the number of calories in a cheese sandwich. Each sandwich contains
	2 slices of bread, 3 slices of cheese, 4 pieces of pickles, and 2 grams of mayonnaise.
-----------------------------------------

*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	string name;

	int breadCalories = 63;				// Calories in a slice of bread
	int cheeseCalories = 106;			// Calories in a slice of cheese
	int mayonnaiseCalories = 49;		// Calories in 1 gram of mayonnaise
	int pickleCalories = 25;			// Calories in a slice of pickle

	float breadSlices;					// Variables that store user input for
	float cheeseSlices;					// the amount of each food item
	float mayonnaiseGrams;
	float pickleSlices;

	float totalBreadCalories,
		totalCheeseCalories,
		totalMayonnaiseCalories,
		totalPicklesCalories;

	float totalCalories;

	cout << fixed << left << showpoint << setprecision(2) << endl;
	cout << setw(25) << "" << "Welcome to my Calorie Counter\n\n";

	cout << setw(10) << "Please enter your name: ";
	getline(cin, name);
	cout << "\n\nHi, " << name << ". Please enter the number of ingredients used in your sandwich." << endl;
	cout << "\n" << setw(70) << "Please enter number of slices of bread used (0 if not used):";
	cin >> breadSlices;
	cout << setw(70) << "Please enter number of slices of cheese used (0 if not used):";
	cin >> cheeseSlices;
	cout << setw(70) << "Please enter amount of mayonnaise in grams used (0 if not used):";
	cin >> mayonnaiseGrams;
	cout << setw(70) << "Please enter number of pieces of pickle used (0 if not used):";
	cin >> pickleSlices;
	
	totalBreadCalories = breadCalories * breadSlices;
	totalCheeseCalories = cheeseCalories * cheeseSlices;
	totalMayonnaiseCalories = mayonnaiseCalories * mayonnaiseGrams;
	totalPicklesCalories = pickleCalories * pickleSlices;

	cout << "\n\n" << setw(30) << "Bread calories:" << totalBreadCalories << endl;
	cout << setw(30) << "Cheese calories:" << totalCheeseCalories << endl;
	cout << setw(30) << "Mayonnaise calories:" << totalMayonnaiseCalories << endl;
	cout << setw(30) << "Pickles calories: " << totalPicklesCalories << endl;

	totalCalories = totalBreadCalories + totalPicklesCalories + totalCheeseCalories + totalMayonnaiseCalories;

	cout << "\n\n" << setw(30) << "Total calories:" << totalCalories << endl;

	cout << "\n\nThere were " << totalCalories << " calories in my lunch yesterday." << endl;
	cout << "What is for lunch today? Funny!!!!" << endl;

	return 0;
}
