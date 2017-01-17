
f = open('18.txt','r')

def main():
    a = []
    d = []
    cnt = 0
    while 1:
        s = f.readline()
        if s == '': break
        a.append(map(int,s.split()))
        cnt += 1
    for i in range(cnt):
        if not i: 
            d.append([a[0][0]])
            continue
        t = []
        for j in range(i+1):
            t1 = (j <= i-1) and d[i-1][j] or 0
            t2 = (j-1 >= 0) and d[i-1][j-1] or 0
            t.append(max(t1,t2)+a[i][j])
        d.append(t)
    ans = 0
    for i in range(cnt):
        ans = max(ans,d[cnt-1][i])
    print ans

main()
