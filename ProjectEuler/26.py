
def cal(d):
    st = set([])
    cur = 1
    len = 0
    while 1:
        while cur < d:
            cur *= 10
        if cur in st:
            return len
            break
        st.add(cur)
        len += 1
        cur %= d
        if not cur:
            return 0

def main():
    ans = 2
    mx = 0
    for d in range(2,1000):
        t = cal(d)
        if t > mx:
            mx = t
            ans = d
    print ans,mx

main()

