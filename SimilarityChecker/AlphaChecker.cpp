#include "AlphaChecker.h"

unsigned int AlphaChecker::getScore(const std::string& str1, const std::string& str2) const
{
	if (hasLowerCase(str1) || hasLowerCase(str2))
	{
		return MIN_SCORE;
	}

	int sameCnt = getSameCnt(str1, str2);
	int totalCnt = getTotalCnt(str1, str2);

	return static_cast<double>(sameCnt) / totalCnt * 40;
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
	std::unordered_set<char> set;

	auto str1Set = getAlphaSet(str1);
	auto str2Set = getAlphaSet(str2);

	for (auto& ch : str1Set)
	{
		if (str2Set.find(ch) != str2Set.end())
		{
			set.insert(ch);
		}
	}

	return set.size();
}

unsigned int AlphaChecker::getTotalCnt(const std::string& str1, const std::string& str2) const
{
	auto str1Set = getAlphaSet(str1);
	auto str2Set = getAlphaSet(str2);

	return str1Set.size() + str2Set.size() - getSameCnt(str1, str2);
}

std::unordered_set<char> AlphaChecker::getAlphaSet(const std::string& str) const
{
	std::unordered_set<char> set;

	for (auto& ch : str)
	{
		set.insert(ch);
	}

	return set;
}
