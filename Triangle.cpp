#include<iostream>
#include<fstream>
#include<stdio.h>
struct Triangle
{
	int len1;
	int len2;
	int len3;
	bool zaliv;
	std::string color;
	float squaere;
	int perim;
	float fatofline;
};
int main()
{
	 std::ifstream Input;
	 std::ofstream Output;
	 Input.open("Triangle.txt");
	 Output.open("Triangle_out.txt");
	 if (!(Input.is_open() && Output.is_open()))
	 {
		 std::cerr << "Error" << std::endl;
		 return 1;
	 }
	 for (int i = 0; i < 100; ++i)
	 {
		 Input>>
	 }
}