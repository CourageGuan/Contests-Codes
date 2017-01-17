

def main():
    n = 501
    S = 1
    cur = 1
    for i in range(n-1):
        for j in range(4):
            cur += (i+1)*2
            #print cur
            S += cur
    print S

main()
