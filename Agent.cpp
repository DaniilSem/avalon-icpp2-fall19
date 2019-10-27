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
	Agent Fuller(Agent data[], int size)
	{
		int lenWork = WorkLen();
		for (int i = 0; i < size; ++i)
		{
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
}