#include<iostream>
#include"Biblio.hpp"
using namespace std;
int main()
{
	std::cout << "Hello, you are using 'Biblio'\nPress:\n1 - to add book\n"
	<<"2 - to redact book\n3 - to find book\n4 - to watch all books\n5 - to watch statistic\n";
	int choise;
	std::cin >> choise;
	switch (choise)
	{
	case 1:
		try
		{
			dr::adder();
		}
		catch (const std::exception&exp)
		{
			cout <<exp.what()<< endl;
		}
		break;
	case 2:
		try
		{
			dr::redactor();
		}
		catch (const std::exception& exp)
		{
			cout << exp.what() << endl;
		}
		break;
	case 3:
		try
		{
			dr::finder();
		}
		catch (const std::exception& exp)
		{
			cout << exp.what() << endl;
		}
		break;
	case 4:
		try
		{
			dr::lister();
		}
		catch (const std::exception& exp)
		{
			cout << exp.what() << endl;
		}
		break;
	case 5:
		try
	{
		dr::stat();
	}
		   catch (const std::exception& exp)
		   {
			   cout << exp.what() << endl;
		   }
		break;
	default:
		std::cerr << "Unknown operation";
		break;
	}
}