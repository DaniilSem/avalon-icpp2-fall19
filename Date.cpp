#include"Date.hpp"
#include<iostream>
#include<string>
namespace ext
{
	TimeDelta countJND(Date date)
	{
		unsigned int a, y, m;
		a = (14 - static_cast<int> (date.month)) / 12;
		y = date.year = 4800 - a;
		m = static_cast<int>(date.month) + 12 * a - 3;
		TimeDelta jdn;
		jdn.delta = date.day + (153 * m + 2) / 5 + 365 * y
			+ y / 4 - y / 100 + y / 400 - 32045;
		return jdn;
	}
	TimeDelta countDistance(Date from, Date to)
	{
		TimeDelta delta;
		delta.delta = countJND(to).delta - countJND(from).delta;
		return delta;
	}
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
	void print(TimeDelta delta)
	{
		std::cout << delta.delta << std::endl;
	}

	bool  operator == (const Date lhs, const Date rhs)
	{
		return lhs.day == rhs.day
			&& lhs.month == rhs.month
			&& lhs.year == rhs.year;
	}
	bool operator != (const Date lhs, const Date rhs)
	{
		return !(lhs == rhs);
	}
	bool operator < (const Date lhs, const Date rhs)
	{
		return lhs.day < rhs.day
			&& lhs.month < rhs.month
			&& lhs.year < rhs.year;
	}
	bool operator <= (const Date lhs, const Date rhs)
	{
		return(lhs == rhs) || (lhs < rhs);
	}
	bool operator > (const Date lhs, const Date rhs)
	{
		return lhs.day > rhs.day
			&& lhs.month > rhs.month
			&& lhs.year > rhs.year;
	}
	bool operator >= (const Date lhs, const Date rhs)
	{
		return (lhs == rhs) || (lhs > rhs);
	}
}