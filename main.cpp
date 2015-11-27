
#include <string>
#include <iostream>
#include "CalculateAge.h"

using namespace std;
int main()
{
	std::string sDate;
	bool bContinue = true;

	while (bContinue)
	{
		cout << "Please enter the date of birth ( in dd-mm-yyyy format )";
		std::getline(std::cin, sDate);

		CDate pCDate;
		bContinue = pCDate.IsValidDate(sDate);	//Check the input date and set the date

		if (bContinue)
		{
			CDate pCurrentDate;
			pCurrentDate.init(); //Set current Date

			double diff = pCDate - pCurrentDate;

			cout << "Age is " << diff << " days!"<< endl;

			bContinue = false;
		}
		else
		{
			cout << "Invalid Date format! Please try again.";
			cin.ignore();
			bContinue = true;
		}
		

	}
	cin.ignore();
}

