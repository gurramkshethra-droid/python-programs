t = int(input())
for _ in range(t):
    N, M, A, B, C = map(int, input().split())
    
    combos = min(N, M)
    cost = combos * C + (N - combos) * A + (M - combos) * B
    
    print(cost)
