#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 110;
char s[maxn][maxn*10];

int main()
{
	//freopen("test.txt","r",stdin);
	int n;
	scanf("%d",&n);
	int ans = 0;
	for(int i=0;i<n;++i)
	{
		scanf("%s",s[i]);
	}
	for(int i=0;i<26;++i)
		for(int j=i+1;j<26;++j)
		{
			int res = 0;
			for(int t=0;t<n;++t)
			{
				int cnt = 0;
				bool flag = true;
				for(int k=0;k<strlen(s[t]);++k)
				{
					if(s[t][k] !=i+'a' && s[t][k] != j+'a' ) {flag =false;break;}
				}
				if(flag) res += strlen(s[t]);
			}
			ans = max(ans,res);
		}
	printf("%d\n",ans);
	return 0;
}
