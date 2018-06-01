#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the countingValleys function below.
def countingValleys(n, s):   
    valleys_count = 0
    curr_alt = 0
    prev_alt = curr_alt    
    for i in range(n):
        curr_alt += 1 if s[i] == 'U' else -1
        if prev_alt < 0 and curr_alt == 0:
            valleys_count += 1
        prev_alt = curr_alt
    
    return valleys_count
            
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    s = input()

    result = countingValleys(n, s)

    fptr.write(str(result) + '\n')

    fptr.close()
