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