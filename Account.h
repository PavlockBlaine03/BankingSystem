#pragma once
#include "AccountTypes.h"

class Account : public Checking, Savings, Bank
{
protected:
	string mName;
	int mZip;
	int mCredit;
	int mAccountNum;
	double mAmount = 0;

public:
	Account(Savings& save, string name, int zip, int credit, int accountNum, double initialDeposit)
	{
		mSavingTime = Savings::getSavingPeriod();
		mName = name;
		mZip = zip;
		mCredit = credit;
		mAccountNum = accountNum;
		mAmount = initialDeposit;
	}
	Account(Checking& check, string name, int zip, int credit, int accountNum, double initialDeposit)
	{
		mName = name;
		mZip = zip;
		mCredit = credit;
		mAccountNum = accountNum;
		mAmount = initialDeposit;
	}
	void setName(string name)
	{
		mName = name;
	}
	void setZip()
	{
		int zip;
		cout << "Enter your Zip code:\n";
		cin >> zip;
		mZip = zip;
	}
	void setAccountNum()
	{
		int accountNum;
		cout << "Enter a account number for your account:\n";
		cin >> accountNum;
		mAccountNum = accountNum;
	}
	void deposit(double amount)
	{
		if (mFees > 0)
		{
			mAmount += amount - mFees;
		}
		else
			mAmount = amount;
	}

	string getName()
	{
		return mName;
	}
	int getZip()
	{
		return mZip;
	}
	int getAccountNum()
	{
		return mAccountNum;
	}
	double getAmount()
	{
		if (mAmount < 0)
		{
			cout << "You account is in debt.\n";
			return mFees;
		}
		else
			return mAmount;
	}
	double withdraw()
	{
		double amount = 0.0;
		cout << "How much would you like to withdraw?\n";
		cin >> amount;
		if (mAmount < 0)
		{
			cout << "Not enough funds.\n";
			return 0;
		}
		else
		{
			mAmount -= amount;
			return amount;
		}
	}
};