#include"Agent.hpp"
#include<iostream>
static const int LEN = 10;
int main()
{
	DS::Agent data[LEN];
	DS::Fuller(data, LEN);
	std::cout << DS::HighMed(data, LEN);
}