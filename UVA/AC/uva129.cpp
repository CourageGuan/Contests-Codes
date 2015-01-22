#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int maxn=1000;
int ans[maxn];
int l,n,cnt,len; 

int solve(int cur)
{
	if(cnt++ == n){
		len=cur;
		return 0;
	}
	for(int i=0;i<l;++i){
		ans[cur]=i;
		bool flag=1;
		for(int j=1;2*j<=cur+1;++j){
			bool equal=1;
			for(int k=0;k<j;++k)
				if(ans[cur-k]!=ans[cur-k-j]) {equal=0;break;}
			if(equal) {flag=0;break;}
		}
		if(flag) if(!solve(cur+1)) return 0;
	}
	return 1;
}

void print()
{
	for(int i=0;i<len;++i){
		printf("%c",'A'+ans[i]);
		if((i+1)%(4*16)==0){
			printf("\n");
			continue;
		}
		if((i+1)%4==0 && i!=len-1){
			printf(" ");
		}
	}
	if(len%(4*16)!=0) printf("\n");
	cout<<len<<endl;
}

int main()
{
	//freopen("test","r",stdin);
	//freopen("1","w",stdout);
	while(scanf("%d%d",&n,&l)==2 && n){
		memset(ans,0,sizeof(ans));
		len=0;
		cnt=0;
		solve(0);
		print();
	}
	return 0;
}
