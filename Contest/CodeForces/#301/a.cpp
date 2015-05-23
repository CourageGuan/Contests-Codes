#include<bits/stdc++.h>
using namespace std;

const int maxn=310;
vector<char> ans[maxn];
bool vis[maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	int n;
	char s[maxn];
	scanf("%d",&n);
	scanf("%s",s);
	int len=strlen(s);
	if(n>len){
	   	puts("NO");
		return 0;
	}
	memset(vis,0,sizeof vis);
	int i=0,k=-1;
	for(i=0;i<len;++i){
		if(!vis[s[i]]){
			vis[s[i]]=1;
		   	++k;
		}
		if(k>=n-1) break;
		ans[k].push_back(s[i]);
	}
	if(k<n-1) puts("NO");
	else{
		puts("YES");
		for(int t=0;t<k;++t){
			for(int j=0;j<ans[t].size();++j)
				printf("%c",ans[t][j]);
			puts("");
		}
		if(i<len){
			printf("%s\n",s+i);
		}
	}
	return 0;
}

