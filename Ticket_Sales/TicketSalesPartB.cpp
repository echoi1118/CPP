/*

ID block  
+---------------------------------------------------+
+ Programmer  : Esther Choi
+ Course      : Computer Science 1
+ Lab Section :	0101 (MW at 10 am)
+ Grader      :	M. Ghyam
+ Assignment  :	Ticket Sales Calculator, Part B
+ Due Date    : Sep. 28, 2015
+---------------------------------------------------+

Program statement:	This program calculates ticket sales
			after each game and calculates city
			taxes based on total net sales.

*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int boxPrice = 250,
		sidelinePrice = 100,
		premiumPrice = 50,
		generalAdmPrice = 25;

	float boxCommissionRate = .05f,
		sidelineCommissionRate = .025f,
		premiumCommissionRate = .015f,
		generalAdmCommissionRate = .01f;

	int boxTicketsSold,
		sidelineTicketsSold,
		premiumTicketsSold,
		generalAdmTicketsSold,
		totalTicketsSold;

	float boxGrossSales,
		sidelineGrossSales,
		premiumGrossSales,
		generalAdmGrossSales,
		totalGrossSales;

	float boxCommission,
		sidelineCommission,
		premiumCommission,
		generalAdmCommission,
		totalCommission;

	float boxNetSales,
		sidelineNetSales,
		premiumNetSales,
		generalAdmNetSales,
		totalNetSales;

	float cityTaxes,
		netIncome;

	cout << left << setw(65) << "Please enter number of Box Type tickets sold:";
	cin >> boxTicketsSold;

	// Validate the user input for number of Box tickets sold
	while (!cin || boxTicketsSold < 0)
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << setw(65) << "Input must be numeric and greater than or equal to 0:";
		cin >> boxTicketsSold;
	}

	cout << setw(65) << "Please enter number of Sideline Type tickets sold:";
	cin >> sidelineTicketsSold;

	// Validate the user input for number of Sideline tickets sold
	while (!cin || sidelineTicketsSold < 0)
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << setw(65) << "Input must be numeric and greater than or equal to 0:";
		cin >> sidelineTicketsSold;
	}

	cout << setw(65) << "Please enter number of Premium Type tickets sold:";
	cin >> premiumTicketsSold;

	// Validate the user input for number of Premium tickets sold
	while (!cin || premiumTicketsSold < 0)
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << setw(65) << "Input must be numeric and greater than or equal to 0:";
		cin >> premiumTicketsSold;
	}

	cout << setw(65) << "Please enter number of General Admission Type tickets sold:";
	cin >> generalAdmTicketsSold;

	// Validate the user input for number of General Admission tickets sold
	while (!cin || generalAdmTicketsSold < 0)
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << setw(65) << "Input must be numeric and greater than or equal to 0:";
		cin >> generalAdmTicketsSold;
	}

	boxGrossSales = boxPrice * boxTicketsSold;
	sidelineGrossSales = sidelinePrice * sidelineTicketsSold;
	premiumGrossSales = premiumPrice * premiumTicketsSold;
	generalAdmGrossSales = generalAdmPrice * generalAdmTicketsSold;

	boxCommission = boxCommissionRate * boxGrossSales;
	sidelineCommission = sidelineCommissionRate * sidelineGrossSales;
	premiumCommission = premiumCommissionRate * premiumGrossSales;
	generalAdmCommission = generalAdmCommissionRate * generalAdmGrossSales;

	boxNetSales = boxGrossSales - boxCommission;
	sidelineNetSales = sidelineGrossSales - sidelineCommission;
	premiumNetSales = premiumGrossSales - premiumCommission;
	generalAdmNetSales = generalAdmGrossSales - generalAdmCommission;

	totalTicketsSold = boxTicketsSold + sidelineTicketsSold + premiumTicketsSold + generalAdmTicketsSold;
	totalGrossSales = boxGrossSales + sidelineGrossSales + premiumGrossSales + generalAdmGrossSales;
	totalCommission = boxCommission + sidelineCommission + premiumCommission + generalAdmCommission;
	totalNetSales = boxNetSales + sidelineNetSales + premiumNetSales + generalAdmNetSales;

	if (totalNetSales > 1000000)
		cityTaxes = .04 * 100000 + .03 * (totalNetSales - 100000) + .02 * (totalNetSales - 550000) + .01 * (totalNetSales - 1000000);
	else if (totalNetSales >= 550000.01)
		cityTaxes = .04 * 100000 + .03 * (totalNetSales - 100000) + .02 * (totalNetSales - 550000);
	else if (totalNetSales >= 100000.01)
		cityTaxes = .04 * 100000 + .03 * (totalNetSales - 100000);
	else
		cityTaxes = .04 * totalNetSales;

	netIncome = totalNetSales - cityTaxes;

	cout << showpoint << setprecision(2) << fixed;
	cout << "\n" << setw(13) << "Ticket Type" << setw(14) << "Ticket Price" << setw(15) << "Tickets sold" << setw(13) << "Gross Sales" << setw(12) << "Commission" << "Net Sales" << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << setw(13) << "Box" << "$" << setw(13) << boxPrice << setw(15) << boxTicketsSold << "$" << setw(12) << boxGrossSales << "$" << setw(11) << boxCommission << "$" << boxNetSales << endl;
	cout << setw(13) << "Sideline" << "$" << setw(13) << sidelinePrice << setw(15) << sidelineTicketsSold << "$" << setw(12) << sidelineGrossSales << "$" << setw(11) << sidelineCommission << "$" << sidelineNetSales << endl;
	cout << setw(13) << "Premium" << "$" << setw(13) << premiumPrice << setw(15) << premiumTicketsSold << "$" << setw(12) << premiumGrossSales << "$" << setw(11) << premiumCommission << "$" << premiumNetSales << endl;
	cout << setw(13) << "Gen. Adm." << "$" << setw(13) << generalAdmPrice << setw(15) << generalAdmTicketsSold << "$" << setw(12) << generalAdmGrossSales << "$" << setw(11) << generalAdmCommission << "$" << generalAdmNetSales << endl;
	cout << "-------------------------------------------------------------------------------\n\n";

	cout << setw(6) << "" << setw(30) << "Total # of tickets sold:" << totalTicketsSold << endl;
	cout << setw(6) << "" << setw(30) << "Total Gross Sales:" << "$" << totalGrossSales << endl;
	cout << setw(6) << "" << setw(30) << "Total Commission:" << "$" << totalCommission << endl;
	cout << setw(6) << "" << setw(30) << "Total Net Sales:" << "$" << totalNetSales << endl;
	cout << setw(6) << "" << setw(30) << "City Taxes:" << "$" << cityTaxes << endl;
	cout << setw(6) << "" << setw(30) << "Net Income:" << "$" << netIncome << endl;
	cout << "\n";

	return 0;
}
