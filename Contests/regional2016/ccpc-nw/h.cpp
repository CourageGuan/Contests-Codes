#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

const int maxn = 1010;
const int mid = maxn/2;
int L,R,rev,n;
int a[maxn];
int T;

int cal(int a,int b)
{
	return !(a&b);
}

int main()
{
	//freopen("input.txt","r",stdin);
	int T;
	scanf("%d",&T);
	F(z,1,T)
	{
		L = R = mid;
		rev = 0;
		scanf("%d",&n);
		printf("Case #%d: \n",z);
		F(q,1,n)
		{
			char op[20];
			scanf("%s",op);
			if(op[0] == 'P')
			{
				if(op[1] == 'U')
				{
					int x;
					scanf("%d",&x);
					if(!rev)
					{
						a[--L] = x;
					}
					else
					{
						a[R++] = x;
					}
				}
				else
				{
					if(L >= R) puts("Invalid.");
					else
					{
						if(!rev)
						{
							++L;
						}
						else
						{
							--R;
						}
					}
				}
			}
			else if(op[0] == 'Q')
			{
				if(L >= R) puts("Invalid.");
				else
				{
					int res = 0;
					if(!rev)
					{
						res = a[L];
						F(i,L+1,R-1)
						{
							res = cal(res,a[i]);
						}
					}
					else
					{
						res = a[R-1];
						for(int i=R-2;i>=L;--i)
						{
							res = cal(res,a[i]);
						}
					}
					printf("%d\n",res);
				}
			}
			else if(op[0] == 'R')
			{
				rev ^= 1;
			}
		}
	}
    return 0; 
}
