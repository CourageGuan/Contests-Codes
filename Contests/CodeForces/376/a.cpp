#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define F(i,a,b) for(int i=(a);i<=(b);++i)


int get(int a,int b)
{
	int t = abs(b-a);
	return min(t,26-t);
}

int main()
{
//	freopen("input.txt","r",stdin);
	char s[110];
	scanf("%s",s+1);
	s[0] = 'a';
	int n = strlen(s),ans = 0;
	F(i,1,n-1)
	{
		ans += get(s[i],s[i-1]);
	}
	printf("%d\n",ans);
	return 0;
}
