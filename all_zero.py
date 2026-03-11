t = int(input())

for _ in range(t):
    a, b, c = map(int, input().split())

    if c % 3 == 0 and b == 2*a + c//3:
        print("Yes")
    else:
        print("No")
