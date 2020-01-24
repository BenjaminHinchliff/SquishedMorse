#ifndef MORSEMAP_H
#define MORSEMAP_H

#include <string>
#include <unordered_map>
#include <iterator>
#include <algorithm>
#include <sstream>

#include <boost/algorithm/string.hpp>

class MorseCoder
{
public:
	MorseCoder();
	std::string encode(std::string text, bool smooshed = false);
	std::string decode(std::string morse);
	std::unordered_map<char, std::string> toMorse;
	std::unordered_map<std::string, char> fromMorse;
};

#endif // !MORSEMAP_H