
n = 28123L

def cal(n):
    s = 0
    i = 1
    while i*i <= n:
        if n%i == 0:
            s += i
            if i*i != n and i!=1:
                s += n/i
        i += 1
    return s


def main():
    s = [x for x in range(1,n+1) if(cal(x) > x)]
    m = len(s)
    dec = 0
    vis = set([])
    for i in range(m):
        for j in range(i+1):
            t = s[i] + s[j]
            if  t <= n:
                vis.add(t)
    print (1+n)*n/2 - sum(vis)

main()
