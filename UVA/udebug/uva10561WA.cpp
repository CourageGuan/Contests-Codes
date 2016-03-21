#include<cstdio>
#include<cstring>

const int maxn=1000;
int n;

bool yes(int k,bool vis[])
{
	for(int i=0;i<n;++i)
	   	if(vis[i] && vis[i+1] && vis[i+2]) return 1;
	for(int i=0;i<n;++i) 
		if(vis[i] && (vis[i+1] || vis[i+2])) return 0;
	for(int i=0;i<n;++i)
	   	if(!vis[i]){
			vis[i]=1;
			if(yes(i,vis)){
				vis[i]=0;
			   	return 0;
			}
			vis[i]=0;
		}
	return 1;
}

int main()
{
	//freopen("test.txt","r",stdin);
	int T;
	scanf("%d",&T);
	char s[maxn];
	bool vis[maxn];
	while(T--){
		scanf("%s",s);
		n=strlen(s);
		memset(vis,0,sizeof vis);
		for(int i=0;i<n;++i)
			vis[i]=(s[i]=='.')?0:1;
		int first=0;
		for(int i=0;i<n;++i)
			if(!vis[i]){
				vis[i]=1;
				if(yes(i,vis)){
					if(first++) printf(" ");
					else puts("WINNING");
					printf("%d",i+1);
				}
				vis[i]=0;
			}
		if(!first) puts("LOSING");
		puts("");
	}
	return 0; 
}

