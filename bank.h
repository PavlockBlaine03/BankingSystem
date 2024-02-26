#pragma once
#include <iostream>
#include <string>

using namespace std;

class Bank
{
protected:
	string mBankName = "";
	string mCity;
	double mInterestRate = 0.0;
public:
	Bank() {}
	Bank(string bankName, string city, double interest) { mBankName = bankName; mCity = city; mInterestRate = interest; }
	string getBankName() const { return mBankName; }
	string getCity() const { return mCity; }
	double getInterestRate() const { return mInterestRate; }

	void setBankName(string bName) { mBankName = bName; }
	void setCity(string city) { mCity = city; }
	void setInterestRate(double rate) { mInterestRate = rate; }

	bool isStudent()
	{
		char input;
		cout << "Is the account for a student? Y/N \n";
		cin >> input;
		if (input == 'Y' or input == 'y')
			return true;
		else if (input == 'N' or input == 'n')
			return false;
		else
			cout << "Invalid input.\n";
	}
	bool isOverdraft()
	{
		char input;
		cout << "Do you want to include overdraft coverage? Y/N \n";
		cin >> input;
		if (input == 'Y' or input == 'y')
			return true;
		else if (input == 'N' or input == 'n')
			return false;
		else
			cout << "Invalid input.\n";
	}
	void printBankInfo()
	{
		cout << "Bank Name: " << mBankName << endl;
		cout << "City: " << mCity << endl;
		cout << "Interest Rate: " << mInterestRate << endl;
	}
};