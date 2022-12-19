#include <random>
#include <cmath>
#include <string>
#include "igloo/igloo_alt.h"
#include "011_reverse_words/reverse_words.h"

using namespace std;
using namespace igloo;

Describe(Tests) {
    It(Sample_Test_Cases) {
        Assert::That(reverse_words("The quick brown fox jumps over the lazy dog."),
                     Equals("ehT kciuq nworb xof spmuj revo eht yzal .god"));
        Assert::That(reverse_words("apple"), Equals("elppa"));
        Assert::That(reverse_words("a b c d"), Equals("a b c d"));
        Assert::That(reverse_words("double  spaced  words"), Equals("elbuod  decaps  sdrow"));
        Assert::That(reverse_words(" Test with a leading space"), Equals(" tseT htiw a gnidael ecaps"));
        Assert::That(reverse_words("Test with a trailing space "), Equals("tseT htiw a gniliart ecaps "));
        Assert::That(reverse_words(""), Equals(""));
        Assert::That(reverse_words("ab   ba   cd"), Equals("ba   ab   dc"));
    }

    It(Random_Test_Cases) {
        for (int i = 0; i < 200; i++) {
            const std::string str = make_string(rand_number(1, 20));
            auto expected = sol(str);
            Assert::That(reverse_words(str), Equals(expected));
        }
    }

    std::string make_string(int length) {
        std::string str;
        for (int i = 1; i < length; i++) {
            str += make_word(1, 20) + " ";
        }
        return str;
    }

    std::string make_word(int min, int max) {
        std::random_device rd;  //Will be used to obtain a seed for the random number engine
        std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
        std::uniform_real_distribution<> dis(0.0, 1.0);

        std::string possible = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        int length = std::ceil((dis(gen) * max) + min);
        std::string word = "";

        for (int i = 0; i < length; i++)
            word += possible[std::floor(dis(gen) * possible.size())];

        return word;
    }

    int rand_number(int min, int max) {
        std::random_device rd;  //Will be used to obtain a seed for the random number engine
        std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
        std::uniform_real_distribution<> dis(0.0, 1.0);
        return std::ceil((dis(gen) * max) + min);
    }

    std::string sol(std::string str) {
        std::string res;
        std::string word;
        int length = str.length();
        for (int i = 0; i < length; i++) {
            if (str[i] != ' ') {
                word = str[i] + word;
            } else {
                if (word.length() > 0) {
                    res += word;
                    word = "";
                }
                res += " ";
            }
        }
        return res + word;
    }
};
