
f = open('22.txt','r')

def main():
    s = f.readline()
    names = map(lambda x:x[1:-1],s.split(','))
    names.sort()
    ans = 0
    cnt = 1
    for s in names:
        res = 0
        for c in s:
            res += ord(c) - ord('A') + 1
        ans += res*cnt
        cnt += 1
    print ans

main()
