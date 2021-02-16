'''
Binary Numer in a Linked List
A binary number is represented as a series of 0's and 1's. 
In this challenge, the series will be in the form of a singly-linked list. 
Each node instance, a LinkedListNode, has a value, data, and a pointer to the next node, next. 
Given a reference to the head of a singly-linked list, convert the binary number represented to a decimal number.
'''
import math
import os
import random
import re
import sys

class SinglyLinkedListNode:
    def __init__(self, node_data):
        self.data = node_data
        self.next = None

class SinglyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def insert_node(self, node_data):
        node = SinglyLinkedListNode(node_data)
        if not self.head:
            self.head = node
        else:
            self.tail.next = node
        self.tail = node

def print_singly_linked_list(node, sep, fptr):
    while node:
        fptr.write(str(node.data))
        node = node.next
        if node:
            fptr.write(sep)

def getNumber(binary):
    # Write your code here
    tmp = ""
    while binary:
        tmp += str(binary.data)
        binary = binary.next
    decimal = int(tmp, 2)
    return decimal

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')
    binary_count = int(input().strip())
    binary = SinglyLinkedList()

    for _ in range(binary_count):
        binary_item = int(input().strip())
        binary.insert_node(binary_item)

    result = getNumber(binary.head)
    fptr.write(str(result) + '\n')
    fptr.close()