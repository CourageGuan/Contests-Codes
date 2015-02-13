/*这道题细思恐极...
  找规律递推，复杂的为O(k) 设f(k,i)为k小时前i层的气球数 f(1,1)=1,f(k,0)=0;
 			2*f(k-1,i)					i<2^(k-1);
  f(k,i)= { 2*3^(k-1)						i=2^(k-1);
  			2*3^(k-1) + f(k-1,i-2^(k-1))	i>2^(k-1);
  */
#include<bits/stdc++.h>
using namespace std;


/*
int main()
{
	//freopen("test","r",stdin);
	int kase,cnt=1;
	scanf("%d",&kase);
	while(kase--){
		int n,a,b;
		scanf("%d%d%d",&n,&a,&b);
		long long ans=0;
		for(int i=a;i<=b;++i){
			int m=i,res=1,k=1<<n;
			while(k>1){
				if(m&1) res=res<<1;
				m=(m+1)/2;
				k=k>>1;
			}
			//cout<<res<<endl;
			ans+=res;
		}
		printf("Case %d: %lld\n",cnt++,ans);
	}
	return 0;
}*/


long long cal(int k,int i)
{
	if(i==0) return 0;
	if(k==0) return 1;
	long long res=0;
	if(i==1<<(k-1)) return 2*pow(3,k-1);
	if(i>(1<<(k-1))) res+=2*pow(3,k-1)+cal(k-1,i-(1<<(k-1)));
	else res+=2*cal(k-1,i);
	return res;
}

int main()
{
	int kase,cnt=1;
	scanf("%d",&kase);
	while(kase--){
		int k,a,b;
		scanf("%d%d%d",&k,&a,&b);
		printf("Case %d: %lld\n",cnt++,cal(k,b)-cal(k,a-1));
	}
	return 0;
}

