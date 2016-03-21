#include<bits/stdc++.h>
using namespace std;

typedef unsigned int UI;
typedef long long LL;

const int maxn = 1e6 + 2;

UI vis[(maxn+31)/32 + 5];
int pri[100000];
int n,tot;

void init()
{
	int n = maxn;
	tot = 0;
	memset(vis,0,sizeof vis);
	for(int i=2;i<n;++i)
	{
		if(!(vis[i/32]&(1<<(i%32)))) pri[tot++] = i;
		for(int j=0;j<tot;++j)
		{
			 LL t = (LL)i*pri[j];
			 if(t > n) break;
			 vis[t/32] |= (1<<(t%32));
			 if(i % pri[j] == 0) break;
		}
	}
//	printf("%d\n",tot);
}

bool witness(LL a,LL n)  
{  
    LL t,d,x;  
    d=1;  
    int i=ceil(log(n-1.0)/log(2.0)) - 1;  
    for(;i>=0;i--)  
    {  
        x=d;  d=(d*d)%n;  
        if(d==1 && x!=1 && x!=n-1) return true;  
        if( ((n-1) & (1<<i)) > 0)  
            d=(d*a)%n;  
    }  
    return d==1? false : true;  
}  

bool miller_rabin(LL n)  
{  
    if(n==2)    return true;  
    if(n==1 || ((n&1)==0))    return false;  
    for(int i=0;i<50;i++){  
        LL a=rand()*(n-2)/RAND_MAX +1;  
        if(witness(a, n))    return false;  
    }  
    return true;  
}  

bool judge(int n)
{
	for(int i=2;i*i<=n;++i)
		if(n%i==0) return false;
	return true;
}

int main()
{
	init();
	while(scanf("%d",&n)==1)
	{
		if(n==3) puts("1\n3");
		else if(n==5) puts("1\n5");
		else
		{
			puts("3");
			for(int i=1;i<tot;++i)
			{
				int t = (n - pri[i])/2;
				if(t>maxn)
				{
					if(miller_rabin(t))
					{
						printf("%d %d %d\n",pri[i],t,t);
						break;
					}
				}
				else
				{
					if(judge(t))
					{
						printf("%d %d %d\n",pri[i],t,t);
						break;
					}
				}
			}
		}
	}
	return 0;
}

