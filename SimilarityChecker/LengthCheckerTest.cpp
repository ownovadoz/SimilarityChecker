#include "gmock/gmock.h"
#include "LengthChecker.h"

class LengthCheckerTest : public ::testing::Test
{
public:
	void run(const unsigned int expected, const unsigned int actual)
	{
		EXPECT_EQ(expected, actual);
	}

	LengthChecker lengthChecker;
};

TEST_F(LengthCheckerTest, SameLengthString)
{
	run(60, lengthChecker.getSimilarityScore("test", "test"));
}

TEST_F(LengthCheckerTest, FirstStringIsLonger)
{
	run(40, lengthChecker.getSimilarityScore("test", "tes"));
}

TEST_F(LengthCheckerTest, SecondStringIsLonger)
{
	run(40, lengthChecker.getSimilarityScore("tes", "test"));
}

TEST_F(LengthCheckerTest, GapIsMoreThanShorterWithFirstStringIsLonger)
{
	run(0, lengthChecker.getSimilarityScore("test", "t"));
}

TEST_F(LengthCheckerTest, GapIsMoreThanShorterWithSecondStringIsLonger)
{
	run(0, lengthChecker.getSimilarityScore("t", "test"));
}