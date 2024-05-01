#include <iostream>
#include <vector>

void get_grams_of_protein(std::vector<int>& grams_of_protein, size_t n)
{
    /*
    (COPILOT suggestion for efficiency)
    push_back which can cause vector reallocation if the number of elements exceeds the current capacity.
    Since you know the number of elements beforehand, you can use resize instead of reserve and directly
    assign the values to the vector.
    */
    grams_of_protein.resize(n);
    for (size_t i = 0; i < n; ++i)
    {
        std::cin >> grams_of_protein[i];
    }
}

void having_sufficient_protein(std::vector<int>& grams_of_protein, const int protein_per_day)
{
    int insufficient_day = 0;
    for (size_t i = 0; i < grams_of_protein.size(); ++i)
    {
        if (grams_of_protein[i] < protein_per_day)
        {
            insufficient_day = i + 1;
            break;
        }
        else
        {
            // adding the remaining protein for the next day
            if ((i + 1) < grams_of_protein.size())
                grams_of_protein[i + 1] += grams_of_protein[i] - protein_per_day;
        }
    }

    if (insufficient_day)
        std::cout << "NO " << insufficient_day << '\n';
    else
        std::cout << "YES\n";
}

int main()
{
    int test_cases{};
    std::cin >> test_cases;

    while (test_cases--)
    {
        int number_of_days{};
        int protein_grams_per_day{};

        std::cin >> number_of_days >> protein_grams_per_day;

        std::vector<int> grams_of_protein_brought;

        get_grams_of_protein(grams_of_protein_brought, number_of_days);

        having_sufficient_protein(grams_of_protein_brought, protein_grams_per_day);
    }

    return 0;
}