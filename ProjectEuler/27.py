
yes = set([])
no = set([])

def prime(n):
    if n <= 1 or n%2==0 : return False
    i = 3
    while i*i <= n:
        if n%i == 0:
            return False
        i += 2
    return True


def cal(a,b):
    i = 0
    while 1:
        if prime(i*i+a*i+b): i += 1
        else: break
    return i


def main():
    ta = 0
    tb = 0
    res = 0
    for a in range(-999,1000):
        for b in range(-999,1000):
            cur = cal(a,b)
            if cur > res:
                ta = a
                tb = b
                res = cur
                ans = a*b
    print res,ta,tb,ta*tb

main()


