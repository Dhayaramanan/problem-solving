#include <iostream>
#include <numeric> // for std::accumulate

void getScores(int* scores, size_t n)
{
    for (size_t i = 0; i < n; ++i)
    {
        std::cin >> scores[i];
    }
}

std::string_view whoGotBetterRank(int* dragon, int* sloth, size_t num_subjects)
{
    // calculating total marks of each (dragon, sloth)
    int dragonTotal = std::accumulate(dragon, dragon + num_subjects, 0);
    int slothTotal = std::accumulate(sloth, sloth + num_subjects, 0);

    if (dragonTotal != slothTotal)
        return ((dragonTotal > slothTotal) ? "DRAGON" : "SLOTH");
    
    // checking for dsa mark
    if (dragon[0] != sloth[0])
        return ((dragon[0] > sloth[0]) ? "DRAGON" : "SLOTH");
    
    // checking for toc mark
    if (dragon[1] != sloth[1])
        return ((dragon[1] > sloth[1]) ? "DRAGON" : "SLOTH");
        
    return "TIE";
}

int main()
{
    int test_cases{};
    std::cin >> test_cases;

    for (size_t i = 0; i < test_cases; ++i)
    {
        const int number_of_subjects{ 3 }; // dsa, toc, dm
        
        int dragon_scores[number_of_subjects]{};
        int sloth_score[number_of_subjects]{};

        getScores(dragon_scores, number_of_subjects);
        getScores(sloth_score, number_of_subjects);

        std::cout << whoGotBetterRank(dragon_scores, sloth_score, number_of_subjects) << '\n';
    }

    return 0;
}