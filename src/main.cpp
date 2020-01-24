// SquishedMorse.cpp : Defines the entry point for the application.

// std
#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <sstream>
#include <random>
// local
#include "MorseCoder.h"
#include "LetterChecker.h"

int main()
{
	std::ios::sync_with_stdio(false);

	std::string wordlist;
	{
		std::ifstream wordlistFile{ "enable1.txt" };
		wordlist = std::string{ std::istreambuf_iterator<char>(wordlistFile), std::istreambuf_iterator<char>() };
	}

	MorseCoder coder{};

	std::vector<std::string> morseAlphabet{};
	for (char i = 'a'; i <= 'z'; ++i)
	{
		morseAlphabet.push_back(coder.encode(std::string(1, i)));
	}

	std::string decoded{};
	std::vector<std::string> morseLetters{ morseAlphabet };
	std::string encoded{ "..-...-..-....--.---.---.---..-..--....-.....-..-.--.-.-.--.-..--.--..--.----..-.." };
	size_t pos = 0;
	std::random_device seed;
	std::default_random_engine shuffleEngine{ seed() };
	while (morseLetters.size() > 0)
	{
		bool deadEnd = true;
		for (int i = 0; i < morseLetters.size(); ++i)
		{
			const auto element{ morseLetters[i] };
			if (element == encoded.substr(pos, element.length()))
			{
				decoded += coder.decode(element);
				pos += element.length();
				morseLetters.erase(morseLetters.begin() + i);
				deadEnd = false;
			}
		}
		if (deadEnd)
		{
			deadEnd = false;
			decoded = "";
			pos = 0;
			morseLetters = morseAlphabet;
			std::shuffle(morseLetters.begin(), morseLetters.end(), shuffleEngine);
		}
	}

	std::cout << "Source:\n" << encoded << '\n';
	std::cout << "Decoded:\n" << decoded
		<< "\nValid: " << std::boolalpha << letters::checkAlpha(decoded) << '\n';
	std::cout << "Decoding's Encoding:\n" << coder.encode(decoded, true) << '\n';

	return 0;
}
