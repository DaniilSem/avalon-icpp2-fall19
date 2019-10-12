#pragma once
#pragma once

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
		���������� ��������� ����
		https://ru.wikipedia.org/wiki/%D0%AE%D0%BB%D0%B8%D0%B0%D0%BD%D1%81%D0%BA%D0%B0%D1%8F_%D0%B4%D0%B0%D1%82%D0%B0
		������ "���������� ������ ���������� ��� (JDN) �� ���� �������������� ���������"
		�������� ������					��������� ���������
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
		������������ ���������� ���� ����� ����� ������.
		��� ����������� ����������� CountJND
	*/
	TimeDelta countDistance(Date from, Date to)
	{
		TimeDelta delta;
		delta.delta = countJND(to).delta - countJND(from).delta;
		return delta;
	}

	/*
		������� � �������
	*/
	void print(Date data, DateFormat format = DateFormat::MonthAsInt)
	{

	}
	void print(Month month, DateFormat format = DateFormat::MonthAsInt);
	void print(TimeDelta delta);

	/*
		���������� ����� (����, �����, ����, �����) ������������ ����
	*/
	Season getSeason(Date date);
	Season getSeason(Month month);

	/*
		�������� ���������� ��� ��������� ���������� ����������
	*/
	bool operator == (const Date lhs, const Date rhs)
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
		�������� ���������� ��� ��������� �������������� �����������
	*/
	Date operator + (const Date date, const TimeDelta delta);
	Date operator + (const TimeDelta delta, const Date date);
	Date operator + (const TimeDelta delta, const TimeDelta date);
	Date operator - (const Date date, const TimeDelta delta);
	Date operator - (const TimeDelta delta, const Date date);
	Date operator - (const TimeDelta delta, const TimeDelta date);

	TimeDelta operator * (const TimeDelta delta, int multiplier);
	TimeDelta operator * (int multiplier, const TimeDelta delta);
	TimeDelta operator / (const TimeDelta delta, int multiplier);
	TimeDelta operator / (int multiplier, const TimeDelta delta);
}