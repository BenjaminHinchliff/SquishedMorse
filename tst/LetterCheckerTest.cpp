#include <gtest/gtest.h>
#include "LetterChecker.h"

TEST(LetterChecker, IsCheckingAlpha)
{
	ASSERT_EQ(letters::checkAlpha("abcdefghijklmnopqrstuvwxyz"), true);
	ASSERT_EQ(letters::checkAlpha("abcdefghijklmnopqrstuvwxy"), false);
}