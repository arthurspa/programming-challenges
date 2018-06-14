#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the solve function below.
def solve(year):
    if year == 1918:
        return '26.09.1918'
    
    if year > 1918 and (year % 400 == 0 or (year % 4 == 0 and year % 100 != 0)) or \
       year < 1918 and (year % 4 == 0):
        return '12.09.{}'.format(year)
    
    return '13.09.{}'.format(year)

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    year = int(input())

    result = solve(year)

    fptr.write(result + '\n')

    fptr.close()
