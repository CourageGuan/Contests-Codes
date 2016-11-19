#include<cstdio>
#include<cstring>
#include<algorithm>

const int maxn = 1010;
int n,m,k;
int ans[maxn];
int op[maxn],a[maxn],b[maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	while(scanf("%d %d %d",&n,&m,&k) == 3)
	{
		for(int i=0;i<k;++i)
		{
			char s[2];
			scanf("%s",s);
			if(s[0] == 'g') op[i] = 0,scanf("%d",a+i);
			if(s[0] == 's') op[i] = 1,scanf("%d %d",a+i,b+i);
			if(s[0] == 'e') op[i] = 2,scanf("%d",a+i);
		}
		memset(ans,0,sizeof ans);
		for(int z=0;z<m;++z) for(int i=0;i<k;++i)
		{
			if(op[i] == 0)
			{
				ans[a[i]]++;
			}
			if(op[i] == 1)
			{
				std::swap(ans[a[i]],ans[b[i]]);
			}
			if(op[i] == 2)
			{
				ans[a[i]] = 0;
			}
		}
		for(int i=1;i<=n;++i) printf("%d ",ans[i]);
		puts("");
	}
	return 0;
}
