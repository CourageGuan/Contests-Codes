#include<stdio.h>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;

const int maxd = 61;
LL B[maxd],D[maxd],len[maxd];

void init()
{
	B[1] = D[1] = len[1] = 1;
	for(int i=2;i<maxd;++i)
	{
		len[i] = 2*len[i-1] + 1;
		B[i] = B[i-1] + (len[i-1] - B[i-1]) + 1;
	}
}

LL cal(LL x)
{
	if(x == 0) return 0;
	if(x == 1) return 1;
	int p = lower_bound(len,len+maxd,x) - len;
	if(len[p] == x) return B[p];
	if(x >= len[p-1]+ 1 + (len[p-1]/2 + 1))
		return B[p-1] + cal(x-len[p-1]-1);
	return B[p-1] + cal(x - len[p-1]-1) + 1;
}


int main()
{
	//freopen("test.txt","r",stdin);
	init();
	int T;
	scanf("%d",&T);
	while(T--)
	{
		LL L,R;
		cin >> L >> R;
		cout << cal(R) - cal(L-1) << '\n';	
	}
	return 0;
}
