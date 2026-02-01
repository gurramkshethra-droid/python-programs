def merge_the_tools(string, k):
    # your code goes here
    length=len(string)
    if(length%k==0):
        t=length//k
    for i in range(t):
        substr=""
        for ch in string[i*k:(i+1)*k]:
            if ch not in substr:
                substr+=ch
        print(substr)

if __name__ == '__main__':
    string, k = input(), int(input())
    merge_the_tools(string, k)