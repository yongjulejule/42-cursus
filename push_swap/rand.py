#!/usr/bin/env python3
import sys
import random

a = sys.argv[1]
a = int(a)
lst = list()
for i in range(1, a):
    i = i + 1
    lst.append(random.randrange(-2147483648, 2147483647))

for nbr in lst:
    print(nbr, end=" ")
