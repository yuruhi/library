#pragma once
#include <string_view>

namespace CharacterClass {
	constexpr std::string_view
	    digit = "0123456789",
	    xdigit = "0123456789ABCDEFabcdef", lower = "abcdefghijklmnopqrstuvwxyz",
	    upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
	    alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz",
	    alnum = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz",
	    word = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ_abcdefghijklmnopqrstuvwxyz",
	    punct = R"(!"#$%&'()*+,-./:;<=>?@[\]^_`{|}~)",
	    graph =
	        R"(!"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~)",
	    print =
	        R"( !"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~)",
	    blank = " \t", space = " \t\n\r\f\v";
}  // namespace CharacterClass
