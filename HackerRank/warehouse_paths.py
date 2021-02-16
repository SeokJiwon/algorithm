'''
Paths in a Warehouse
A forklift worker moves products from one place to the other in an automotive parts warehouse. 
There a map in the dashboard that shows, in real time, the open and blocked sections inside the warehouse.
The map is displayed as an n*m matrix of 1's and 0's which represent open and blocked sections respectively.
A forklift driver always starts at the upper left corner of the map at warehouse[0][0] and tries to reach the bottom right section of the map or warehouse[n-1][m-1].
Each movement must be in increasing value along a row or column but not both.
Given the warehouse map, determine the number of distinct paths to get from warehouse[0][0] to warehouse[n-1][m-1].
The number may be large, so return the value modulo (10^9+7).
'''
import math
import os
import random
import re
import sys

def numPaths(warehouse):
    if warehouse[0][0]==0:
        return 0
    
    paths = [[0]*len(warehouse[0]) for i in warehouse]
    if warehouse[0][0] == 1:
        paths[0][0] = 1
     
    for i in range(1, len(warehouse)):
        if warehouse[i][0] == 1:
            paths[i][0] = paths[i-1][0]
             
    for j in range(1, len(warehouse[0])):
        if warehouse[0][j] == 1:
            paths[0][j] = paths[0][j-1]
             
    for i in range(1, len(warehouse)):
        for j in range(1, len(warehouse[0])):
            if warehouse[i][j] == 1:
                paths[i][j] = paths[i-1][j] + paths[i][j-1]
 
    return paths[-1][-1]%1000000007

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    warehouse_rows = int(input().strip())
    warehouse_columns = int(input().strip())
    warehouse = []

    for _ in range(warehouse_rows):
        warehouse.append(list(map(int, input().rstrip().split())))

    result = numPaths(warehouse)
    fptr.write(str(result) + '\n')
    fptr.close()