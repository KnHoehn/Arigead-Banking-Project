/*
Developer: Kayla Hoehn
Date: 4/2/2023
Program Purpose:
                The purpose of this program is to display interest accumalated from the user's
				initial deposits amount and any deposits made monthly
*/

#include <iostream>
#include "Banking.h"
#include <iomanip>

using namespace std;

int main() {
	double userAmount;
	double userMonthlyDeposit;
	double userInterest;
	int userNumYears;
	char userAnswer;
	bool userContinue = true;
	Banking accountWMonthlyDeposits;
	
	// Loop that iterates until the user types "N"
	while (userContinue) {
		// Displays and gets input from the user
		cout << endl;
		cout << "**********************************" << endl;
		cout << "********** Data Input ************" << endl;
		cout << "Initial Investment Amount: ";
		cin >> userAmount;
		cout << endl;
		cout << "Monthly Deposit: ";
		cin >> userMonthlyDeposit;
		cout << endl;
		cout << "Annual Interest: %";
		cin >> userInterest;
		cout << endl;
		cout << "Number Of Years: ";
		cin >> userNumYears;
		cout << endl;

		// Creates an object with the user's account information
		accountWMonthlyDeposits.CreateAccount(userAmount, userMonthlyDeposit, userInterest, userNumYears);

		// Calls the print function
		accountWMonthlyDeposits.PrintAccount();

		cout << endl;

		cout << "Test again with different values? Y/N: "; // Asks if the user wants to continue

		cin >> userAnswer;

		if (userAnswer == 'N' || userAnswer == 'n') { // Breaks loop if user enters "N"
			cout << "Goodbye" << endl;
			userContinue = false;
		}
		else {
			continue;
		}
	}
}