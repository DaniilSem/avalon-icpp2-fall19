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
 void Fuller(Student data[],int size)
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
		char letter =ext:: GetRandomValue('A', 'Z');
		data[i].Name += letter;
		for (int j = 1; j < length; ++j)
			{
				data[i].Name += ext::GetRandomValue('a', 'z');
			}
		
	}

}
int main()
{
	std::string krit;
	std::cout << "Введите критерий сортировки"<<std::endl;
	std::cin >> krit;
	Student data[100];
	Fuller(data, SIZE);
}
