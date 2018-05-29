#!/bin/python3

import math

if __name__ == '__main__':
    n = int(input())
    colors = {}
    colors_list = [int(x) for x in input().strip().split()]
    for color in colors_list:
        if color in colors:
            colors[color] += 1
        else:
            colors[color] = 1
    ans = 0
    for color in colors:
        if colors[color] % 2 == 0:
            ans += int(colors[color] / 2)
        else:
            ans += int((colors[color] - 1)/2)
    
    print(ans)