import re

n = int(input())

for _ in range(n):
    s = input()
    try:
        re.compile(s)
        print("True")
    except:
        print("False")
