#include "gmock/gmock.h"
#include "AlphaChecker.h"

TEST(AlphaChecker, HasLowerCase)
{
	AlphaChecker checker;

	EXPECT_EQ(0, checker.getScore("Hello", "World"));
}