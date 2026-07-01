#include <cmath>

#include "LengthChecker.h"

unsigned int LengthChecker::getSimilarityScore(const string& str1, const string& str2) const noexcept
{
	const int longer = static_cast<int>(std::max(str1.length(), str2.length()));
	const int shorter = static_cast<int>(std::min(str1.length(), str2.length()));

	if (hasSameLength(longer, shorter))
		return MAX_SCORE;

	if (isGapDoubleThanShorter(longer, shorter))
		return MIN_SCORE;

	double score = calcScore(longer, shorter);

	if (isNegative(score))
		return MIN_SCORE;

	return static_cast<unsigned int>(score);
}

bool LengthChecker::hasSameLength(const int longer, const int shorter) const
{
	return (longer == shorter);
}

bool LengthChecker::isGapDoubleThanShorter(const int longer, const int shorter) const
{
	return getDiff(longer, shorter) >= (shorter * 2);
}

int LengthChecker::getDiff(const int longer, const int shorter) const
{
	return longer - shorter;
}

double LengthChecker::calcScore(const int longer, const int shorter) const
{
	return (1.0 - (static_cast<double>(getDiff(longer, shorter)) / shorter)) * static_cast<double>(MAX_SCORE);
}

bool LengthChecker::isNegative(const double score) const
{
	return (score < 0);
}