//http://main.edu.pl/en/archive/oi/16/kam
//poi 2009
#include<cstdio>
#include<cstring>

const int maxn = 1010;
int save[maxn];

int main()
{
	int T,n,x;
	//freopen("test.txt","r",stdin);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		int ans = 0;
		for(int i=1;i<=n;++i) scanf("%d",save+i); 
		for(int i=n;i>1;i-=2) ans ^= (save[i] - save[i-1]);
		if(n&1) ans ^= save[1];
		puts(ans?"TAK":"NIE");
	}
	return 0;
}
