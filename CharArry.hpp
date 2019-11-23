#pragma once
#pragma once

namespace dr
{
	using CharrArray=char*;
	char characterAt(CharrArray, int number);
	void append(CharrArray& str, char symbol);
	void concatenate(CharrArray& str1, CharrArray str2);
	CharrArray substring(CharrArray& str1, int start, int len);
	void replaceString(CharrArray& str, CharrArray target, CharrArray text);
}