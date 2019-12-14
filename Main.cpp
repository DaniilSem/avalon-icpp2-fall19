#include<fstream>
#include<iostream>
struct Triangle
{
	int a;
	int b;
	int c;
	double perim;
};
int findIndex( int left, int right, int value)
{
	std::ifstream Input("Triangle.bin", std::ifstream::in | std::ifstream::binary);
	int middle = (left + right) / 2; 
	Triangle num{};
	Input.seekg(middle*sizeof(num));
	Input.read(reinterpret_cast<char*>(&num), sizeof(Triangle));
	if (num.perim == value)
	{
		Input.close();
		return middle;
	}
	if (num.perim > value)
	{
		Input.close();
		return findIndex( left, middle - 1, value);
	}
	else
	{
		Input.close();
		return findIndex( middle + 1, right, value);
	}
}
int main()
{
	std::ifstream Input("Triangle.bin", std::ifstream::in | std::ifstream::binary);
	if (!Input.is_open())
	{
		std::cerr << "Error";
		return 1;
	}
	int perimetr;
	std::cin >> perimetr;
	int col;
	Input.seekg(0, std::ios_base::end);
	col = Input.tellg() / sizeof(Triangle);
	Input.close();
	findIndex(1,col,perimetr);
}