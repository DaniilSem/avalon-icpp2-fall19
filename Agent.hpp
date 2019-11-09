#pragma once
#pragma once
namespace DS
{
	struct Agent
	{
		static const int SIZE = 12;
		int	data[SIZE];
		int LenWork;
	};
	void Fuller(Agent data[], int size);
	int HighMed(Agent data[], int size);
}