#include <cmath>
#include "LengthChecker.h"

int LengthChecker::getSimilarityScore(const string& str1, const string& str2) const noexcept
{
	if (str1.length() - str2.length() == 0)
		return 60;
	return 0;
}
