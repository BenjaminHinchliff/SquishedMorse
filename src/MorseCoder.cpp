#include "MorseCoder.h"

MorseCoder::MorseCoder()
{
	const std::string morseStr{
		".- -... -.-. -.. . ..-. --. .... .. .--- -.- .-.. -- -. --- .--. "
		"--.- .-. ... - ..- ...- .-- -..- -.-- --.."
	};
	const std::string alphabet{ "abcdefghijklmnopqrstuvwxyz" };

	std::vector <std::string> morseParts{};
	boost::algorithm::split(morseParts, morseStr, boost::is_any_of(" "));

	for (int i = 0; i < alphabet.length(); ++i)
	{
		toMorse[alphabet[i]] = morseParts[i];
		fromMorse[morseParts[i]] = alphabet[i];
	}
}

std::string MorseCoder::encode(std::string text, bool smooshed)
{
	std::string output{};
	for (int i = 0; i < text.length() - 1; ++i)
	{
		output += toMorse[text[i]];
		if (!smooshed)
			output += ' ';
	}
	output += toMorse[text[text.length() - 1]];
	return output;
}

std::string MorseCoder::decode(std::string morse)
{
	std::string output{};
	
	std::stringstream morseStream{ morse };
	for (
		std::istream_iterator<std::string> letter(morseStream);
		letter != std::istream_iterator<std::string>();
		++letter
	)
	{
		output += fromMorse[*letter];
	}
	return output;
}