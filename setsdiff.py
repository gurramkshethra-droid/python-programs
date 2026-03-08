# Enter your code here. Read input from STDIN. Print output to STDOUT
n=int(input())
ll1=set(map(int,input().split()))
m=int(input())
ll2=set(map(int,input().split()))
s=ll1.symmetric_difference(ll2)#set_difference
print(len(s))
