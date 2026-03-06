from itertools import product

k, m = map(int, input().split())
lists = []

for _ in range(k):
    x = list(map(int, input().split()))
    lists.append(x[1:])   # skip first number (count)

ans = 0

for i in product(*lists):
    s = sum(j*j for j in i) % m
    ans = max(ans, s)

print(ans)
