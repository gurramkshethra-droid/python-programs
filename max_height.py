# Enter your code here. Read input from STDIN. Print output to STDOUT
n=int(input())
gain=list(map(int,input().split()))
cur=0
max=0
for i in gain:
    cur+=i
    if(cur>max):
        max=cur
print(max)
