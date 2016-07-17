#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define mp make_pair

int q;
map<pair<LL,LL>,LL> G;

LL lca(LL u,LL v)
{
	if(u < v) swap(u,v);
//	printf("%lld %lld\n",u,v);
	while(__builtin_clzll(u) < __builtin_clzll(v)) u>>=1;
//	printf("..%lld %lld\n",u,v);
	while(u != v) u>>=1,v>>=1;
	return u;
}

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d",&q);
	G.clear();
	for(int i=0;i<q;++i)
	{
		int op;
		LL u,v;
		scanf("%d %lld %lld",&op,&u,&v);

		LL r = lca(u,v);

//		printf("%d\n",r);

		if(op == 1)
		{
			int w;
			scanf("%d",&w);

			while(u != r)
			{
				LL t = u>>1;
//				if(G.count(mp(t,u))) 
					G[mp(t,u)] += w,G[mp(u,t)] += w;
//				else
//					G[mp(t,u)] = G[mp(u,t)] = w;
				u = t;
			}
			while(v != r)
			{
				LL t = v>>1;
//				if(G.count(mp(t,v))) 
					G[mp(t,v)] += w,G[mp(v,t)] += w;
//				else
//					G[mp(t,v)] = G[mp(v,t)] = w;
				v = t;
			}
		}
		else
		{
			LL res = 0;
			while(u != r)
			{
				LL t = u>>1;
//				if(G.count(mp(t,u)))
					res += G[mp(t,u)];
				u = t;
			}
			while(v != r)
			{
				LL t = v>>1;
//				if(G.count(mp(t,v))) 
					res += G[mp(t,v)];
				v = t;
			}
			printf("%lld\n",res);
		}
	}
	return 0;
}

