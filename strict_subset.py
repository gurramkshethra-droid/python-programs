A = set(map(int, input().split()))
n = int(input())

result = True

for _ in range(n):
    B = set(map(int, input().split()))
    if not A > B:#strict condition
        result = False

print(result)
