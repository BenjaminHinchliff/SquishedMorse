#include <gtest/gtest.h>
#include "MorseCoder.h"

#include <string>
#include <sstream>
#include <iterator>
#include <algorithm>

class MorseCoderTest : public ::testing::Test
{
protected:
	MorseCoder coder{};
	std::string alphabetSource{ "abcdefghijklmnopqrstuvwxyz" };
	std::string alphabetEncoding{ ".- -... -.-. -.. . ..-. --. .... .. .--- -.- .-.. -- -. --- .--. --.- .-. ... - ..- ...- .-- -..- -.-- --.." };
	std::istringstream encodedBuf{ alphabetEncoding };
};

TEST_F(MorseCoderTest, IsEncodingWorking)
{
	int i = 0;
	for (
		std::istream_iterator<std::string> code{ encodedBuf };
		code != std::istream_iterator<std::string>();
		++code, ++i
		)
	{
		ASSERT_EQ(coder.encode(std::string(1, alphabetSource[i])), *code);
	}
}

TEST_F(MorseCoderTest, IsSquishedEncodingWorking)
{
	ASSERT_EQ(coder.encode("sos", true), "...---...");
}

TEST_F(MorseCoderTest, IsDecodingWorking)
{
	int i = 0;
	for (
		std::istream_iterator<std::string> code{ encodedBuf };
		code != std::istream_iterator<std::string>();
		++code, ++i
		)
	{
		ASSERT_EQ(coder.decode(*code), std::string(1, alphabetSource[i]));
	}
}