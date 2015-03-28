#include<bits/stdc++.h>
using namespace std;

const int maxn=2*100*100*10 + 10;
char s[maxn];
bool pos[maxn];

int main()
{
	scanf("%s",s+1);
	int l=strlen(s+1);
	int n,t;
	scanf("%d",&n);
	memset(pos,0,sizeof(pos));
	for(int i=0;i<n;++i){
		scanf("%d",&t);
		pos[t]^=1;
	}
	int yes=0;
	for(int i=1;i<=l/2;++i)
		if(pos[i]){
			if(!yes) swap(s[i],s[l-i+1]);
			yes^=1;
		}
		else if(yes) 
			swap(s[i],s[l-i+1]);
	printf("%s\n",s+1);
	return 0;
}
