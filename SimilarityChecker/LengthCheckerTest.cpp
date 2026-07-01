#include "gmock/gmock.h"
#include "LengthChecker.h"

TEST(LengthChecker, SameLengthString)
{
	LengthChecker lengthChecker;
	int expected = 60;
	int actual = lengthChecker.getSimilarityScore("test", "test");
	EXPECT_EQ(expected, actual);
}