#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;

const int maxm= 200000 +5;
int m,n;

struct DOOR{
	int a,b,o;
} door[maxm];

//前k个0，剩下为1，逻辑运算后的结果；
int re(int k)
{
	for(int i=1;i<=m;++i){
		int a=door[i].a,b=door[i].b;
		int va=a>0?door[a].o:-a>k;
		int vb=b>0?door[b].o:-b>k;
		door[i].o=!(va && vb);
	}
	return door[m].o;
}

void print(int l,int r,int t){
	for(int i=l;i<=r;++i) printf("%d",t);
}

int main()
{
	//freopen("test","r",stdin);
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&m);
		for(int i=1;i<=m;++i) scanf("%d %d",&door[i].a,&door[i].b);
		int v0=re(0);
		int vn=re(n);
		if(v0==vn) print(1,n,1);	//即任意输出一组无x解
		else{
			int l=1,r=n;
			while(l<r){
				int m=l+(r-l)/2;
				if(re(m)==vn) r=m;
				else l=m+1;
			}
			print(1,l-1,0);
			printf("x");
			print(l+1,n,1);
		}
		puts("");
	}
	return 0;
}

