t = int(input())
for _ in range(t):
    N, K = map(int, input().split())
    A = list(map(int, input().split()))
    
    A.sort()
    M = N - K
    
    medians = set()
    
    for i in range(N - M + 1):
        median_index = (M - 1) // 2
        medians.add(A[i + median_index])
    
    print(*sorted(medians))
