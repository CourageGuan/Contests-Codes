#include<bits/stdc++.h>
using namespace std;

typedef int LL;

vector<int> X,Y;

LL gcd(LL a,LL b)
{
    return !b?a:gcd(b,a%b);
}

LL lcm(LL a,LL b)
{
    return a/gcd(a,b)*b;
}

int res;

void dfs(LL x,LL y)
{

    res++;
    if(x == 1)
    {
        if(y % 2 == 0)
            dfs(x,y/2);

    }
    else if(y == 1)
    {
        if(x % 2 == 0)
            dfs(x/2,y);

    }
    else
    {
		for(int i=0;i<X.size();++i)
		{
			if(X[i] >= x) break;
			if(lcm(X[i],y)+X[i] == x) 
				dfs(X[i],y);
		}

		for(int i=0;i<Y.size();++i)
		{
			if(Y[i] >= y) break;
			if(lcm(Y[i],x)+Y[i] == y) 
				dfs(x,Y[i]);
		}
    }
}

int main()
{
    //freopen("./test.txt","r",stdin);
    int kase;
    scanf("%d",&kase);
    for(int z = 1;z <= kase;++z)
    {
		int x,y;
        scanf("%d %d",&x,&y);
		X.clear();
		Y.clear();
		for(int i=1;1LL*i*i<=x;++i)
		{
			if(x%i == 0)
			{
				X.push_back(i);
				if(x/i != i) X.push_back(x/i);
			}
		}
		for(int i=1;1LL*i*i<=y;++i)
		{
			if(y%i == 0)
			{
				Y.push_back(i);
				if(y/i != i) Y.push_back(y/i);
			}
		}
		sort(X.begin(),X.end());
		sort(Y.begin(),Y.end());
        res = 0;
        dfs(x,y);
        printf("Case #%d: %d\n",z,res);
    }
    return 0;
}
