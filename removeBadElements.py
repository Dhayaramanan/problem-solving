from re import M


def main():
    test_cases = int(input())

    for i in range(test_cases):
        length_of_array = int(input())
        arr = list(map(int, input().split()))

        map_dict = {}

        for i in arr:
            if i not in map_dict:
                map_dict[i] = 1
            else:
                map_dict[i] += 1

        max_value = max(map_dict.values())
        # print(max_value)
        print(length_of_array - max_value)


if __name__ == '__main__':
    main()
