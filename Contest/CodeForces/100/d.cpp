#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)

const int maxn = 110;

int n;
int a[maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d",&n);
	R(i,n) scanf("%d",a+i);
	sort(a,a+n);
	int cur = 0,tot = -1,res = 0;
	R(i,n)
	{
		if(cur + a[i] <= 710)
			cur += a[i];
		else
		{
			tot = i;
			break;
		}
	}
	if(tot == -1) tot = n;
	cur = 0;
	R(i,tot)
	{
		if(cur + a[i] <= 350)
			cur += a[i];
		else
		{
			a[i] -= 350 - cur;
			F(j,i,tot-1)
			{
//				printf("%d %d\n",tot-i-(j-i),a[j]);
				res += (tot-i-(j-i))*a[j];
			}
			break;
		}
	}
	printf("%d %d\n",tot,res);
	return 0;
}

