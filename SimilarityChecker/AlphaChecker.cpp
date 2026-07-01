#include <iostream>
#include "AlphaChecker.h"

unsigned int AlphaChecker::getScore(const std::string& str1, const std::string& str2) const
{
	if (hasLowerCase(str1) || hasLowerCase(str2))
	{
		return MIN_SCORE;
	}

	return 0;
}

bool AlphaChecker::hasLowerCase(const std::string& str) const
{
	for (auto& ch : str)
	{
		if (std::islower(ch))
		{
			return true;
		}
	}
	return false;
}

unsigned int AlphaChecker::getSameCnt(const std::string& str1, const std::string& str2) const
{
	return 0;
}

unsigned int AlphaChecker::getTotalCnt(const std::string& str1, const std::string& str2) const
{
	return 0;
}
