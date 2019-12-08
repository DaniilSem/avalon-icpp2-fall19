#include<fstream>
#include<iostream>
struct Triangle
{
	int a;
	int b;
	int c;
	double perim;
};
int findIndex(int data[], int left, int right, int value)
{
	int middle = (left + right) / 2;
	if (data[middle] == value)
	{
		return middle;
	}
	if (data[middle] > value)
	{
		return findIndex(data, left, middle - 1, value);
	}
	else
	{
		return findIndex(data, middle + 1, right, value);
	}
}

int findIndex(int data[], int size, int value)
{
	return findIndex(data, 0, size - 1, value);
}
int main()
{
	std::ifstream Input("Triangle.bin",std::ifstream::in|std::ifstream::binary);
	if (!Input.is_open())
	{
		std::cerr << "Error";
		return 1;
	}
	int perimetr;
	std::cin >> perimetr;
	int size;
	Input.seekg(0, std::ios_base::end);
	size = Input.tellg()/sizeof(Triangle);
}