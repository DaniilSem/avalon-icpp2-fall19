#include<iostream>
#include<fstream>
#include<stdio.h>
struct Athlet
{
	int num;
	float res=0;
	std::string name;
	std::string SName;
};
std::istream& operator >> (std::istream& in, Athlet& ath)
{
	in >> ath.num >> ath.name >> ath.SName;
	return in;
}

std::ostream& operator << (std::ostream& out, Athlet ath)
{
	out << ath.name<<"  " << ath.SName<<"  " << ath.res;
	return out;
}

int main()
{
	std::ifstream InputAthl;
	std::ifstream InputRes;
	InputAthl.open("Athlets.txt");
	InputRes.open("Results.txt");
	if (!(InputAthl.is_open() && InputRes.is_open()))
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}
	Athlet data[20]{};
	for (int i = 0;i<20;++i)
	{
		InputAthl >> data[i];
	}
	int num,res;
	for(int i = 0; i < 60; ++i)
	{
		InputRes >> num;
		InputRes >> res;
		if (res > data[num].res) { data[num].res = res;}
	}
	Athlet winner{};
	for (int i = 0; i < 20; ++i)
	{
		if(data[i].res>winner.res)
		{
			winner.name = data[i].name;
			winner.SName = data[i].SName;
			winner.res = data[i].res;
		}
	}
	std::cout << winner;
}