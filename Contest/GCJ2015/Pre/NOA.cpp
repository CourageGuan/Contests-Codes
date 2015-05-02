#include<cstdio>

const int maxn=1000+10;
int a[maxn];

int main()
{
	freopen("./A-large.in","r",stdin);
	freopen("./a.out","w",stdout);
	int kase,T,S;
	scanf("%d",&T);
	while(T--){
		scanf("%d%*c",&S);
		for(int i=0;i<=S;++i){
		   	char ch=getchar();
			a[i]=ch-'0';
		}
		int cur,ans=0;
		cur=a[0];
		for(int i=1;i<=S;++i){
			if(i>cur){
				ans+=i-cur;
				cur=i;
			}
			cur+=a[i];
		}
		printf("Case #%d: %d\n",++kase,ans);
	}
	return 0;
}
