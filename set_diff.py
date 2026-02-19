# Read input
n = int(input())
arr = set(map(int, input().split()))

m = int(input())
brr = set(map(int, input().split()))

# Symmetric Difference
result = sorted(arr.symmetric_difference(brr))

# Print result
print(*result, sep="\n")
