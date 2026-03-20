# Enter your code here. Read input from STDIN. Print output to STDOUT
import math
n,k=map(int,input().split())
arr=list(map(int,input().split()))
ans=0
for i in range(n):
    g=0
    for j in range(i,n):
        g=math.gcd(g,arr[j])
        length=j-i+1
        if k>0:
            score=length*g*2
        else:
            score=length*g
        ans=max(ans,score)
print(ans)
