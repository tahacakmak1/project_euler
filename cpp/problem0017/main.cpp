#include <array>
#include <cstdint>
#include <iostream>
#include <string>

std::array<std::string const, 20> const ONES{
    "zero",     "one",     "two",     "three",     "four",     "five",    "six",
    "seven",    "eight",   "nine",    "ten",       "eleven",   "twelve",  "thirteen",
    "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
std::array<std::string const, 10> const
    TENS{"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

void numberToText(uint16_t num, std::string& str) {
    if (num >= 0 && num < 20)
        str.append(ONES.at(num));
    else if (num >= 20 && num <= 90 && num % 10 == 0)
        str.append(TENS.at(num / 10));
    else if (num > 20 && num < 100) {
        str.append(TENS.at(num / 10));
        str.append(ONES.at(num % 10));
    }
    else if (num >= 100 && num <= 900 && num % 100 == 0) {
        str.append(ONES.at(num / 100));
        str.append("hundred");
    }
    else if (num > 100 && num < 1000) {
        str.append(ONES.at(num / 100));
        str.append("hundredand");
        numberToText(num % 100, str);
    }
    else if (num == 1000)
        str.append("onethousand");
}

int main() {
    std::string totalText{""};
    for (int i = 1; i < 1001; i++) {
        numberToText(i, totalText);
    }
    std::cout << totalText.length();
    return 0;
}
