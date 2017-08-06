# https://www.codingame.com/ide/puzzle/there-is-no-spoon-episode-1

import sys
import math

# Don't let the machines win. You are humanity's last hope...

w = int(input())  # the number of cells on the X axis
h = int(input())  # the number of cells on the Y axis
grid = [[0 for x in range(w)] for y in range(h)]
for l in range(h):
    line = input()
    for c in range(w):
        if line[c] == '0':
            grid[l][c] = 1

for l in range(h):
    for c in range(w):
        if grid[l][c] != 0:
            rightNeighbor = (-1, -1)
            tempc = c
            while tempc + 1 < w:
                if grid[l][tempc + 1] != 0:
                    rightNeighbor = (tempc + 1, l)
                    break
                else:
                    tempc = tempc + 1

            leftNeighbor = (-1, -1)
            templ = l
            while templ + 1 < h:
                if grid[templ + 1][c] != 0:
                    leftNeighbor = (c, templ + 1)
                    break
                else:
                    templ = templ + 1

            out = '{} {} {} {} {} {}'
            out = out.format(
                c, l, rightNeighbor[0], rightNeighbor[1], leftNeighbor[0], leftNeighbor[1])
            print(out)