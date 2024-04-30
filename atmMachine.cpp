#include <iostream>
#include <vector>

void getArray(int* array, int size) {
    for (size_t i = 0; i < size; ++i) {
        std::cin >> array[i];
    }
}

void possibleToGetMoneyOrNot(int* moneyRequired, int numberOfPeople, int totalMoney) {
    std::string possibility{};

    for (size_t i = 0; i < numberOfPeople; ++i) {
        if (moneyRequired[i] <= totalMoney) {
            possibility.append("1");
            totalMoney -= moneyRequired[i];
        } else {
            possibility.append("0");
        }
    }

    std::cout << possibility << '\n';
}

int main() {
    int test_cases{};
    std::cin >> test_cases;

    for (size_t i = 0; i < test_cases; ++i) {
        int numberOfPeople{};
        int totalMoney{};

        std::cin >> numberOfPeople >> totalMoney;

        std::vector<int> moneyRequired(numberOfPeople);

        getArray(moneyRequired.data(), numberOfPeople);

        possibleToGetMoneyOrNot(moneyRequired.data(), numberOfPeople, totalMoney);
    }
    

    return 0;
}