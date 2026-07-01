#include <cmath>
#include "LengthChecker.h"

int LengthChecker::getSimilarityScore(const string& str1, const string& str2) const noexcept
{
	const string& longer = (str1.length() > str2.length()) ? str1 : str2;
	const string& shorter = (str1.length() > str2.length()) ? str2 : str1;

	if (longer.length() - shorter.length() == 0)
		return 60;

	int lengthDifference = longer.length() - shorter.length();
	double score = (1.0 - (static_cast<double>(lengthDifference) / shorter.length())) * 60.0;

	return static_cast<int>(score);
}
