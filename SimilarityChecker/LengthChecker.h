#pragma once

#include <string>

using std::string;

class LengthChecker
{
public:
	static constexpr int MAX_SCORE = 60;

	unsigned int getSimilarityScore(const string& str1, const string& str2) const noexcept;

private:
	const string& getShorter(const string& str1, const string& str2) const;
	const string& getLonger(const string& str1, const string& str2) const;
	bool hasSameLength(const string& longer, const string& shorter) const;
	unsigned int getLengthDifference(const string& longer, const string& shorter) const;
};