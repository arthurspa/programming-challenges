#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the roadsAndLibraries function below.
def roadsAndLibraries(n, c_lib, c_road, cities):
    
    if c_lib <= c_road:
        return c_lib*n
    
    nodes = {}
    for i in range(1, n+1):
        nodes[i] = set()
    for edge in cities:
        u, v = edge
        if u not in nodes[v]:
            nodes[v].add(u)
        if v not in nodes[u]:
            nodes[u].add(v)
    
    def dfs(nodes, start, visited):
        stack = [start]
        connected_cities = 0
        while stack:
            v = stack.pop()
            if v not in visited:
                visited.add(v)
                connected_cities += 1
                stack.extend(nodes[v] - visited)
            
        return connected_cities
    
    total_cost = 0
    visited = set()
    for start_node in nodes:
        if start_node not in visited:
            connected_cities = dfs(nodes, start_node, visited)
            total_cost += (connected_cities-1)*c_road + c_lib
    
    return total_cost
            
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input())

    for q_itr in range(q):
        nmC_libC_road = input().split()

        n = int(nmC_libC_road[0])

        m = int(nmC_libC_road[1])

        c_lib = int(nmC_libC_road[2])

        c_road = int(nmC_libC_road[3])

        cities = []

        for _ in range(m):
            cities.append(list(map(int, input().rstrip().split())))

        result = roadsAndLibraries(n, c_lib, c_road, cities)

        fptr.write(str(result) + '\n')

    fptr.close()
