#pragma once
#include "bank.h"

class Checking : public Bank
{
protected:
	bool mOverDraft = false;
	bool mStudentAccount = false;
public:
	Checking() {}
	Checking(Bank& bank)
	{
		mBankName = Bank::getBankName(); 
		mCity = Bank::getCity(); 
		mInterestRate = Bank::getInterestRate();
		mStudentAccount = Bank::isStudent();
		mOverDraft = Bank::isOverdraft();
	}
	void printOverdraft() const
	{
		if (mOverDraft)
			cout << "You have overdraft coverage.\n";
		else
			cout << "You do not have overdraft coverage.\n";
	}
	void printStudent() const
	{
		if (mStudentAccount)
			cout << "This account is setup for a student.\n";
		else
			cout << "This account is not a student account.\n";
	}
	void setOverdraft(bool overdraft)
	{
		mOverDraft = overdraft;
	}
	void setStudentAccount(bool student)
	{
		mStudentAccount = student;
	}

};

// Make a savings class 
class Savings : public Bank
{
protected:
	int mSavingTime = 0;
	double mFees = 0.0;
	bool mHaveFees = false;
public:
	Savings() {}
	Savings(Bank& bank, int savingTime)
	{
		mBankName = Bank::getBankName();
		mCity = Bank::getCity();
		mInterestRate = Bank::getInterestRate();
		mSavingTime = savingTime;
	}
	void hasFees()
	{
		if (mFees > 0)
		{
			cout << "You owe: " << mFees << "\n";
			mHaveFees = true;
		}
		else
			cout << "No outstanding fees.\n";
	}
	void setFees(double fees)
	{
		mFees = fees;
	}
	void setSavingPeriod(int period)
	{
		mSavingTime = period;
	}
	double getFees()
	{
		return mFees;
	}
	int getSavingPeriod()
	{
		return mSavingTime;
	}
};