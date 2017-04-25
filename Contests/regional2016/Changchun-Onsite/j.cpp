#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

const int maxn = 2010;
int lena,it;
char s[maxn],a[maxn],b[maxn],ans[maxn][maxn];

void print(char s[])
{
	int len = strlen(s) - 1;
	while(s[len] == '0') --len;
	while(len >= 0) putchar(s[len--]);
	puts("");
}

bool judge(char s[],int len)
{
	int i=0,j=len-1;
	while(i < j) if(s[i++] != s[j--]) return 0;
	return 1;
}

void get()
{
	if(s[lena-1] <= '1' && s[0] < '1')
	{
		F(i,0,lena-2) b[i] = '9';
		b[lena-1] = '\0';
		return ;
	}
	int i=0,j=lena-1;
	while(i <= j)
	{
		if(s[i] >= s[j]) b[i] = b[j] = s[j];
		else b[i] = b[j] = s[j] - 1;
		++i;
		--j;
	}
	b[lena] = '\0';
}

void dec(char b[])
{
	int lenb = strlen(b),lo = 0;
	F(i,0,lenb-1)
	{
		if(s[i] >= b[i])
			s[i] = '0' + s[i] - b[i];
		else
		{
			s[i] = '0' + s[i] + 10 - b[i];
			s[i+1] -= 1;
		}
	}
	while(lena && s[lena-1] == '0') --lena;
}

int main()
{
	//freopen("test.txt","r",stdin);
	int T;
	scanf("%d",&T);
	F(z,1,T)
	{
		scanf("%s",s);
		memcpy(a,s,sizeof a);
		lena = strlen(s);
		reverse(s,s+lena);
		while(s[lena-1] == '0') --lena;
		it = 0;
		printf("Case #%d:\n",z);
		while(1)
		{
			if(judge(s,lena))
			{
			   	memcpy(ans[it++],s,sizeof (ans[0]));
				break;
			}
			get();
			memcpy(ans[it++],b,sizeof (ans[0]));
			dec(b);
			if(!lena) break;
		}
		assert(it <= 50);
		printf("%d\n",it);
		F(i,0,it-1)
		{
			print(ans[i]);
			//int len = strlen(ans[i]) - 1;
			//while(ans[i][len] == '0') --len;
			//assert(!judge(ans[i],len+1));
		}
	}
	return 0;
}
