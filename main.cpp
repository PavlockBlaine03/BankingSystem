#include "Account.h"
#include "Login.h"

int main()
{
	string city;
	string bankname;
	double interestRate;
	
	char input;
	cout << "Press Y to create login, N to close out.\n";
	cin >> input;

	if (input != 'Y' and input != 'y')
	{
		return 0;
	}

	string user;
	string pass;
	cout << "Enter login creditials.\n";
	cin >> user >> pass;
	Login login(user, pass);


	string username = "";
	string password = "";
	cout << "Please login:\n";
	cin >> username >> password;

	while (login.isLogin(username, password))
	{
		// setting up the bank account with basic info
		cout << "Please enter the bank name, city, and the interest rate of the bank.\n";
		cin >> bankname >> city >> interestRate;
		Bank bank1(bankname, city, interestRate);
		bank1.printBankInfo();

		string accountType;
		cout << "Checking or Savings\n";
		cin >> accountType;

		if (accountType == "Checking" or accountType == "checking")
		{
			Checking check1(bank1);
			Account person1(check1, "Blaine", 77777, 750, 2354, 25000);
			person1.withdraw();
		}
		if (accountType == "Savings" or accountType == "savings")
		{
			Savings save1(bank1, 24);
			save1.setFees(34.56);
			cout << "Your savings period is: " << save1.getSavingPeriod() << endl;
			save1.hasFees();
		}
	}
	return 0;
}