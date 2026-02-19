n = int(input())
arr = set(map(int, input().split()))
m = int(input())

for _ in range(m):
    cmd = input().split()
    
    if cmd[0] == "pop":
        if arr:   # check if set is not empty
            arr.pop()
    elif cmd[0] == "remove":
        arr.remove(int(cmd[1]))   # raises error if not present (as expected)
    elif cmd[0] == "discard":
        arr.discard(int(cmd[1]))  # does nothing if not present

print(sum(arr))
