#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 2e5 + 10;
int n,m,k,s,ci,cj;
int a[maxn],b[maxn],ma[maxn],mb[maxn];
vector<LL> gad[2];
vector<pair<int,int> > id[2];

bool yes(int m)
{
	for(int i=0;i<=k;++i)
	{
		int j = k-i;
		if(i<gad[0].size() && j<gad[1].size() && gad[0][i]*ma[m] + gad[1][j]*mb[m] <= s)
		{
			ci = i, cj = j;
			return 1;
		}
	}
	return 0;
}

int solve()
{
	int L = 0,R = n-1,res = -1;
	while(L<=R)
	{
		int m = (L+R)/2;
		if(yes(m))
		{
			res = m;
			R = m-1;
		}
		else L = m+1;
	}
	return res+1;
}


int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %d %d %d",&n,&m,&k,&s);
	for(int i=0;i<n;++i) scanf("%d",a+i);
	for(int i=0;i<n;++i) scanf("%d",b+i);
	int mna = a[0], mnb = b[0];
	for(int i=0;i<n;++i)
	{
		mna = min(mna,a[i]);
		mnb = min(mnb,b[i]);
		ma[i] = mna; mb[i] = mnb;
	}
	for(int i=0;i<m;++i)
	{
		int t,c;
		scanf("%d %d",&t,&c);
		gad[t-1].push_back(c);
		id[t-1].push_back(make_pair(c,i+1));
	}
	for(int z=0;z<2;++z)
	{
		gad[z].push_back(0);
		sort(gad[z].begin(),gad[z].end());
		sort(id[z].begin(),id[z].end());
		for(int i=1;i<gad[z].size();++i) gad[z][i] += gad[z][i-1];
	}
	int res = solve();
	if(!res) puts("-1");
	else
	{
		printf("%d\n",res);
		int ca,cb; ca = cb = -1;
		for(int i=0;i<n;++i)
		{
			if(ma[i] == ma[res-1])
			{
				ca = i+1;
				break;
			}
			if(mb[i] == mb[res-1])
			{
				cb = i+1;
				break;
			}
		}
		if(ca == -1) ca = res;
		else cb = res;
		for(int i=0;i<ci;++i) printf("%d %d\n",id[0][i].second,ca);
		for(int i=0;i<cj;++i) printf("%d %d\n",id[1][i].second,cb);
	}
	return 0;
}

