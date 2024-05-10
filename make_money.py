def main():
    test_cases = int(input())

    for i in range(test_cases):
        _number_of_bags, max_limit_of_coins, cost_of_operation = map(int, input().split())
        coins_in_bags = list(map(int, input().split()))

        total_cost = 0

        for index, element in enumerate(coins_in_bags):
            # operation of increasing coins in each bag is performed only when increase in number of coins
            # in each bag is greater than the cost of performing the operation
            if ((max_limit_of_coins - element) > cost_of_operation):
                total_cost += cost_of_operation
                coins_in_bags[index] = max_limit_of_coins
        
        
        print(sum(coins_in_bags) - total_cost)
            


if __name__== '__main__':
    main()


"""
Alternative way

def main():
    test_cases = int(input())

    for _ in range(test_cases):
        _number_of_bags, max_limit_of_coins, cost_of_operation = map(int, input().split())
        coins_in_bags = list(map(int, input().split()))

        total_cost = sum(max_limit_of_coins - coin if max_limit_of_coins - coin > cost_of_operation else 0 for coin in coins_in_bags)
        total_coins = sum(coin if coin + cost_of_operation <= max_limit_of_coins else max_limit_of_coins for coin in coins_in_bags)

        print(total_coins - total_cost)

if __name__== '__main__':
    main()
"""