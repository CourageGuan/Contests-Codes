#include<bits/stdc++.h>
using namespace std;

const int maxn=2<<12;
int n;
int a[maxn];

int main()
{
	//freopen("test","r",stdin);
	scanf("%d",&n);	
	long long ans=0;
	for(int i=2;i<(1<<(n+1));++i) scanf("%d",&a[i]);
	for(int i=(1<<(n+1))-1;i>=3;i-=2){ 
		ans+=abs(a[i]-a[i-1]);
		a[i/2]+=max(a[i],a[i-1]);
	}
	cout<<ans<<endl;
	return 0;
}
