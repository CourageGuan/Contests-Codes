
s = [0,3,3,5,4,4,3,5,5,4,3,6,6,8,8,7,7,9,8,8,6,7,11]

def cal(t):
    res = 0
    if t >= 100:
        res += s[t/100]
        res += s[21]
        t %= 100
        if t: res += 3
    if t >= 20:
        if t >=30:
            res += s[t/10 + 10] - ((t/10 == 4) and 3 or 2)
        else:
            res += s[20]
        t %= 10
    res += s[t]
    return res

def main():
    n = 1000
    Sum = s[22]
    for i in range(1,n):
        Sum += cal(i);
    print Sum

main()
