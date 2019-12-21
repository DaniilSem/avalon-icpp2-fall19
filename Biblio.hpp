#pragma once
namespace dr
{
	struct Book
	{
		static const int BUFFER_SIZE = 20;
		int Id;
		char Title[BUFFER_SIZE];
		char Author[BUFFER_SIZE];
		float Price;
		int Quantity;
	};
	void adder();
	void redactor();
	void finder();
	void lister();
	void stat();
}