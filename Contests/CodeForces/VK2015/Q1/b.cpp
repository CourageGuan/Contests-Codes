#include<bits/stdc++.h>
using namespace std;

const int maxn=1000+10;
vector<int> arr[maxn];
int p[maxn],que[2000000+10];

void init()
{
	for(int i=0;i<maxn;++i) arr[i].clear();
	memset(p,0,sizeof(p));
}

int main()
{
	int n,H,W;
	H=W=0;
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		int w,h;
		scanf("%d %d",&w,&h);
		H=max(H,h);
		W+=w;		
		arr[h].push_back(w);
		que[i]=h;
	}
	int h1=H;
	if(arr[H].size()==1)
		while(--h1) if(arr[h1].size()) break;
	for(int i=0;i<n;++i){
		int h=que[i],res;
		res=(W-arr[h][p[h]++])*(h==H?h1:H);
		if(i) printf(" ");
		printf("%d",res);	
	}
	puts("");
	return 0;
}

