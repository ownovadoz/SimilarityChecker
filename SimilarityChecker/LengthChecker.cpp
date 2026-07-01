#include <cmath>
#include "LengthChecker.h"

unsigned int LengthChecker::getSimilarityScore(const string& str1, const string& str2) const noexcept
{
	const string& longer = getLonger(str1, str2);
	const string& shorter = getShorter(str1, str2);

	if (hasSameLength(longer, shorter))
		return MAX_SCORE;

	if (isGapDoubleThanShorter(longer, shorter))
		return MIN_SCORE;

	double score = calcScore(longer, shorter);

	if (score < 0)
		return MIN_SCORE;

	return static_cast<unsigned int>(score);
}

double LengthChecker::calcScore(const std::string& longer, const std::string& shorter) const
{
	return (1.0 - (static_cast<double>(getLengthDifference(longer, shorter)) / shorter.length())) * static_cast<double>(MAX_SCORE);
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
	return longer.length() == shorter.length();
}

bool LengthChecker::isGapDoubleThanShorter(const string& longer, const string& shorter) const
{
	return getLengthDifference(longer, shorter) >= (shorter.length() * 2);
}

unsigned int LengthChecker::getLengthDifference(const string& longer, const string& shorter) const
{
	return longer.length() - shorter.length();
}