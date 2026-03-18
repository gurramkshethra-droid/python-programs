t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    
    # Sort in descending order
    a.sort(reverse=True)
    
    profit = 0
    
    # First K items (cost = 5)
    for i in range(min(k, n)):
        if a[i] > 5:
            profit += (a[i] - 5)
    
    # Remaining items (cost = 10)
    for i in range(k, n):
        if a[i] > 10:
            profit += (a[i] - 10)
    
    print(profit)
