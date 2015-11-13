#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 1010;
int a[maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	int n,cnt = 0,cur = 0;
	bool flag =true;
	scanf("%d",&n);
	for(int i=0;i<n;++i) scanf("%d",a+i);
	while(flag)
	{
		flag = false;
		if(cnt&1)
		{
			for(int i=n-1;i>=0;--i)
			{
				if(a[i]!=-1)
				{
					if(a[i] <= cur) ++cur,a[i] = -1;
					else flag = true;
				}
			}
		}
		else
		{
			for(int i=0;i<n;++i)
			{
				if(a[i]!=-1)
				{
					if(a[i] <= cur) ++cur,a[i] = -1;
					else flag = true;
				}
			}
		}
		++cnt;
	}
	printf("%d\n",cnt-1);
	return 0;
}
