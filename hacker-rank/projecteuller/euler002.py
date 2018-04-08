#!/bin/python3

import sys


t = int(input().strip())
for a0 in range(t):
    n = int(input().strip())
    f0 = 1
    f1 = 2
    sum = 0
    while f1 <= n:
        if f1 % 2 == 0:
            sum += f1
        temp = f0 + f1
        f0 = f1
        f1 = temp
    print(sum)