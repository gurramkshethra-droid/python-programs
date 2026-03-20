# Enter your code here. Read input from STDIN. Print output to STDOUT
m=int(input())
bin=list(map(int,input().split()))
count=0
for i in bin:
    if i==1:
        count+=1
if count==0:
    print(0)
else :
    zero=0
    for i in range(count):
        if(bin[i]==0):
            zero+=1
    minm=zero
    for i in range(count,m):
        if bin[i]==0:
            zero+=1
        if bin[i-count]==0:
            zero-=1
        minm=min(zero,minm)
print(minm)
