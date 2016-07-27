#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof (a))

int n; 
int a[110];

pair<int,int> p[110];


int main()
{
	//freopen("test.txt","r",stdin);
	int sum = 0;
	cin >> n;
	F(i,1,n) scanf("%d",a+i),p[i] = make_pair(a[i],i);
	sort(p+1,p+1+n);
	F(i,1,n/2)
		printf("%d %d\n",p[i].second,p[n-i+1].second);
	return 0;
}
