def average(array):
    # your code goes here
    values=set(array)
    length=len(values)
    total=0
    for i in values:
        total+=i
    avg=total/length
    return avg
if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    result = average(arr)
    print(f"{result:.3f}")