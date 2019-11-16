#include<iostream>
using namespace std;
using CharrArray=char*;
#include"CharArry.hpp"
int main()
{
	CharrArray str = new char[8]{ "abcdefg" };
	CharrArray str2 = new char[7]{ " world" };
	char result =dr:: characterAt(str, 1);//h
	char result2 = dr::characterAt(str, 3);//l
	dr::concatenate(str,str2);//str-> "hello world"
	std::cout << dr::substring(str, 3, 4);

}