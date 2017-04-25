#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 1010;

int n,m;
char s[maxn][maxn];
int cntx[maxn],cnty[maxn],sum;

int main()
{
	//freopen("test.txt","r",stdin);
	cin >> n >> m;
	sum = 0;
	for(int i=0;i<n;++i)
	{
		scanf("%s",s[i]);
		for(int j=0;j<m;++j)
		{
			if(s[i][j] == '*')
			{
				cntx[i]++;
				cnty[j]++;
				++sum;
			}
		}
	}
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
		{
			if(cntx[i] + cnty[j] - (s[i][j] == '*') >= sum)
			{
				puts("YES");
				printf("%d %d\n",i+1,j+1);
				return 0;
			}

		}
	puts("NO");
	return 0;
}
