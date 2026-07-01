#include "gmock/gmock.h"
#include "AlphaChecker.h"

TEST(AlphaChecker, HasLowerCase)
{
	AlphaChecker checker;

	EXPECT_EQ(0, checker.getScore("Hello", "World"));
}

TEST(AlphaChecker, ASDandDSA)
{
	AlphaChecker checker;

	EXPECT_EQ(40, checker.getScore("ASD", "DSA"));
}

TEST(AlphaChecker, AandBB)
{
	AlphaChecker checker;

	EXPECT_EQ(0, checker.getScore("A", "BB"));
}

TEST(AlphaChecker, AAABBandBA)
{
	AlphaChecker checker;

	EXPECT_EQ(40, checker.getScore("AAABB", "BA"));
}

TEST(AlphaChecker, AAandAAE)
{
	AlphaChecker checker;

	EXPECT_EQ(20, checker.getScore("AA", "AAE"));
}

TEST(AlphaChecker, EmptyStrings)
{
	AlphaChecker checker;

	EXPECT_EQ(0, checker.getScore("", ""));
}