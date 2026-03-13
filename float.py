n = int(input())
for _ in range(n):
    s = input()
    try:
        if '.' in s and float(s):
            print(True)
        else:
            print(False)
    except:
        print(False)
