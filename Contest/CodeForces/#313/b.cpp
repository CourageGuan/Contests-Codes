#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 2e5 + 10;
char s1[maxn],s2[maxn];
int sum1[maxn],sum2[maxn];
int n;

bool check(int l1,int r1,int l2,int r2)
{
	if((r1 - l1)&1)
	{
		if(sum1[r1+1] - sum1[l1] != sum2[r2+1] - sum2[l2]) return false;
		int m1 = (l1+r1)>>1,m2 =(l2+r2)>>1;
		return (check(l1,m1,l2,m2) && check(m1+1,r1,m2+1,r2)) || (check(l1,m1,m2+1,r2) && check(m1+1,r1,l2,m2)); 
	}
	else
	{
		int p1 = l1,p2 = l2;
		while(p1 <= r1)
		{
			if(s1[p1] != s2[p2]) return false;
			++p1;
			++p2;
		}
		return true;
	}
}

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%s %s",s1,s2);
	n = strlen(s1);
	sum1[0] = sum2[0] = 0;
	for(int i=0;i<n;++i)
	{
		sum1[i+1] = sum1[i] + s1[i] - 'a';
		sum2[i+1] = sum2[i] + s2[i] - 'a';
	}
	puts(check(0,n-1,0,n-1)?"YES":"NO");
	return 0;
}
