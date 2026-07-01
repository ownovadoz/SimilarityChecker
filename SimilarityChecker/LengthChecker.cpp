#include <cmath>
#include "LengthChecker.h"

unsigned int LengthChecker::getSimilarityScore(const string& str1, const string& str2) const noexcept
{
	const string& longer = getLonger(str1, str2);
	const string& shorter = getShorter(str1, str2);

	if (hasSameLength(longer, shorter))
		return MAX_SCORE;

	double score = (1.0 - (static_cast<double>(getLengthDifference(longer, shorter)) / shorter.length())) * 60.0;

	return static_cast<unsigned int>(score);
}

const string& LengthChecker::getLonger(const string& str1, const string& str2) const
{
	return (str1.length() > str2.length()) ? str1 : str2;
}

const string& LengthChecker::getShorter(const string& str1, const string& str2) const
{
	return (str1.length() > str2.length()) ? str2 : str1;
}

bool LengthChecker::hasSameLength(const string& longer, const string& shorter) const
{
	return longer.length() - shorter.length() == 0;
}

unsigned int LengthChecker::getLengthDifference(const string& longer, const string& shorter) const
{
	return longer.length() - shorter.length();
}