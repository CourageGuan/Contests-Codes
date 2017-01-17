from datetime import datetime
from datetime import timedelta

def main():
    year = 1901
    mon = 1
    L = datetime(year,mon,1) 
    R = datetime(2000,12,31)
    cnt = 0
    while L < R:
        if L.weekday() == 6:
            cnt+=1
        mon += 1
        if mon > 12: 
            year += 1
            mon -= 12
        L = datetime(year,mon,1)
    print cnt

main()
