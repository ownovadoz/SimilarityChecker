#include "gmock/gmock.h"
#include "LengthChecker.h"

TEST(LengthChecker, SameLengthString)
{
	LengthChecker lengthChecker;
	unsigned int expected = 60;
	unsigned int actual = lengthChecker.getSimilarityScore("test", "test");
	EXPECT_EQ(expected, actual);
}

TEST(LengthChecker, FirstStringIsLonger)
{
	LengthChecker lengthChecker;
	unsigned int expected = 40;
	unsigned int actual = lengthChecker.getSimilarityScore("test", "tes");
	EXPECT_EQ(expected, actual);
}

TEST(LengthChecker, SecondStringIsLonger)
{
	LengthChecker lengthChecker;
	unsigned int expected = 40;
	unsigned int actual = lengthChecker.getSimilarityScore("tes", "test");
	EXPECT_EQ(expected, actual);
}

TEST(LengthChecker, GapIsMoreThanShorterWithFirstStringIsLonger)
{
	LengthChecker lengthChecker;
	unsigned int expected = 0;
	unsigned int actual = lengthChecker.getSimilarityScore("test", "t");
	EXPECT_EQ(expected, actual);
}

TEST(LengthChecker, GapIsMoreThanShorterWithSecondStringIsLonger)
{
	LengthChecker lengthChecker;
	unsigned int expected = 0;
	unsigned int actual = lengthChecker.getSimilarityScore("t", "test");
	EXPECT_EQ(expected, actual);
}