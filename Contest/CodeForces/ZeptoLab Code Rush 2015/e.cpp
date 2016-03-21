#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=1e6+10;
int a[maxn*3];
ll p[maxn*3];
int n,q;

int solve(ll t)
{
	int cnt=0,i=1,len=n,st=-1;
	while(i<=n){
		int j=i;
		ll cur=0;
		while(j<=2*n && a[j]+cur<=t) cur+=a[j++];
		if(j-i<len) len=j-i,st=i;	//找到一个最短的区间
		i=j;
		++cnt;
	}
	int res=cnt;
	for(int i=st;i<=st+len;++i){	//将区间的每一个元素作为起点计算一次
		if(i>=2*n) break;
		cnt=0;
		int k=0;
		while(k<=n){
			int r=k;
			r+=len;
			ll cur=0;
			while(r<=n && p[r+i]-p[k+i]<=t) cur=p[r+i]-p[k+i],++r;
			k=r;			
			++cnt;
		}
		res=min(cnt,res);
	}
	return res;
}

ll nextInt()
{
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	ll res=0;
	while(isdigit(c)){
		res=res*10+c-'0';
		c=getchar();
	}
	return res;
}

ll write(ll x)
{
	if(x>9) write(x/10);
	putchar(x%9+'0');
}

int main()
{
	freopen("test","r",stdin);
	n=nextInt();
	q=nextInt();
	ll sum=0;
	for(int i=1;i<=n;++i){
		a[i]=nextInt();
		sum+=a[i];
		a[2*n+i]=a[i+n]=a[i];
	}
	p[0]=0;
	for(int i=1;i<=3*n;++i) p[i]=p[i-1]+a[i];
	ll t;
	while(q--){
		t=nextInt();
		if(t>=sum){
		   	puts("1");
			continue;
		}
		write(solve(t));
		putchar('\n');
	}
	return 0;
}


