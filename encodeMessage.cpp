#include <algorithm> // for std::reverse()
#include <iostream>
#include <string>


void swap(std::string& message, int length)
{
    if (length % 2 == 0)
    {
        for (int i = 0; i < length-1; i+=2)
        {
            char temp = message.at(i);
            message.at(i) = message.at(i+1);
            message.at(i+1) = temp;
        }
    }
    else
    {
        for (int i = 0; i < length-2; i+=2)
        {
            char temp = message.at(i);
            message.at(i) = message.at(i+1);
            message.at(i+1) = temp;   
        }
    }

    /*
    all the above can be done by below code
    for (int i = 0; i < length-1; i+=2)
    {
        std::swap(message.at(i), message.at(i+1));
    }
    */
}


void replace(std::string& message, int length)
{
    std::string alphabets = "abcdefghijklmnopqrstuvwxyz";
    std::string reverse_alphabets = alphabets;
    std::reverse(reverse_alphabets.begin(), reverse_alphabets.end());

    for (size_t i = 0; i < length; ++i)
    {
        size_t index = alphabets.find(message.at(i));
        message.at(i) = reverse_alphabets.at(index);
    }

    /*
    all the above can be done like

    for (size_t i = 0; i < length; ++i)
    {
        message.at(i) = 'a' + 'z' - message.at(i);
    }
    */
}


int main()
{
    int testCases{};
    std::cin >> testCases;

    while (testCases--)
    {
        int lengthOfMessage{};
        std::string message{};

        std::cin >> lengthOfMessage >> message;

        swap(message, lengthOfMessage);
        replace(message, lengthOfMessage);

        std::cout << message << '\n';
    }

    return 0;
}

/*
COPILOT generated code

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>

void swapAndReplace(std::string& message) {
    std::string alphabets = "abcdefghijklmnopqrstuvwxyz";
    std::string reverse_alphabets = alphabets;
    std::reverse(reverse_alphabets.begin(), reverse_alphabets.end());

    std::unordered_map<char, char> charMap;
    for (size_t i = 0; i < alphabets.size(); ++i) {
        charMap[alphabets[i]] = reverse_alphabets[i];
    }

    for (size_t i = 0; i < message.size(); i += 2) {
        if (i + 1 < message.size()) {
            std::swap(message[i], message[i + 1]);
        }
        message[i] = charMap[message[i]];
        if (i + 1 < message.size()) {
            message[i + 1] = charMap[message[i + 1]];
        }
    }
}

int main() {
    int testCases{};
    std::cin >> testCases;

    while (testCases--) {
        int lengthOfMessage{};
        std::string message{};

        std::cin >> lengthOfMessage >> message;

        swapAndReplace(message);

        std::cout << message << '\n';
    }

    return 0;
}
*/