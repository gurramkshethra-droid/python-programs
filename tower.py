# Enter your code here. Read input from STDIN. Print output to STDOUT
m=int(input())
mul=1
for i in range(m):
    n=int(input())
    arr=list(map(int,input().split()))
    count=0
    for i in arr:
        if i==2:
            count+=1
    if(count%8==0):
        print("YES")
    else :
        print("NO")
        
