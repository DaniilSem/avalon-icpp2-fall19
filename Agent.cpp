#include"Agent.hpp"
#include"Extention.hpp"
namespace DS
{
	int WorkLen()
	{
		int len;
		len = ext::GetRandomValue(1, 12);
		return len;
	}
	void Fuller(Agent data[], int size)
	{
		int lenWork = WorkLen();
		for (int i = 0; i < size; ++i)
		{
			data[i].LenWork = lenWork;
			for (int j = 1; j < lenWork; ++j)
			{
				data[i].data[j] = ext::GetRandomValue(1000, 100000);
			}
			for (int j = lenWork + 1; j < Agent::SIZE; ++j)
			{
				data[i].data[j] = -1;
			}
		}
	}
	int HighMed(Agent data[], int size)
	{
		int sum, med;
		int maxnum=0;
		int max = 0;
		for (int i = 0; i < size; ++i)
		{
			sum = 0;
			for (int j = 0; j < data[i].LenWork; ++j)
			{
				sum += data[i].data[j];
			}
			med = sum / data[i].LenWork;
			if (med > max) {
				max = med;
				maxnum = i;
			}
		}
		return maxnum;
	}
	
}