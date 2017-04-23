class Solution(object):

	def cal(self,q,n):
	    return (q**n - 1)/(q-1)
		    
	def smallestGoodBase(self, n):
	    
		tt = s = long(n)
		lens = 0
		while tt:
		    tt /= 2
		    lens += 1
		print lens
		while lens >= 1:
			l,r = 2,s
			res = -1
			while l <= r:
				m = (l+r) >> 1
				if self.cal(m,lens) == s:
					res = m
					break
				if self.cal(m,lens) > s:
					r = m - 1
				else:
					l = m + 1
			if res != -1:
				return res
			lens -= 1

s = Solution()
print s.smallestGoodBase(15) 

