# cook your dish here
m=int(input())
for _ in range(m):
    x,y,n=map(int,input().split())
    p=y*n
    if(p<=x):
        print(x-p)
    else:
        print(0)