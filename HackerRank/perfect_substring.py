'''
Perfect Substring
A string s comprised of digits from 0 to 9 contains a perfect substring if all the elements within a substring occur exactly k times. 
Calculate the number of perfect substrings in s.
Example) 
s=110202122
k=2
The 6 perfect substrings are:
    s[0:1] = 11
    s[0:5] = 110202
    s[1:6] = 102021
    s[2:5] = 0202
    s[7:8] = 22
    s[8:9] = 22
'''
import math
import os
import random
import re
import sys

def check(k, elements):
    for element in elements:
        if element != 0 and element != k:
            return False
    return True

def perfectSubstring(s, k):
    # Write your code here
    count = 0
    for i in range(0, len(s)):
        arr = [0]* 10
        for j in range(i, len(s)):
            arr[int(s[j])] += 1
            if arr[int(s[j])] > k:
                break
            if arr[int(s[j])] == k and check(k, arr):
                count += 1
    return count

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()
    k = int(input().strip())
    result = perfectSubstring(s, k)

    fptr.write(str(result) + '\n')
    fptr.close()