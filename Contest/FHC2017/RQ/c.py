def solve():
	T = int(raw_input())
	for z in range(T):
		h,s = map(int,raw_input().split())
		ans = 0.0
		ts = raw_input().split();

		for i in range(s):
			ss = ts[i]
			a = int(ss[:ss.find('d')])
			c = 0
			if '-' in ss: 
				b = int(ss[ss.find('d')+1:ss.find('-')])
				c = - int(ss[ss.find('-')+1:])
			elif '+' in ss:
				b = int(ss[ss.find('d')+1:ss.find('+')])
				c = int(ss[ss.find('+')+1:])
			else:
				b = int(ss[ss.find('d')+1:])

			d = []
			p = []

			for j in range(a*b+1):
				d.append(0)
				p.append(0)

			d[0] = 1

			for j in range(a+1):
				for k in range(a*b+1):
					p[k] = 0
				for k in range(a*b,0,-1):
					for l in range(1,b+1):
						if k - l >= 0:
							p[k] += d[k-l]
				p,d = d,p

			cnt = 0
			for j in range(1,a*b+1):
				if j + c >= h: cnt += p[j]

			ans = max(ans,float(cnt)/(b**a))


		print "Case #%d: %.8f"%(z+1,ans)

if __name__ == '__main__':
	solve()
