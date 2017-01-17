
def main():
    a , b = 1 , 1
    i = 2
    while 1:
        i += 1
        a , b = b , a+b
        if len(str(b)) >= 1000:
            print i
            break

main()
