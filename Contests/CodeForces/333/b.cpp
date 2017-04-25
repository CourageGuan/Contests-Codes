#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int a[maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	int n,ans = 0;
	int mx[2],mn[2];
	for(int i=0;i<2;++i) mx[i] = mn[i] = 0;
	scanf("%d",&n);
	for(int i=0;i<n;++i) scanf("%d",a+i);
	for(int i=1;i<n;++i)
	{
		if(a[mx[1]] == a[i]) mx[1] = i;
		if(a[mn[1]] == a[i]) mn[1] = i;

		if(a[mx[0]] < a[i])
		{
			mx[0] = mx[1] = i;
			while(a[i] - a[mn[1]] > 1) ++mn[1];
			if(a[mn[0]] != a[mn[1]]) mn[0] = mn[1];
		}
		else if(a[mn[0]] > a[i])
		{
			mn[0] = mn[1] = i;
			while(a[mx[1]] - a[i] > 1) ++mx[1];
			if(a[mx[0]] != a[mx[1]]) mx[0] = mx[1];
		}

		/*
		printf("%d %d\n",mx[0],mx[1]);
		printf("%d %d\n",mn[0],mn[1]);
		puts("");
		*/
		
		int mmax = -1,mmin = maxn;
		for(int j=0;j<2;++j)
		{
			mmax = max(mmax,max(mn[j],mx[j]));
			mmin = min(mmin,min(mn[j],mx[j]));
		}
		ans = max(ans,mmax - mmin + 1);
	}
	printf("%d\n",ans);
	return 0;
}
