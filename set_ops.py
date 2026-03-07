# Enter your code here. Read input from STDIN. Print output to STDOUT
n = int(input())
m = set(map(int, input().split()))
p = int(input())

for _ in range(p):
    ll, ll1 = input().split()
    m2 = set(map(int, input().split()))

    if ll == "intersection_update":
        m.intersection_update(m2)
    elif ll == "update":
        m.update(m2)
    elif ll == "symmetric_difference_update":
        m.symmetric_difference_update(m2)
    elif ll == "difference_update":
        m.difference_update(m2)

print(sum(m))
