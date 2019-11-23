#include"CharArry.hpp"
#include<cmath>
namespace dr
{
	int counter(CharrArray str)
	{
		int size = 0;
		while (str[size] != '\0')
		{
			++size;
		}
		return size;
	}
	char characterAt(CharrArray str, int number)
	{
		return str[number - 1];
	}
	void append(CharrArray& str, char symbol)
	{
		int size = counter(str);
		CharrArray newstr = new char[size + 2];
		for (int i = 0; i < size; ++i)
		{
			newstr[i] = str[i];
		}
		newstr[size + 1] = symbol;
		newstr[size + 2] = '\0';
		delete[]str;
		str = newstr;

	}
	void concatenate(CharrArray& str1, CharrArray str2)
	{
		int lenght = counter(str1);
		int lenght2 = counter(str2);
		CharrArray result = new char[lenght + lenght2 + 1];
		for (int i = 0; i < lenght; ++i)
		{
			result[i] = str1[i];
		}
		for (int i = 0; i < lenght2; ++i)
		{
			result[lenght + i] = str2[i];
		}
		result[lenght + lenght2 + 1] = '\0';
		delete[]str1;
		str1 = result;
	}
	CharrArray substring(CharrArray& str1, int start, int len)
	{
		CharrArray result = new char[len + 1];
		for (int i = 0; i < len; ++i)
		{
			result[i] = str1[start + i - 1];
		}
		result[len] = '\0';
		return result;
	}
	void replaceString(CharrArray& str, CharrArray target, CharrArray text)
	{
		int size = counter(str);
		int sizeres = size;
		for (int i = 0; i < size; ++i)
		{
			bool fl = false;
			if (str[i] = target[0])
			{
				fl = true;
				for (int j = 1; j < counter(target); ++j)
				{
					if (str[i + j] != target[j]) { fl = false; }
				}
			}
			if (fl == true)
			{ 
				sizeres += std::abs(counter(target) - counter(text));
			
			}
		}
		sizeres += size;
		CharrArray result = new char[sizeres + 1];
		result[sizeres] = '\0';
		int n = 0;
		for (int i = 0; i < size; ++i)
		{
			bool fl = false;
			if (str[i] = target[0])
			{
				fl = true;
				for (int j = 1; j < counter(target); ++j)
				{
					if (str[i + j] != target[j]) { fl = false; }
				}
			}
			if (fl == true) 
			{
				for (int j = 1; j < counter(text); ++j)
				{
					result[n] = text[j];
					n++;
				}
				i += counter(target);
			}
			else
			{
				result[n] = str[i];
				n++;

			}
		}
	}
}