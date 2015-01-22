#include<cstdio>
const int maxn=100;
int n;

void print(int i,int p[])
{
	int j=0;
	while(j<n){
		if(i&1) printf("%d ",p[j]);
		j++;i=i>>1;
	}
	printf("\n");
}

int main()
{
	int n,p[maxn];
	scanf("%d",&n);
	int ALL_BITS=(1<<n)-1;
	// A&B 交集  A|B 并集  A^B 对称差集(只存在于A和只存在于B的元素)  ALL_BITS^A 补集
	for(int i=0;i<n;++i) scanf("%d",&p[i]);
	for(int i=0;i<(1<<n);++i)
		print(i,p);
	return 0;
}

