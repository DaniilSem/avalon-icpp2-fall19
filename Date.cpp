#include"Date.hpp"
#include<iostream>
#include<string>
namespace ext
{
	std::string montToString(Month month)
	{
		switch (month)
		{
		case Month::January:
			return "january";
			break;
		case Month::February:
			return "February";
			break;
		case Month::March:
			return "March";
			break;
		case Month::April:
			return "April";
			break;
		case Month::May:
			return"May";
			break;
		case Month::June:
			return "June";
			break;
		case Month::July:
			return "July";
			break;
		case Month::August:
			return"August";
			break;
		case Month::September:
			return "September";
			break;
		case Month::October:
			return "October";
			break;
		case Month::Novemver:
			return "November";
			break;
		case Month::December:
			return "December";
			break;
		}

	}
	void print(Date data, DateFormat format)
	{
		std::cout << data.year << " ";
		print(data.month, format);
		std::cout << data.day;
	}
	void print(Month month, DateFormat format)
	{
		if (DateFormat::MonthAsInt == format)
		{
			std::cout << static_cast<int>(month) << " ";
		}
		else if (format == DateFormat::MonthAsString)
		{
			std::cout << montToString(month);
			std::cout << " ";
		}
		else
		{
			throw std::exception("Invalid format of month");
		}
	}

}