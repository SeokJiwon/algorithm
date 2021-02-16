'''
Fun with Anagrams
Problem Statement
Two strings are anagrams if they are permutations of each other. 
For example, “aaagmnrs” is an anagram of “anagrams”. 
Given an array of strings, remove each string that is an anagram of an earlier string, then return the remaining array in sorted order.
'''
import math
import os
import random
import re
import sys

def funWithAnagrams(text):
    # Write your code here
    answer = []
    found = []
    for i in range(len(text)):
        word = text[i]
        word = "".join(sorted(word)) 
        if (word not in found): 
            answer.append(text[i])  
            found.append(word)            
    return sorted(answer) 

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')
    text_count = int(input().strip())
    text = []

    for _ in range(text_count):
        text_item = input()
        text.append(text_item)

    result = funWithAnagrams(text)
    fptr.write('\n'.join(result))
    fptr.write('\n')
    fptr.close()