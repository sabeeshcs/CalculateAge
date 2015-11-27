#pragma once

#include <iostream>
#include <ctime>
#include <sstream>
#include <vector>
using namespace std;


class CDate
{
private:
	
	int day, month, year;
	const int monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

public:
	void init(void);
	void initDate(unsigned short& month, unsigned short& day, unsigned short& year);

	bool IsValidDate(const string& sDate);
	std::vector<std::string> &CDate::Split(const std::string &s, char delim, std::vector<std::string> &elems);
	std::vector<std::string> CDate::Split(const std::string &s, char delim);
	bool IsLeapYear(unsigned short year);
	bool IsValid_Date(unsigned short year, unsigned short month, unsigned short day);
	int operator - (const CDate& pCDate);

	void printDate() const;
	int countLeapYears() const;

};
