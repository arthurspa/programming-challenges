#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the journeyToMoon function below.
def journeyToMoon(n, astronaut):
    nodes = {}
    for i in range(n):
        nodes[i] = set()
    
    for u,v in astronaut:
        if u not in nodes[v]:
            nodes[v].add(u)
        if v not in nodes[u]:
            nodes[u].add(v)
    
    def dfs(nodes, start, visited):
        stack = [start]
        count = 0
        while stack:
            u = stack.pop()
            if u not in visited:
                visited.add(u)
                stack.extend(nodes[u]-visited)
                count += 1
        
        return count
    
    visited = set()
    countries = []
    for person in nodes:
        if person not in visited:
            countries.append(dfs(nodes, person, visited))
    
    result = 0
    sum = 0
    for size in countries:
        result += sum*size
        sum += size
    
    return result
            
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    np = input().split()

    n = int(np[0])

    p = int(np[1])

    astronaut = []

    for _ in range(p):
        astronaut.append(list(map(int, input().rstrip().split())))

    result = journeyToMoon(n, astronaut)

    fptr.write(str(result) + '\n')

    fptr.close()
