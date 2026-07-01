#include "gmock/gmock.h"
#include "LengthChecker.h"

TEST(LengthChecker, SameLengthString)
{
	LengthChecker lengthChecker;
	int expected = 60;
	int actual = lengthChecker.getSimilarityScore("test", "test");
	EXPECT_EQ(expected, actual);
}

TEST(LengthChecker, FirstStringIsLongerByOne)
{
	LengthChecker lengthChecker;
	int expected = 40;
	int actual = lengthChecker.getSimilarityScore("test", "tes");
	EXPECT_EQ(expected, actual);
}