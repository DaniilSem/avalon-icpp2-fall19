#pragma once

#pragma once
#include <random>

namespace ext
{
	/** Ôóíêöè GetRandomValueñëó÷àéíî çíà÷åíèå òèïà int èç óêàçàííîãî èíòåðâàëà.
	*
	* @param min íèæíÿÿ ãðàíèöà èíòåðâàëà (âêëþ÷èòåëüíî)
	* @param max âåðõíÿÿ ãðàíèöà èíòåðâàëà (âêëþ÷èòåëüíî)
	* @param isDebugMode åñëè true òî êàæäûé ðàç áóäåò ãåíåðèðîâàòüñÿ îäèíàêîâà ïîñëåäîâàëüíîñòü äëÿ óäîáñòâà ïðè îòëàäêå
	* @return ñëó÷àéíîå çíà÷åíèå òèïà int èç óêàçàííî î èíòåðâàëà
	*/
	int GetRandomValue(int min, int max, bool isDebugMode = false)
	{
		static auto randomEngine = [isDebugMode]() { return isDebugMode ? std::mt19937{} : std::mt19937(std::random_device{}()); }();
		auto distribution = std::uniform_int_distribution<int>(min, max);
		return distribution(randomEngine);
	}
}