#include<bits/stdc++.h>
using namespace std;
typedef long long LL;


int main()
{
	//freopen("test.txt","r",stdin);
	int n,h,k;
	LL rem,ans;
	rem = ans = 0;
	cin >> n >> h >> k;
	for(int i=0;i<n;++i)
	{
		int a;
		scanf("%d",&a);
//		puts("ok");
		if(rem + a <= h) rem += a;
		else
		{
			int l = 0,r = n,res = 0;
			while(l <= r)
			{
				int m = l+r >> 1;
				if(rem - ((LL)m*k>=rem?rem:(LL)m*k) + a <= h)
				{
					res = m;
					r = m-1;
				}
				else l = m+1;
			}
//			printf("%d %d\n",rem,res);
			ans += res;
			rem = rem - ((LL)res*k>=rem?rem:(LL)res*k) + a;
		}
	}
	ans += rem/k + (rem%k != 0);
	cout << ans << '\n';
	return 0;
}
