#include "LetterChecker.h"

namespace letters
{
	bool checkAlpha(std::string toCheck)
	{
		std::unordered_map<char, bool> exists{};
		for (char letter : toCheck)
			exists[letter] = true;
		for (char i = 'a'; i <= 'z'; ++i)
		{
			if (!exists[i])
				return false;
		}
		return true;
	}
}