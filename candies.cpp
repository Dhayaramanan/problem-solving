#include <algorithm> // for std::count
#include <iostream>
#include <vector>

// Both arrays can have distinct elements only if
// no element in the original array is repeated more than twice.

void get_prices(std::vector<int>& candy_prices, const size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        int value{};
        std::cin >> value;
        candy_prices.push_back(value);
    }
}

bool is_possible_to_split(const std::vector<int>& candy_prices)
{
    for (const auto& i : candy_prices)
    {
        // if the occurence of an element is more than 2 then,
        // it is not possible to split array into two array of distinct elements
        int occurence_count = std::count(candy_prices.begin(), candy_prices.end(), i);
        
        if (occurence_count > 2)
            return false;
    }

    return true;
}

int main()
{
    int test_cases{};
    std::cin >> test_cases;

    for (size_t i = 0; i < test_cases; ++i)
    {
        int number_of_cities{};
        std::cin >> number_of_cities;

        const int size = 2 * number_of_cities;
        std::vector<int> candy_prices;
        candy_prices.reserve(size);

        get_prices(candy_prices, size);

        std::cout << ((is_possible_to_split(candy_prices)) ? "YES" : "NO") << '\n';
    }

    return 0;
}
