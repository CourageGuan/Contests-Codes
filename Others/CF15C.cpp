#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<set>
#include<vector>
#include<map>
using namespace std;

#define REP(i,n) for(int i=0;i<n;++i)
#define F(i,a,b) for(int i=a;i<=b;++i)
#define Fd(i,a,b) for(int i=a;i>=b;--i)
typedef long long ll;

ll Xor(ll n)
{
	switch(n%4){	
		case 0:return n;
		case 1:return 1;
		case 2:return n+1;
		case 3:return 0;
	}
}

int main()
{
	//freopen("test.txt","r",stdin);
	int n;	
	scanf("%d",&n);
	ll res=0,x,m;
	REP(i,n){
		scanf("%lld %lld",&x,&m);
		res^=Xor(x-1)^Xor(x+m-1);
	}
	puts(res?"tolik":"bolik");
	return 0;
}

