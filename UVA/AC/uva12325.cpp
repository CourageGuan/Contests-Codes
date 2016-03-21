/*分类枚举*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
int n,s1,v1,s2,v2;


LL solve()
{
	LL ans=0;
	if(s1<s2){
		swap(s1,s2);
		swap(v1,v2);
	}
	if(n/s1<65536)
		for(LL i=0;i*s1<=n;++i){
			ans=max(ans,v1*i+(n-i*s1)/s2*v2);
		}
	else{
		for(LL i=0;i<=s1;++i){
			ans=max(ans,v2*i+(n-i*s2)/s1*v1);
		}
		for(LL i=0;i<=s2;++i){
			ans=max(ans,v1*i+(n-i*s1)/s2*v2);
		}
	}
	return ans;
}

int main()
{
	//freopen("test","r",stdin);
	int T;
	cin>>T;
	F(kase,1,T){
		printf("Case #%d: ",kase);
		scanf("%d%d%d%d%d",&n,&s1,&v1,&s2,&v2);
		printf("%lld\n",solve());
	}
}


