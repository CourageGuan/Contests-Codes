

def cal(n):
    f5 = 120 
    f6 = f5*6
    f7 = f6*7
    cur = 1
    for i in range(5):
        cur = cur*n
        n -= 1
    res = 0
    res += cur/f5
    cur *= n
    res += cur/f6
    n -= 1
    cur *= n
    res += cur/f7
    return res
    

if __name__ == '__main__':
    n = long(raw_input())
    print cal(n)
