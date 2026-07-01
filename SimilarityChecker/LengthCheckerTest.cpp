#include "gmock/gmock.h"
#include "LengthChecker.h"

TEST(LengthChecker, SameLengthString)
{
	LengthChecker lengthChecker;
	unsigned int expected = 60;
	unsigned int actual = lengthChecker.getSimilarityScore("test", "test");
	EXPECT_EQ(expected, actual);
}

TEST(LengthChecker, FirstStringIsLongerByOne)
{
	LengthChecker lengthChecker;
	unsigned int expected = 40;
	unsigned int actual = lengthChecker.getSimilarityScore("test", "tes");
	EXPECT_EQ(expected, actual);
}

TEST(LengthChecker, SecondStringIsLongerByOne)
{
	LengthChecker lengthChecker;
	unsigned int expected = 40;
	unsigned int actual = lengthChecker.getSimilarityScore("tes", "test");
	EXPECT_EQ(expected, actual);
}

TEST(LengthChecker, FirstStringIsLongerByDouble)
{
	LengthChecker lengthChecker;
	unsigned int expected = 0;
	unsigned int actual = lengthChecker.getSimilarityScore("test", "te");
	EXPECT_EQ(expected, actual);
}

TEST(LengthChecker, SecondStringIsLongerByDouble)
{
	LengthChecker lengthChecker;
	unsigned int expected = 0;
	unsigned int actual = lengthChecker.getSimilarityScore("te", "test");
	EXPECT_EQ(expected, actual);
}

TEST(LengthChecker, FirstStringIsLongerByMoreThanDouble)
{
	LengthChecker lengthChecker;
	unsigned int expected = 0;
	unsigned int actual = lengthChecker.getSimilarityScore("testt", "te");
	EXPECT_EQ(expected, actual);
}

TEST(LengthChecker, SecondStringIsLongerByMoreThanDouble)
{
	LengthChecker lengthChecker;
	unsigned int expected = 0;
	unsigned int actual = lengthChecker.getSimilarityScore("te", "testt");
	EXPECT_EQ(expected, actual);
}