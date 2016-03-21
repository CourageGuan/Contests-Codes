#include<cstdio>
using namespace std;

const int maxn=100;

void print(int n,int p[],int a[],int cur)
{
	if(cur==n){
		for(int i=0;i<n;++i)
			printf("%d ",a[i]);
		printf("\n");
	}else
		for(int i=0;i<n;++i)
			if(!i || p[i]!=p[i-1]){
			int c1,c2;
			c1=c2=0;
			for(int j=0;j<cur;++j) if(a[j]==p[i]) c1++;
			for(int j=0;j<n;++j) if(p[i]==p[j]) c2++;
			if(c1<c2){
				a[cur]=p[i];
				print(n,p,a,cur+1);
			}
		}
}

int main()
{
	int n,p[maxn],a[maxn];
	scanf("%d",&n);
	for(int i=0;i<n;++i)
		scanf("%d",&p[i]);
	print(n,p,a,0);
	return 0;
}

