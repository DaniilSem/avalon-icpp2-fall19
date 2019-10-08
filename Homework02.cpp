#include"Extention.hpp"
#include<iostream>
#include<string>
const int SIZE = 100;
struct Student
{
	int Id;
	int Grade;
	std::string Name;
};
void Fuller(Student data[], int size)
{
	bool isREpeat = true;
	for (int i = 0; i < size; ++i)
	{

		data[i].Grade = ext::GetRandomValue(0, 100);
		data[i].Id = ext::GetRandomValue(0, 1000);
		/*while (isREpeat)
{
	for (int j = 0; j < i - 1; ++j)
	{
		if ((data[j].Id == data[j].Id)&(i!=j))
		{
			data[i].Id = ext::GetRandomValue(0, 1000);
			break;
			isREpeat = true;
		}
		else isREpeat = false;

	}
}*/
		int length = ext::GetRandomValue(3, 6);
		char letter = ext::GetRandomValue('A', 'Z');
		data[i].Name += letter;
		for (int j = 1; j < length; ++j)
		{
			data[i].Name += ext::GetRandomValue('a', 'z');
		}

	}

}
void Sort(Student data[],std::string krit)
{
	bool chan=false;
	for (int i = 1; i < SIZE; ++i)
	{
		if (krit =="ID")
		{
			if (data[i].Id > data[i - 1].Id)
			{
				chan = true;
			}
		}
		if (krit == "Grade")
		{
			if (data[i].Grade > data[i - 1].Grade)
			{
				chan = true;
			}
		}
		if (krit == "Name")
		{
			if (data[i].Name > data[i - 1].Name)
			{
				chan = true;
			}
		}
		if (chan)
		{
			std::swap(data[i], data[i - 1]);
		}
		chan = false;
	}
}
int Marks(Student data[], int step)
{
	Sort(data, "Grade");
	int num = SIZE * (step / 100);
	return  data[num].Grade;
}
int main()
{
	std::string krit;
	std::cout << "Kriteriy" << std::endl;
	std::cin >> krit;
	Student data[100];
	Fuller(data, SIZE);
	Sort(data, krit);
	int step;
	std::cout << "Porog" << std::endl;
	std::cin >> step;
	std::cout<<" Marks > "<<Marks(data, step)<<std::endl;
}