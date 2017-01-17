
def main():
    d = [0 for i in range(201)]
    m = [1,2,5,10,20,50,100,200]
    d[0] = 1
    for c in m:
        for i in range(201):
            if i+c  <= 200 and d[i]:
                d[i+c] += d[i]

    print d[200]

main()

