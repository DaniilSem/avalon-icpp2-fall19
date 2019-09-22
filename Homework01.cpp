#include<iostream>
bool isbn13(long long int num)
{
	bool res;
	int cont = num % 10;
	int sum = 0, n;
	num = num / 10;
	n = 1;
	for (int i = 0; i < 12; ++i)
	{
		if (n < 0)
		{
			sum = sum + (num % 10) * 1;
			n = n * (-1);
			num = num / 10;
		}
		else
		{
			sum = sum + (num % 10) * 3;
			n = n * (-1);
			num = num / 10;
		}
	}
	res = (10 - (sum % 10) == cont);
	return res;
}
bool isbn10(long long num)
{
	int sum = 0;
	bool res;
	int cont = num % 10;
	num = num / 10;
	for (int i = 2; i < 11; ++i)
	{
		sum = sum + (num % 10)*i;
		num = num / 10;
	}
	int n;
	n = sum % 11;
	n = 11 - n;
	res = ((11-(sum%11))==cont);
	return res;
}
//int main()
//{
//	int col;
//	long long		num;
//	std::cout << "Col of numbers" << std::endl;
//	std::cin >> col;
//	for (int i = 0; i < col; ++i)
//	{
//		std::cout << "Number" << std::endl;
//		std::cin >> num;
//		if (isbn13(num))
//		{
//			std::cout << "valid" << std::endl;
//		}
//		else
//		{
//			std::cout << "invalid" << std::endl;
//		}
//	}
//}
int main()
{
	long long int num = 0;
	std::cout << "idbn13 or isbn10" << std::endl;
	int chek;
	std::cin >> chek;
	std::cout << "Number" << std::endl;
	std::cin >> num;
	if (chek == 13)
	{
		if (isbn13(num))
		{
			std::cout << "valid" << std::endl;
		}
		else
		{
			std::cout << "invalid" << std::endl;
		}
	}
	else
	{
		if (isbn10(num))
		{
			std::cout << "valid" << std::endl;
		}
		else
		{
			std::cout << "invalid" << std::endl;
		}
	}
}