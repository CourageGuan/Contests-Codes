#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))

int main()
{
	int a,b,t[3];
	fill(t,0);
	scanf("%d%d",&a,&b);
	R(i,6) 
	{
		if(abs(i+1 - a) < abs(i+1 - b)) ++t[0];
		else if(abs(i+1 - a) == abs(i+1 - b)) ++t[1];
		else ++t[2];
	}
	R(i,3) printf("%d ",t[i]);
	return 0;
}
