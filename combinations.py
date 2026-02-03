from itertools import combinations
m,n=input().split()
result=sorted(m)
n=int(n)
for i in range(1,n+1):
    for c in combinations(result,i):
        print(''.join(c))
    