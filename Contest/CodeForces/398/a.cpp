#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define F(i,a,b) for(int (i)=(a);i<(b);++(i))

int main()
{
//	freopen("input.txt","r",stdin);
	int n,t,cnt,a;
	scanf("%d",&n);
	t = n;
	cnt = 0;
	F(i,0,n)
	{
		scanf("%d",&a);
		++cnt;
		if(a == t)
		{
			for(int i=0;i<cnt;++i) printf("%d ",a - i);
			t -= cnt;
			cnt = 0;
		}
		puts("");
	}
	return 0;
}
