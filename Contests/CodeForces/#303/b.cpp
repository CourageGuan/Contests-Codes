#include<bits/stdc++.h>
using namespace std;

const int maxn=100010;
char s[maxn],t[maxn];
bool vis[maxn];

int main()
{
	memset(vis,0,sizeof vis);
	scanf("%s %s",s,t);
	int err,n=strlen(s);
	for(int i=0;i<n;++i){
		if(s[i]!=t[i]) ++err;
	}
	if(err&1){
		puts("impossible");	
		return 0;
	}
	for(int i=0;i<n;++i){
		if(s[i]!=t[i]  && err--) vis[i]=(err&1)?(s[i]=='1'):(t[i]=='1');
		else vis[i]=(s[i]=='1');
	}
	for(int i=0;i<n;++i){
	   	putchar(vis[i]?'1':'0');
	}
	puts("");
	return 0;
}
