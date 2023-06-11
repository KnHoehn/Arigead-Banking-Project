#include "Banking.h"
#include <iostream>
#include <iomanip>

using namespace std;

void Banking::CreateAccount(double t_initialInvestAmount, double t_monthlyDeposit, 
	                        double t_annualInterest, int t_numYears) {
	/*
	This creates an account using variables input from the user
	*/
	
	m_initialInvestAmount = t_initialInvestAmount;
	m_monthlyDeposit = t_monthlyDeposit;
	m_annualInterest = t_annualInterest;
	m_numYears = t_numYears;
}

double Banking::CalculateInterest(double t_initialDepositAmount, double t_monthlyDeposits, double t_interest) {

	/*
	This calculates and returns yearly accumulated interest with monthly deposits figured in
	*/

	m_currentBalance = t_initialDepositAmount;
	m_totalInterest = 0;

	// Loop that iterates over the 12 months of the year adding interest and any deposits made
	for (j = 0; j < 12; j++) { 
		m_monthlyInterest = (m_currentBalance + t_monthlyDeposits) * ((t_interest / 100) / 12);
		m_currentBalance += (m_monthlyInterest + t_monthlyDeposits);
		m_totalInterest += m_monthlyInterest;
	}

	return m_totalInterest;

}

double Banking::CalculateInterest(double t_initialDepositAmount, double t_interest) {

	/*
	This calculates and returns accumulated interest not given any monthly deposits
	*/

	m_totalInterest = ((t_initialDepositAmount + 0) * ((t_interest / 100) / 12) * 12);

	return m_totalInterest;

}

double Banking::CalculateBalance(double t_initialDepositAmount, double t_monthlyDeposits, double t_interest) {

	/*
	This calculates and returns the total yearly balance given accumalated interest and deposits
	*/

	m_balance = t_initialDepositAmount;

	// Loop that iterates over the 12 months of the year adding interest and any deposits made
	for (ij = 0; ij < 12; ij++) {
		m_interest = (m_balance + t_monthlyDeposits) * ((t_interest / 100) / 12);
		m_balance += (m_interest + t_monthlyDeposits);
	}

	return m_balance;

}


void Banking::PrintAccount() {

	/*
	This prints the account information. It firsts prints information without figuring in any
	monthly deposits. Then it prints figuring in monthly deposits
	*/

	
	m_currentInterest = CalculateInterest(m_initialInvestAmount, m_annualInterest); // Calls the CalculateInterest function
	m_yearEndBalance = m_initialInvestAmount + m_currentInterest;

	cout << "    Balance And Interest Without Additional Monthly Deposits" << endl;
	cout << "================================================================" << endl;
	cout << " Year         Year End Balance          Year End Earned Interest" << endl;
	
	// Loop that iterates for each year the user entered, displaying account information
	for (i = 1; i <= m_numYears; i++) { 
		cout << fixed << setprecision(2) << "  " << i << "                 " << m_yearEndBalance << "                          " << m_currentInterest << endl;
		m_currentInterest = CalculateInterest(m_yearEndBalance, m_annualInterest); // Calls the CalculateInterest function
		m_yearEndBalance = m_yearEndBalance + m_currentInterest;

	}
	
	m_currentInterest = CalculateInterest(m_initialInvestAmount, m_monthlyDeposit, m_annualInterest);
	m_yearEndBalance = CalculateBalance(m_initialInvestAmount, m_monthlyDeposit, m_annualInterest);

	cout << "     Balance And Interest With Additional Monthly Deposits" << endl;
	cout << "================================================================" << endl;
	cout << " Year         Year End Balance          Year End Earned Interest" << endl;
	
	// Loop that iterates for each year the user entered, displaying account information
	for (i = 1; i <= m_numYears; i++) { 
		cout << fixed << setprecision(2) << "  " << i << "                 " << m_yearEndBalance << "                      " << m_currentInterest << endl;
		m_currentInterest = CalculateInterest(m_yearEndBalance, m_monthlyDeposit, m_annualInterest); // Calls the CalculateInterest function
		m_yearEndBalance =  CalculateBalance(m_yearEndBalance, m_monthlyDeposit, m_annualInterest); // Calls the CalculateBalance funciton

	}
}
