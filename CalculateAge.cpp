#include "CalculateAge.h"

void CDate::init(void) 
{
	time_t rawtime = time(nullptr);
	tm timeinfo;
	errno_t error = localtime_s(&timeinfo, &rawtime);

	this->day = timeinfo.tm_mday;
	this->month = 1 + timeinfo.tm_mon;
	this->year = 1900 + timeinfo.tm_year;

}

void CDate::initDate(unsigned short& month, unsigned short& day, unsigned short& year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

bool CDate::IsValidDate(const string& sDate) 
{
	std::vector<std::string> vData;
	unsigned short year, month, day;

	vData = Split(sDate, '-');
	if(vData.size() != 3 )
		vData = Split(sDate, '/');

	if (vData.size() !=3 )
		return false;
	else
	{

		day = (unsigned short)atoi(vData[0].c_str());
		month = (unsigned short)atoi(vData[1].c_str());
		year = (unsigned short)atoi(vData[2].c_str());

		if (IsValid_Date(year, month, day) == true)
		{
			initDate(month, day, year);
			return true;
		}
		else
			return false;
	}
}

std::vector<std::string> &CDate::Split(const std::string &s, char delim, std::vector<std::string> &elems) {
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;
}

std::vector<std::string> CDate::Split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	Split(s, delim, elems);
	return elems;
}

bool CDate::IsLeapYear(unsigned short year) 
{
	return (!(year % 4) && (year % 100) || !(year % 400));
}

bool CDate::IsValid_Date(unsigned short year, unsigned short month, unsigned short day)
{
	unsigned short monthlen[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (!year || !month || !day || month>12)
		return 0;
	if (IsLeapYear(year) && month == 2)
		monthlen[1]++;
	if (day > monthlen[month - 1])
		return 0;

	if (year <= 0 || year > 9999)
		return 0;

	return 1;
}

int CDate::operator - (const CDate& pCDate)
{
	int difference = 0;

	long int n1 = this->year * 365 + this->day;

	for (int i = 0; i<this->month - 1; i++)
		n1 += monthDays[i];

	// Since every leap year is of 366 days,
	// Add a day for every leap year
	n1 += this->countLeapYears();

	long int n2 = pCDate.year * 365 + pCDate.day;
	for (int i = 0; i<pCDate.month - 1; i++)
		n2 += monthDays[i];
	n2 += pCDate.countLeapYears();

	// return difference between two counts
	return (n2 - n1);
}

void CDate::printDate() const
{
	cout << "Month" << month << endl;
	cout << "Day" << day << endl;
	cout << "Year " << year;
}

int CDate::countLeapYears() const
{
	int years = this->year;

	// Check if the current year needs to be considered
	// for the count of leap years or not
	if (this->month <= 2)
		years--;

	// An year is a leap year if it is a multiple of 4,
	// multiple of 400 and not a multiple of 100.
	return years / 4 - years / 100 + years / 400;
}
