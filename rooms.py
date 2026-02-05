# cook your dish here
t = int(input())

for _ in range(t):
    B, G, X, Y, N = map(int, input().split())

    # Check if even one room is possible
    if X + Y > N:
        print(-1)
        continue

    # Minimum rooms needed by capacity
    min_rooms = (B + G + N - 1) // N   # ceil division

    # Maximum rooms possible by constraints
    max_rooms = min(B // X, G // Y)

    if min_rooms <= max_rooms:
        print(min_rooms)
    else:
        print(-1)
