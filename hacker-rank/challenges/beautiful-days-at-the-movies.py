#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the beautifulDays function below.
def beautifulDays(i, j, k):
    
    def reverse(n):
        return int(''.join([c for c in reversed(str(n))]))
    
    count = 0
    for i in range(i, j+1):
        if abs(i-reverse(i)) % k == 0:
            count += 1
    
    return count

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    ijk = input().split()

    i = int(ijk[0])

    j = int(ijk[1])

    k = int(ijk[2])

    result = beautifulDays(i, j, k)

    fptr.write(str(result) + '\n')

    fptr.close()
