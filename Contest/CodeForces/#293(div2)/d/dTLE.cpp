/*组合数计算是瓶颈，TLE*/
#include<bits/stdc++.h>
using namespace std;

const int maxn=2000 +5;

inline double qpow(double a,int n)
{
	if(n==0) return 1;
	double x=qpow(a,n/2);
	double res=x*x;
	if(n&1) res=res*a;
	return res;
}

inline long long C(int m,int n)
{
	if(m==n || n==0) return 1;
	return C(m-1,n)+C(m-1,n-1);	
}

int main()
{
	//freopen("test","r",stdin);
	int n,t;double p,q,a[maxn],ans;
	memset(a,0,sizeof(a));
	scanf("%d %lf %d",&n,&p,&t);
	q=1-p;int m=min(t,n);
	for(int i=1;i<=m;++i){
		if(i<n){
			double cur=1;
			cur*=qpow(p,i);
			cur*=qpow(q,t-i);
			cur*=C(t,i);		
			a[i]=cur;
		}else{					//到达n时应考虑特殊情况
			for(int j=i;j<=t;++j){
				double cur=1;
				cur*=qpow(p,i);
				cur*=qpow(p,j-1);
				cur*=C(j-1,i-1);
				a[i]+=cur;
			}
		}
	}
	for(int i=1;i<=m;++i) ans+=i*a[i];
	printf("%.8lf\n",ans);
	return 0;
}


