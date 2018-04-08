#!/bin/python3

import sys
import math

def find_largest_prime_factor(n):
    max_prime_factor  = -1

    # using "trial and division" method
    for i in range(2, int(math.sqrt(n)) + 1):
        while n % i == 0:
            if i > max_prime_factor:
                max_prime_factor = i
            n /= i
    
    if n != 1 and n > max_prime_factor:
        max_prime_factor = n
    
    return int(max_prime_factor)


t = int(input().strip())
for a0 in range(t):
    n = int(input().strip())
    print(find_largest_prime_factor(n))
