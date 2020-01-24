// SquishedMorse.cpp : Defines the entry point for the application.

// std
#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
// boost
#include <boost/algorithm/string.hpp>
// local
#include "MorseCoder.h"

int main()
{
	std::ios::sync_with_stdio(false);

	MorseCoder morse{};

	//const std::string encoded{ morse.encode("abcdefghijklmnopqrstuvwxyz") };
	//std::cout << encoded << '\n';
	//std::cout << morse.decode(encoded) << '\n';
	//std::cout << morse.encode("sos", true) << '\n';

	//std::ifstream wordlistFile{ "enable1.txt" };

	//std::string wordlist{ std::istreambuf_iterator<char>(wordlistFile), std::istreambuf_iterator<char>() };

	std::cout << '"' << morse.encode("a") << "\"\n";

	return 0;
}
