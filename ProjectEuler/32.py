
import itertools

def main():
    st = set([])
    for s in itertools.permutations('123456789',9):
        t = ''.join(s)
        for i in range(1,9):
            for j in range(1,9):
                if i+j >= 9: break
                if long(t[:i])*long(t[i:i+j]) == long(t[i+j:]):
                    print t[i+j:]
                    st.add(long(t[i+j:]))
        
    print sum(st)

main()
