/*最大连续和*/
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn=123456;

int maxsum(int a[],int x,int y)	//a[],[x,y)
{
	if(y-x<=1) return a[x];
	int mx,m=x+(y-x)/2;  // mid
	mx=max(maxsum(a,x,m),maxsum(a,m,y));
	int v,L,R;
	v=0;L=a[m-1];
	for(int i=m-1;i>=x;--i) L=max(L,v+=a[i]);
	v=0;R=a[m];
	for(int i=m;i<y;++i) R=max(R,v+=a[i]);
	return max(mx,L+R);
}

int main()
{
	int n,a[maxn];
	cin>>n;
	for(int i=0;i<n;++i) cin>>a[i];
	cout<<maxsum(a,0,n)<<endl;
	return 0;
}

