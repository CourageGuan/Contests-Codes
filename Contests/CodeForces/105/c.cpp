#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a));

const int maxn = 110;
int res[maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	int n,a,b;
	while(cin >> n >> a >> b)
	{
		int sum = 1,cur = 1,i=0,bg = 2;
		if(n == 1)
		{
			printf("%d\n",1);
			continue;
		}
		if(b != 0)
		{
			res[++i] = 1;
			F(j,1,b) 
			{
				cur = sum + 1;
				res[++i] = cur;
				sum += cur;
			}
		}
		else
		{
			res[++i] = 1;
			res[++i] = 1;
			cur = 1;
			bg = 3;
		}
		F(j,1,a)
		{
			++cur;
			res[++i] = cur;
		}
		F(j,bg,n-a-b) res[++i] = 1;
		bool flag = true;
		if(i != n) flag = false;
		F(i,1,n) if(res[i] > 50000)
		{
			flag = false;
			break;
		}
		if(!flag) puts("-1");
		else
		{
			int ta = 0,tb = 0,sum = res[1],mx = res[1];
			F(i,2,n)
			{
				if(res[i] > sum) ++tb;
				else if(res[i] > mx) ++ta;
				mx = max(mx,res[i]);
				sum += res[i];
			}
			if(ta != a || tb != b || i != n)
			{
				printf("%d %d %d\n",n,a,b);
				assert(0);
			}
			F(i,1,n) printf("%d ",res[i]);
		}
	}
	return 0;
}
