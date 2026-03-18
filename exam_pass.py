# cook your dish here
m=int(input())
for i in range(m):
    x,y,z=map(int,input().split())
    if((x>=50  and y>=50) or (y>=50 and z>=50) or (x>=50 and z>=50)):
        print("Yes")
    else :
        print("No")
