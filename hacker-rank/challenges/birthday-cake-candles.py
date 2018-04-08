#!/bin/python3

import os
import sys

#
# Complete the birthdayCakeCandles function below.
#
def birthdayCakeCandles(n, ar):
    #
    # Write your code here.
    #
    prev_value = -1
    count = 0
    for value in sorted(ar, reverse=True):
        if prev_value == -1:
            prev_value = value
        elif value != prev_value:
            break
        count += 1
    
    return count



if __name__ == '__main__':
    f = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    ar = list(map(int, input().rstrip().split()))

    result = birthdayCakeCandles(n, ar)

    f.write(str(result) + '\n')

    f.close()
