#include "AlphaChecker.h"

unsigned int AlphaChecker::getScore(const std::string& str1, const std::string& str2) const
{
	if (hasLowerCase(str1) || hasLowerCase(str2))
		return MIN_SCORE;

	auto set1 = getAlphaSet(str1);
	auto set2 = getAlphaSet(str2);

	int sameCnt = getSameCnt(set1, set2);
	int totalCnt = getTotalCnt(set1, set2, sameCnt);

	if (totalCnt == 0)
		return MIN_SCORE;

	return calcScore(sameCnt, totalCnt);
}

bool AlphaChecker::hasLowerCase(const std::string& str) const
{
	for (unsigned char uch : str)
	{		
		if (std::islower(uch))
		{
			return true;
		}
	}
	return false;
}

unsigned int AlphaChecker::getSameCnt(const std::set<unsigned char>& set1, const std::set<unsigned char>& set2) const
{
	const auto& small = (set1.size() < set2.size() ? set1 : set2);
	const auto& large = (set1.size() < set2.size() ? set2 : set1);

	unsigned int cnt = 0;
	
	for (auto& ch : small)
	{
		if (large.find(ch) != large.end())
		{
			++cnt;
		}
	}

	return cnt;
}

unsigned int AlphaChecker::getTotalCnt(const std::set<unsigned char>& set1, const std::set<unsigned char>& set2, const int sameCnt) const
{
	return static_cast<unsigned int>(set1.size()) + static_cast<unsigned int>(set2.size()) - sameCnt;
}

std::set<unsigned char> AlphaChecker::getAlphaSet(const std::string& str) const
{
	std::set<unsigned char> set_;

	for (unsigned char uch : str)
	{
		set_.insert(uch);
	}

	return set_;
}

unsigned int AlphaChecker::calcScore(int sameCnt, int totalCnt) const
{
	return static_cast<unsigned int>(static_cast<double>(sameCnt) / totalCnt * MAX_SCORE);
}