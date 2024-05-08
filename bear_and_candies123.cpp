/*
QUESTION:

Bears love candies and games involving eating them. Limak and Bob play the following game. 
Limak eats 1 candy, then Bob eats 2 candies, then Limak eats 3 candies, then Bob eats 4 candies, and so on. 
Once someone can't eat what he is supposed to eat, he loses.

Limak can eat at most A candies in total (otherwise he would become sick), 
while Bob can eat at most B candies in total. Who will win the game? Print "Limak" or "Bob" accordingly.
*/

#include <iostream>

void whoWins(int limakMax, int bobMax)
{
    // for counting the candies eaten by Limak and Bob
    int limakAte{};
    int bobAte{};

    // For storing the name of winner
    std::string winner{};

    // For increasing the number of candies
    int i{ 1 };

    /*
        Still Limak and Bob will eat until their maximum capability,
        competition continuous until either one of them exceeding their max limit
    */
    while (limakAte <= limakMax && bobAte <= bobMax)
    {
        if (i % 2 != 0)
            limakAte += i;
        else
            bobAte += i;
        
        ++i;

        // std::cout << limakAte << ' ' << bobAte << '\n'; used for debugging purpose

        // if limakAte exceeds limaks max that means Bob wins, vice versa.
        if (limakAte > limakMax)
            winner = "Bob";
        
        if (bobAte > bobMax)
            winner = "Limak";
    }

    std::cout << winner << '\n';
}

int main()
{
    int testCases{};
    std::cin >> testCases;

    while (testCases--)
    {
        int limakMax{};
        int bobMax{};

        std::cin >> limakMax >> bobMax;

        whoWins(limakMax, bobMax);
    }

    return 0;
}

/*
Alternate solution by COPILOT

#include <iostream>

void whoWins(int limakMax, int bobMax)
{
    int limakCandiesEaten = 0, bobCandiesEaten = 0;
    int i = 1;

    while (true)
    {
        if (i % 2 != 0) // Limak's turn
        {
            if (limakCandiesEaten + i > limakMax)
            {
                std::cout << "Bob\n";
                return;
            }
            limakCandiesEaten += i;
        }
        else // Bob's turn
        {
            if (bobCandiesEaten + i > bobMax)
            {
                std::cout << "Limak\n";
                return;
            }
            bobCandiesEaten += i;
        }
        ++i;
    }
}

int main()
{
    int testCases;
    std::cin >> testCases;

    while (testCases--)
    {
        int limakMax, bobMax;
        std::cin >> limakMax >> bobMax;

        whoWins(limakMax, bobMax);
    }

    return 0;
}

*/