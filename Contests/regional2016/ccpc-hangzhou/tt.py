
k = 2

def cal(t,k):
	res = 0
	while t:
		res += (t%10)**k
		t /= 10
	return res

for i in range(10000):
	if i == cal(i,k):
		print i
