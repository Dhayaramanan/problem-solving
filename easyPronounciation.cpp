// #include <algorithm>
#include <iostream>
#include <string_view>

bool isEasyPronounciation(std::string_view s)
{
    // char vowels[] = {'a', 'e', 'i', 'o', 'u'};
    std::string vowels = "aeiou";
    int consonantCount{};
    int flag{};

    for (const auto& i : s)
    {
        // auto position = std::find(std::begin(vowels), std::end(vowels), i);
        auto position = vowels.find(i);

        if (position != std::string::npos) {
            // character is a vowel
            consonantCount = 0;
            continue;
        }
        else {
            ++consonantCount;
            if (consonantCount == 4) {
                flag = 1;
                break;
            }
        }
    }

    if (flag)
        return false;
    return true;
}

int main()
{
    int test_cases{};
    std::cin >> test_cases;

    for (int i = 0; i < test_cases; ++i)
    {
        int length_of_string{};
        std::string s{};

        std::cin >> length_of_string >> s;

        std::cout << ((isEasyPronounciation(s)) ? "Yes\n" : "No\n");
    }

    return 0;
}