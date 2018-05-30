#!/bin/python3

import os
import sys

#
# Complete the pageCount function below.
#
def pageCount(n, p):
    #
    # Write your code here.
    #
    max_turns = n/2 if n % 2 == 0 else (n-1)/2
    turns_left_to_right = p/2 if p % 2 == 0 else (p-1)/2
    
    return int(min(turns_left_to_right, max_turns - turns_left_to_right))
        

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    p = int(input())

    result = pageCount(n, p)

    fptr.write(str(result) + '\n')

    fptr.close()