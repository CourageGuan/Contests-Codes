def main():
    from sys import stdin,stdout
    def gcd(a,b):
        if b == 0:
            return a
        else:
            return gcd(b,a%b)

    t,w,b = map(long,stdin.readline().split())
    
    ans = 0
    
    if w>b: w,b = b,w
    
    lcm = w/gcd(w,b)*b

    if t>=lcm:
        ans += (t/lcm)*w - 1 + min(w,t%lcm +1)
    else:
        ans = min(w-1,t%lcm)

    if ans == 0: 
        print "%d/%d" % (0,1)
    else:
        d = gcd(ans,t)
        print "%d/%d" % (ans/d,t/d)

main()
