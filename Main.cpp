#include<iostream>
using namespace std;
using CharrArray=char*;
#include"CharArry.hpp"
int main()
{
	CharrArray str = new char[9]{ "abcdabee" };
	CharrArray str2 = new char[3]{ "ab" };
	CharrArray str3 = new char[4] { "xyz" };
	//char result = dr::characterAt(str, 1);//h
	//char result2 = dr::characterAt(str, 3);//l
	//dr::concatenate(str, str2);//str-> "hello world"
dr::replaceString(str,str2,str3);
std::cout << str;
}