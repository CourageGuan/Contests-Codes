#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 1e5 + 10;
char s[maxn];
int a[maxn],res[maxn],n;
int first;
int d[maxn][2][2];

bool dfs(int l,int r,int curl,int curr)
{
	if(curr >= 2) return false;
//	printf("%d %d %d %d\n",l,r,curl+a[l],a[r]-curr);
	int &ans = d[r][curl==10][curr];
	if(ans!=-1) return ans;
	if(r+1 >= l)
	{
		if(l == r)
		{
			curl += a[l];
			if(curr) --curl;
			if(curl&1) return false;
			res[l] = curl/2;
			return true;
		}
		else
		{
			curl += a[l];
			curr = a[r] - curr;
			if(curl < 10)
			{
				if(curr != curl) return false;
				res[l] = (curl+1)/2;
				res[r] = curl/2;
				if(first && res[l] == 0) return false;
				return true;
			}
			else
			{
				if(curr != (curl%10)-1) return false;
				res[l] = curl/2;
				res[r] = (curl-1)/2;
				return true;
			}
		}
		return false; 
	}
	int end = 0+first,flag = 0;
	first = 0;
	curl += a[l];
	curr = a[r] - curr; 
	if(curr == -1)
	{
		curr = 9;
		flag = 1;
	}
	for(int i=9;i>=end;--i)
	{
		int j = curl - i;
		if(curl%10 == curr && j>=0 && j<10)
		{
			if(dfs(l-1,r+1,0,(i+j>=10?1:0)+flag))
			{
				res[l] = i; 
				res[r] = j;
				return ans = 1;
			}
		}
		--j;
		if((curl-1)%10 == curr && j>=0 && j<10)
		{
			if(dfs(l-1,r+1,10,(i+j>=10?1:0)+flag))
			{
				res[l] = i; 
				res[r] = j;
				return ans = 1;
			}
		}
	}
	return ans = 0;
}

bool solve()
{
	if(n == 1)
	{
		if(a[n]&1) putchar('0');
		else putchar('0'+a[n]/2);
		puts("");
		return true;
	}
	first = 1;
	memset(d,-1,sizeof d);
	if(dfs(n,1,0,0))
	{
		for(int i=n;i>=1;--i) printf("%d",res[i]);
		puts("");
		return true;
	}
	first = 1;
	memset(d,-1,sizeof d);
	if(dfs(n-1,1,10,0))
	{
		for(int i=n-1;i>=1;--i) printf("%d",res[i]);
		puts("");
		return true;
	}
	return false;
}

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%s",s);
	n = strlen(s);
	for(int i=0;i<n;++i) a[n-i] = s[i] - '0';
	if(!solve()) puts("0");
	return 0;
}

