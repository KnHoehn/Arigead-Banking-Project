#pragma once
class Banking // Creates class "Banking"

{
	// Declares public functions for the class
public:
	double CalculateBalance(double t_initialDepositAmount, double t_monthlyDeposits, double t_interest);
	double CalculateInterest(double t_initialDepositAmount, double t_monthlyDeposits, double t_interest);
	double CalculateInterest(double t_initialDepositAmount, double t_interest);
	void CreateAccount(double t_initialInvestAmount, double t_monthlyDeposit, 
		               double t_annualInterest, int t_numYears);
	void PrintAccount();

	// Creates private variables to be used within the class and it's funcitons
private:
	double m_initialInvestAmount ;
	double m_monthlyDeposit;
	double m_annualInterest;
	double m_yearEndBalance;
	double m_currentBalance;
	double m_currentInterest;
	double m_monthlyInterest;
	double m_totalInterest;
	double m_balance;
	double m_interest;
	int m_numYears;
	int i;
	int j;
	int ij;
};

