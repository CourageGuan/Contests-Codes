#include<cstdio>
#include<cstring>
using namespace std;

const int maxn=100;

void print(int n,int a[],int p[],int cur)
{
	if(cur==n){
		for(int i=0;i<n;++i)
			if(a[i]) printf("%d ",p[i]);
		printf("\n");	
		return;
	}
	a[cur]=1;
	print(n,a,p,cur+1);
	a[cur]=0;
	print(n,a,p,cur+1);
}

int main()
{
	int n,a[maxn],p[maxn];
	memset(a,0,sizeof(a));
	scanf("%d",&n);
	for(int i=0;i<n;++i)
		scanf("%d",&p[i]);
	print(n,a,p,0);
	return 0;
}

