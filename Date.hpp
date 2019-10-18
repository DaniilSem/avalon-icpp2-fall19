#pragma once
#include<iostream>
namespace ext
{
	enum class Month
	{
		January = 1,
		February,
		March,
		April,
		May,
		June,
		July,
		August,
		September,
		October,
		Novemver,
		December
	};

	enum DateFormat
	{
		MonthAsInt,
		MonthAsString
	};

	enum Season
	{
		Winter,
		Spring,
		Summer,
		Autumn
	};

	struct Date
	{
		int year;
		Month month;
		int day;
	};

	struct TimeDelta
	{
		int delta;
	};

	/*
		Âîçâðàùàåò Þëèàíñêóþ äàòó
		https://ru.wikipedia.org/wiki/%D0%AE%D0%BB%D0%B8%D0%B0%D0%BD%D1%81%D0%BA%D0%B0%D1%8F_%D0%B4%D0%B0%D1%82%D0%B0
		ðàçäåë "Âû÷èñëåíèå íîìåðà þëèàíñêîãî äíÿ (JDN) ïî äàòå ãðèãîðèàíñêîãî êàëåíäàðÿ"
		Òåñòîâûå äàííûå					Îæèäàåìûé ðåçóëüòàò
		1.12.2018					2458454
		1.1.2018					2458120
		1.6.2000					2451697
		21.12.2012					2456283
	*/
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

	/*
		Ðàññ÷èòûâàåò êîëè÷åñòâî äíåé ìåæäó äâóìÿ äàòàìè.
		Ïðè ðåàëèçâàöèè èñïîëüçóéòå CountJND
	*/
	TimeDelta countDistance(Date from, Date to)
	{
		TimeDelta delta;
		delta.delta = countJND(to).delta - countJND(from).delta;
		return delta;
	}

	/*
		Âûâîäèò â êîíñîëü
	*/
	void print(Date data, DateFormat format = DateFormat::MonthAsInt)
	{
		std::cout << data.day << "/";
		print(data.month, format);
		std::cout << data.year << std::endl;
	}
	void printer(Month month)
	{
		if(static_cast<int>(month)==1)
		{
			std::cout <<"Januar"<<"/" ;
		}
		if (static_cast<int>(month) == 2)
		{
			std::cout << "February" << "/";
		}
		if (static_cast<int>(month) == 3)
		{
			std::cout << "March" << "/";
		}
		if (static_cast<int>(month) == 4)
		{
			std::cout << "April" << "/";
		}
		if (static_cast<int>(month) == 5)
		{
			std::cout << "May" << "/";
		}
		if (static_cast<int>(month) == 6)
		{
			std::cout << "June" << "/";
		}
		if (static_cast<int>(month) == 7)
		{
			std::cout << "July" << "/";
		}
		if (static_cast<int>(month) == 8)
		{
			std::cout << "August" << "/";
		}
		if (static_cast<int>(month) == 9)
		{
			std::cout << "September" << "/";
		}
		if (static_cast<int>(month) == 10)
		{
			std::cout << "October" << "/";
		}
		if (static_cast<int>(month) == 11)
		{
			std::cout << "November" << "/";
		}
		if (static_cast<int>(month) == 12)
		{
			std::cout << "December" << "/";
		}
	}
	void print(Month month, DateFormat format = DateFormat::MonthAsInt)
	{
		if (format == DateFormat::MonthAsInt)
		{
			std::cout << static_cast<int>(month) << "/";
		}
		else
		{
			printer(month);
		}
	}
	void print(TimeDelta delta)
	{
		std::cout << delta.delta << std::endl;
	}

	/*
		Âîçâðàùàåò ñåçîí (çèìà, âåñíà, ëåòî, îñåíü) ïåðåäàâàåìîé äàòû
	*/
	Season getSeason(Date date)
	{
		if ((static_cast<int>(date.month) == 12) || (static_cast<int>(date.month) == 1) || (static_cast<int>(date.month) == 2))
		{
			std::cout << "Winter" << std::endl;
		}
		if ((static_cast<int>(date.month)>2)& (static_cast<int>(date.month)<6))
		{
			std::cout << "Spring" << std::endl;
		}
		if ((static_cast<int>(date.month) > 5) & (static_cast<int>(date.month) < 9))
		{
			std::cout << "Summer" << std::endl;
		}
		if ((static_cast<int>(date.month) > 8) & (static_cast<int>(date.month) < 12))
		{
			std::cout << "Fall" << std::endl;
		}
	}
	Season getSeason(Month month)
	{
		if ((static_cast<int>(month) == 12) || (static_cast<int>(month) == 1) || (static_cast<int>(month) == 2))
		{
			std::cout << "Winter" << std::endl;
		}
		if ((static_cast<int>(month) > 2) & (static_cast<int>(month) < 6))
		{
			std::cout << "Spring" << std::endl;
		}
		if ((static_cast<int>(month) > 5) & (static_cast<int>(month) < 9))
		{
			std::cout << "Summer" << std::endl;
		}
		if ((static_cast<int>(month) > 8) & (static_cast<int>(month) < 12))
		{
			std::cout << "Fall" << std::endl;
		}
	}

	/*
		Íàïèñàòü ïåðåãðóçêó äëÿ ñëåäóþùèõ ëîãè÷åñêèõ îïåðàòîðîâ
	*/
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

	/*
		Íàïèñàòü ïåðåãðóçêó äëÿ ñëåäóþùèõ àðèôìåòè÷åñêèõ îïåðàòîðîìâ
	*/
	Date operator + (const Date date, const TimeDelta delta)
	{
		Date daa;
		daa.day = date.day + delta.delta;
		return daa;
	}
	Date operator + (const TimeDelta delta, const Date date)
	{
		return (date + delta);
	}
	Date operator + (const TimeDelta delta, const TimeDelta date)
	{
		Date daa;
		daa.day = delta.delta + date.delta;
		return daa;
	}
	Date operator - (const Date date, const TimeDelta delta)
	{
		Date daa;
		daa.day = date.day - delta.delta;
		return daa;
	}
	Date operator - (const TimeDelta delta, const Date date)
	{
		Date daa;
		daa.day = delta.delta - date.day;
		return daa;
	}
	Date operator - (const TimeDelta delta, const TimeDelta date)
	{
		Date daa;
		daa.day = delta.delta - date.delta;
		return daa;
	}

	TimeDelta operator * (const TimeDelta delta, int multiplier)
	{
		TimeDelta	daa;
		daa.delta = delta.delta * multiplier;
		return daa;
	}
	TimeDelta operator * (int multiplier, const TimeDelta delta)
	{
		return delta * multiplier;
	}
	TimeDelta operator / (const TimeDelta delta, int multiplier)
	{
		TimeDelta daa;
		daa.delta = delta.delta / multiplier;
		return daa;
	}
	TimeDelta operator / (int multiplier, const TimeDelta delta)
	{
		TimeDelta daa;
		daa.delta = multiplier / delta.delta;
		return daa;
	}
}