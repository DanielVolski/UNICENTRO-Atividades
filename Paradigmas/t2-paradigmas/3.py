import math

max_range = 10000

def find_divisors(n: int):
    return list(num for num in range(1, n) if n % num == 0)

def find_friend_numbers():
    sum_of_divisors = list(sum(find_divisors(num)) for num in range(0, max_range))
    friend_numbers = []
    for i in range(0, max_range):
        if (sum_of_divisors[i] < max_range and i == sum_of_divisors[sum_of_divisors[i]] and i < sum_of_divisors[i]):
            friend_numbers.append((i, sum_of_divisors[i]))
    return (sum_of_divisors, friend_numbers)

print(find_friend_numbers())
