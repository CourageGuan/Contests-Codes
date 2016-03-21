#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn =  2e5 + 10;
char a[maxn],b[maxn];
int res[maxn][2];


int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%s %s",a,b);
	int na = strlen(a),nb = strlen(b);
	for(int i=0;i<=nb-na;++i) 
		if(b[i]-'0') ++res[0][0];
		else ++res[0][1];
	LL ans = res[0][a[0]-'0'];
	for(int i=1;i<na;++i)
	{
		res[i][0] = res[i-1][0];
		res[i][1] = res[i-1][1];
		if(b[i-1]-'0') --res[i][0];
		else --res[i][1];
		if(b[i+(nb-na)]-'0') ++res[i][0];
		else ++res[i][1];
		ans += res[i][a[i]-'0'];
	}
	printf("%lld\n",ans);
	return 0;
}
