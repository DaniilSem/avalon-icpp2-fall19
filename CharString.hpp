#pragma once
namespace ds 
{
	struct CharString
	{
		char symbol;
		CharString* nextSymbol;
	};
	void append(CharString* ptr, char symbol);
	void print(CharString* ptr);
	char characterAt(CharString* ptr, int num);
	void removeChars(CharString* ptr,int tar,int dell);
}