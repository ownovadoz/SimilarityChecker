#pragma once

#include <string>

using std::string;

class LengthChecker
{
public:
	static constexpr int MAX_SCORE = 60;
	static constexpr int MIN_SCORE = 0;

	unsigned int getSimilarityScore(const string& str1, const string& str2) const noexcept;

private:
	bool hasSameLength(const int longer, const int shorter) const;
	bool isGapDoubleThanShorter(const int longer, const int shorter) const;
	int getDiff(const int longer, const int shorter) const;
	double calcScore(const int longer, int shorter) const;
	bool isNegative(const double score) const;
};