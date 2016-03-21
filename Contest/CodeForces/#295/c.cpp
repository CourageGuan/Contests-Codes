//证明未知...
#include<cstdio>
#include<iostream>
using namespace std;

const int mod=1000000007;
int m[255];

int main()
{
	m['A']=0;
	m['T']=1;
	m['G']=2;
	m['C']=3;
	int n;
	int cnt[4]={0,0,0,0};
	scanf("%d",&n);
	getchar();
	for(int i=0;i<n;++i){
		char ch=getchar(); cnt[m[ch]]++;
	}
	int mx=0,m=0;
	for(int i=0;i<4;++i) mx=max(mx,cnt[i]);
	for(int i=0;i<4;++i) if(mx==cnt[i]) m++;
	long long ans=m;
	for(int i=1;i<n;++i) ans=(ans*m)%mod;
	cout<<ans<<endl;
}
