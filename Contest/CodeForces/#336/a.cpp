#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 1010;
int fl[maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	int n,s,f,t,T = 0;
	scanf("%d %d",&n,&s);
	memset(fl,0,sizeof fl);
	for(int i=0;i<n;++i)
	{
		scanf("%d %d",&f,&t);
		fl[f] = max(fl[f],t);
	}
	for(int i = s;i>=0;--i)
	{
		T = max(T,fl[i]);
		if(i) T += 1;
	}
	printf("%d\n",T);
	return 0;
}
