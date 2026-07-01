#pragma once

#include <string>
#include <unordered_set>

class AlphaChecker
{
	static constexpr unsigned int MAX_SCORE = 40;
	static constexpr unsigned int MIN_SCORE = 0;

public:
	unsigned int getScore(const std::string& str1, const std::string& str2) const;

private:
	bool hasLowerCase(const std::string& str) const;
	unsigned int getSameCnt(const std::string& str1, const std::string& str2) const;
	unsigned int getTotalCnt(const std::string& str1, const std::string& str2) const;
	std::unordered_set<char> getAlphaSet(const std::string& str) const;
};