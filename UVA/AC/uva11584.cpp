// d[i] 表示0~i划分最少的回文串
// d[i]=min{d[j]+1|s[j+1...i]是回文串}
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cctype>
using namespace std;

const int maxn=1000 + 10;
const int INF=0x3f3f3f3f;
int b[maxn][maxn];

int solve(char s[])
{
	memset(b,0,sizeof(b));
	int n=strlen(s);
	for(int i=0;i<n;++i){
		b[i+1][i+1]=1;
		for(int j=1; i+j<n && i-j>=0 ;++j)
			if(s[i-j]==s[i+j]) b[i-j+1][i+j+1]=1;
			else break;
        for(int j=1; i+j<n && i-j+1>=0 ;++j)
            if(s[i-j+1]==s[i+j]) b[i-j+1+1][i+j+1]=1;
            else break;
	}
	int d[maxn];
	for(int i=1;i<=n;++i) d[i]=i;
	for(int i=1;i<=n;++i)
		for(int j=0;j<i;++j)
			if(b[j+1][i]){
				d[i]=min(d[i],d[j]+1);
				//cout<<i<<" "<<d[i]<<endl;
            }

	return d[n];
}

int main()
{
    //freopen("test","r",stdin);
	int T;
	char s[maxn];
	scanf("%d",&T);
	while(T--){
		scanf("%s",s);
		printf("%d\n",solve(s));
	}
}

