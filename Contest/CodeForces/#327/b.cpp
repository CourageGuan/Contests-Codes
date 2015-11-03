#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 2e6 + 10;
char s[maxn];

char mp[255];

int main()
{
	//freopen("test.txt","r",stdin);
	int n,m;
	scanf("%d %d",&n,&m);
	scanf("%s",s);
	for(char i='a';i<='z';++i) mp[i] = i;
	for(int i=0;i<m;++i)
	{
		char s1[2],s2[2];
		scanf("%s %s",s1,s2);
		for(char i='a';i<='z';++i)
		{
			if(mp[i] == s1[0]) 
				mp[i] = s2[0];
			else 
				if(mp[i] == s2[0])
					mp[i] = s1[0];
		}
	}
	for(int i=0;i<n;++i) putchar(mp[s[i]]);
	puts("");
	return 0;
}
