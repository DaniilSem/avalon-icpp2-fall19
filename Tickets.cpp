#include<fstream>
#include<iostream>
int Sum(int num)
{
	int sum;
	sum = num % 10 + num / 10 % 10 + num / 100 % 10;
	return sum;
}
/*int main()
{
	std::ifstream Input;
	std::ofstream outputunluc;
	std::ofstream outputluc;
	Input.open("tickets.txt");
	if (!Input.is_open())
	{
		std::cerr << "Not open";
		return 1;
	}
	int num;
	outputluc.open("luck.txt", std::iostream::ate);
	outputunluc.open("unluck.txt", std::iostream::ate);
	for(int i = 0; i < 100; ++i)
	{
		Input >> num;
		if ((Sum(num / 1000)) ==Sum( (num % 1000)))
		{
			outputluc << num<<std::endl;
		}
		else
		{
			outputunluc << num << std::endl;
		}
	}
}*/