
def main():
	n = int(raw_input())
	lst = map(int,raw_input().split())
	st = []
	for a in lst:
		st.append(a)
		if a == n:
			n -= len(st)
			for i in sorted(st,reverse = True):		
				print i,
			st = []
		print

if __name__ == '__main__':
	main()
