# cook your dish here
t = int(input())

for _ in range(t):
    n = int(input())
    
    ans = 100  # large value
    
    for m in range(1, 101):  # since constraint is small
        if (m % 2 == 0 or m % 5 == 0) and not (m % 2 == 0 and m % 5 == 0):
            ans = min(ans, abs(n - m))
    
    print(ans)