
while 1:
    s=raw_input()
    if s=='': break
    n,m=map(long,s.split())
    if n==1:
        print 6%m
    elif n==2:
        print 18%m
    else:
        n-=1
        print (n*(n+1)*(2*n+1)+3*n*(n+1)-6*n-6+18)%m 
