#include<iostream>
bool isbn13(long long int num)
{
	bool res;
	int cont = num % 10;
	 int sum=0, n;
	num = num % 10;
	n = 1;
	for (int i = 0; i < 12; ++i)
	{
		if (n > 0)
		{
			sum = sum + (num % 10) * 1;
			n = n * (-1);
			num = num % 10;
		}
		else
		{
			sum = sum + (num % 10) * 3;
			n = n * (-1);
			num = num % 10;
		}
	} 
	res = (10 - (sum % 10) == cont);
	return res;
}
int main()
{
	int col;
long long		num;
	std::cout << "Col of numbers" << std::endl;
	std::cin >> col;
	for (int i = 0; i < col; ++i)
	{
		std::cout << "Number" << std::endl;
		std::cin >> num ;
		if (isbn13(num))
		{
			std::cout << "valid" << std::endl;
		}
		else
		{
			std::cout << "invalid" << std::endl;
		}
	}
}
