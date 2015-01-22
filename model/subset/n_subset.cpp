#include<cstdio>
using namespace std;

const int maxn=100;

void print(int n,int a[],int cur)
{
	for(int i=0;i<cur;++i) printf("%d ",a[i]);
	printf("\n");
	int s= cur ? a[cur-1]+1:0;
	for(int i=s;i<n;++i){
		a[cur]=i;
		print(n,a,cur+1);
	}
}

int main()
{
	int n,a[maxn];
	scanf("%d",&n);
	print(n,a,0);
	return 0;
}
