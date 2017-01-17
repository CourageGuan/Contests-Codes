import itertools

def main():
    cnt = 1
    for i in itertools.permutations('0123456789',10):
        if cnt == 1000000:
            print cnt
            print ''.join(i)
            break
        cnt += 1

main()

