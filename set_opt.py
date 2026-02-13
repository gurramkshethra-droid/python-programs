n = int(input())
arr = set(map(int, input().split()))
m = int(input())

for _ in range(m):
    cmd = input().split()
    
    if cmd[0] == "pop":
        arr.remove(min(arr))   # simulate correct pop behavior
    elif cmd[0] == "remove":
        arr.remove(int(cmd[1]))
    elif cmd[0] == "discard":
        arr.discard(int(cmd[1]))

print(sum(arr))
