

if __name__ == '__main__':
    n = 2**1000
    res = 0
    
    while n:
        res += n%10
        n/=10
    
    print res
