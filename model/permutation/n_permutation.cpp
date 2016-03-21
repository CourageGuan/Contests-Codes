#include<cstdio>
using namespace std;

const int maxn=100;

void print(int n,int a[],int cur)
{
	if(cur==n){
		for(int i=0;i<n;++i) printf("%d",a[i]);
		printf("\n");
	}else
		for(int i=1;i<=n;++i){
			bool flag=true;
			for(int j=0;j<=cur;++j)
				if(a[j]==i) flag=false;
			if(flag){
				a[cur]=i;
				print(n,a,cur+1);
			}
		}
}


int main()
{
	int n,a[maxn];
	scanf("%d",&n);
	print(n,a,0);
	return 0;
}
