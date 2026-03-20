# Enter your code here. Read input from STDIN. Print output to STDOUT
m=int(input())
for i in range(m):
    n,k=map(int,input().split())
    s=list(input())
    count=s.count("1")
    for j in range(k):
        changed=False
        for j in range(n-1):
            if s[j]=="0" and s[j+1]=="1":
                s[j]="1"
                count+=1
                changed=True
                break
        if not changed:
            break
    print(count)
