
def d(n):
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
#   print d(1)
    print sum(x for x in range(2,10000) if(d(d(x)) == x and d(x) != x))

main()
