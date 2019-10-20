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
		return  "Invalid type of month";
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
	
	Season getSeason(Date date)
	{
		return getSeason(date.month);

	}
	Season getSeason(Month month)
	{
		if ((static_cast<int>(month) == 12) || (static_cast<int>(month) == 1) || (static_cast<int>(month) == 2))
		{
			return Season::Winter;
		}
			if ((static_cast<int>(month) > 2) & (static_cast<int>(month) < 6))
			{
				return Season::Spring;
			}
			if ((static_cast<int>(month) > 5) & (static_cast<int>(month) < 9))
			{
				return Season::Summer;
			}
			if ((static_cast<int>(month) > 8) & (static_cast<int>(month) < 12))
			{
				return Season::Autumn;
			}
			
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
	
//Домашнее задание 4
	TimeDelta& operator ++ ( TimeDelta& delta)
	{
		++delta.delta;
		return delta;
	}
	TimeDelta& operator ++ (TimeDelta& delta,int)
	{
		TimeDelta temp = delta;
		++delta.delta;
		return temp;
	}
	TimeDelta& operator -- (TimeDelta& delta)
	{
		--delta.delta;
		return delta;
	}
	TimeDelta& operator -- (TimeDelta& delta, int)
	{
		TimeDelta temp=delta;
		--delta.delta;
		return temp;
	}

	Date& operator ++ (Date& delta)
	{
		++delta.day;
		++delta.year;
		delta.month=static_cast<Month>(static_cast<int>(delta.month) + 1);
		return delta;
	}
	Date& operator ++ (Date& delta, int)
	{
		Date temp = delta;
			++delta.day;
			++delta.year;
			delta.month = static_cast<Month>(static_cast<int>(delta.month) + 1);
			return temp;
	}
	Date& operator -- (Date& delta)
	{
		--delta.day;
		--delta.year;
		delta.month = static_cast<Month>(static_cast<int>(delta.month) - 1);
		return delta;
	}
	Date& operator -- (Date& delta, int)
	{
		Date temp = delta;
		--delta.day;
		-delta.year;
		delta.month = static_cast<Month>(static_cast<int>(delta.month)- 1);
		return temp;
	}


	void swap(Date& lhs, Date& rhs)
	{
		Date	temp = lhs;
		lhs = rhs;
		rhs = temp;
	}
	void swap(TimeDelta& lhs, TimeDelta& rhs)
	{
		TimeDelta temp = lhs;
		lhs = rhs;
		rhs = temp;
	}


	Date& max(Date& lhs, Date& rsh)
	{
		return countJND(lhs).delta > countJND(rsh).delta ? lhs : rsh;
	}
	Date& min(Date& lhs, Date& rsh)
	{
		return countJND(lhs).delta < countJND(rsh).delta ? lhs : rsh;
	}

	Date& getMinDate(Date dates[], int size)
	{
		Date min=dates[0];

		for (int i = 1; i < size; ++i)
		{
			if (countJND(dates[i]).delta < countJND(min).delta)
			{
				min = dates[i];
			}
		}
		return min;
	}
	Date& getMaxDate(Date dates[], int size)
	{
		Date max = dates[0];

		for (int i = 1; i < size; ++i)
		{
			if (countJND(dates[i]).delta > countJND(max).delta)
			{
				max = dates[i];
			}
		}
		return max;
	}
	void sort(Date dates[],int size, SortBy sortBy)
	{
		if(sortBy==SortBy::Date)
		{
			bool isSwap = false;
			for (int i = 0; i < size; ++i)
			{

				for (int j = 0; j < size - 1 - i; ++j)
				{
					if (countJND(j).delta>countJND(j+1).delta)
					{
						Date temp = dates[j];
						dates[j] = dates[j + 1];
						dates[j + 1] = temp;
						isSwap = true;
					}
				}
				if (!isSwap)return;
				isSwap = false;
			}
		}

}