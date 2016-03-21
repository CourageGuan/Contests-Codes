#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 4010;

int v[maxn],d[maxn],n;
LL p[maxn];
bool inque[maxn];


int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		scanf("%d %d %d",v+i,d+i,p+i);
		inque[i] = 1;
	}
	int cur = 0,cnt = 0;
	while(cur<n)
	{
		while(cur < n && !inque[cur]) ++cur;
		if(cur < n) ++cnt;
		else break;
		LL dec = v[cur];
		for(int i=cur+1;i<n;++i)
		{
			if(dec <= 0) break;
			if(!inque[i]) continue;
			p[i] -= dec;
			--dec;
		}
		dec = 0;
		for(int i=cur+1;i<n;++i)
		{
			if(!inque[i]) continue;
			p[i] -= dec;
			if(p[i] < 0)
			{
			   	inque[i] = 0;
				dec += d[i];
			}
		}
		++cur;
	}
	//for(int i=0;i<n;++i) printf("%d\n",p[i]);
	printf("%d\n",cnt);
	for(int i=0;i<n;++i) if(inque[i]) printf("%d%c",i+1,--cnt == 0?'\n':' ');
	return 0;
}
