#!/bin/python3

if __name__ == '__main__':
    N = int(input())
    
    if N % 2 != 0 or (N % 2 == 0 and (N >= 6 and N <= 20)):
        print('Weird')
    else:
        print('Not Weird')
