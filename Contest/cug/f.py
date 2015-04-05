mod=10**9+7

while 1:
    s=raw_input()
    if s=='': break
    t1,t2=map(long,s.split())
    n=long(raw_input())
    arr=[0,t1,t2,t2-t1,-t1,-t2,t1-t2]
    n=n%6
    if n==0: n=6
    print arr[n]%mod
