#include<iostream>
#include<fstream>
#include<stdio.h>
#include<math.h>
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
std::ostream& operator << (std::ostream& out, Triangle triangle)
{
	out << triangle.len1 << "  "<<triangle.len2 << "  " << triangle.len3 << "  "<<triangle.perim << "  "<<
		triangle.squaere << "  "<<triangle.fatofline << "  "<<triangle.color ;
	return out;
}
std::istream& operator >> (std::istream& in, Triangle& triangle)
{

	in >> triangle.color>> triangle.len1>> triangle.len2 >> triangle.len3 >> triangle.fatofline;
	return in;
}
float Square(Triangle tri)
{
	float p = (tri.len1 + tri.len2 + tri.len3) / 2;
	return sqrt(p*(p- tri.len1)*(p- tri.len2)*(p- tri.len3));
}
int Perimetr(Triangle tri)
{
	return tri.len1 + tri.len2 + tri.len3;
}
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
	Triangle data[100]{};
	for (int i = 0; i < 100; ++i)
	{
		Input >> data[i];
	}

	for (int i = 0; i < 100; ++i)
	{
		data[i].squaere = Square(data[i]);
		data[i].perim = Perimetr(data[i]);
		Output<<data[i]<<std::endl;
	}
}
