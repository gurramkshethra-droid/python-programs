# Enter your code here. Read input from STDIN. Print output to STDOUT
n,q=map(int,input().split())
p=[0]+[0]+list(map(int,input().split()))
for _ in range(q):
    a,b=map(int,input().split())
    visited=set()
    while a:
        visited.add(a)
        a=p[a]
    while b:
        if b in visited:
            print(b)
            break
        b=p[b]
