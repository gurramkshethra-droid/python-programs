from collections import namedtuple
n=int(input())
columns=input().split()
total=0
table=namedtuple('table',columns)
for _ in range(n):
    x=table(*input().split())
    total+=int(x.MARKS)
avg=total/n
print(f"{avg:.2f}")