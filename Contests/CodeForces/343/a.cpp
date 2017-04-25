#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 110;
char s[maxn][maxn];
int n;

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d",&n);
	for(int i=0;i<n;++i) scanf("%s",s[i]);
	LL res = 0;
	for(int i=0;i<n;++i)
	{
		LL cnt = 0;
		for(int j=0;j<n;++j)
			if(s[i][j] == 'C') ++cnt;
		cnt = cnt*(cnt-1)/2;
		res += cnt;
	}
	for(int i=0;i<n;++i)
	{
		LL cnt = 0;
		for(int j=0;j<n;++j)
			if(s[j][i] == 'C') ++cnt;
		cnt = cnt*(cnt-1)/2;
		res += cnt;
	}
	printf("%d\n",res);
	return 0;
}
