//裸的KMP
#include<cstdio>
#include<cstring>

const int maxm = 10010;
const int maxn = 1000010;
int f[maxm];
char P[maxm],T[maxn];

int find()
{
	int m = strlen(P);
	int n = strlen(T);
	int res = 0;
	int j = 0;
	for(int i=0;i<n;++i)
	{
		while(j && P[j]!=T[i]) j = f[j];
		if(P[j]==T[i]) ++j;
		if(j==m)
		{
			++res;
			j = f[j];
		}
	}
	return res;
}

void getFail()
{
	int m = strlen(P);
	f[0] = f[1] = 0;
	for(int i=1;i<m;++i)
	{
		int j = f[i];
		while(j && P[j]!=P[i]) j = f[j];
		f[i+1] = P[j] == P[i] ? j+1 : 0;
	}
}

int main()
{
	int kase;
	scanf("%d",&kase);
	while(kase--)
	{
		scanf("%s %s",P,T);
		getFail();
		printf("%d\n",find());	
	}
	return 0;
}


