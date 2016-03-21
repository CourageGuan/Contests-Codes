#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=100;

int main()
{
	int n,p[maxn];
	scanf("%d",&n);
	for(int i=0;i<n;++i) scanf("%d",&p[i]);
	//sort(p,p+n);
	do{
		for(int i=0;i<n;++i) printf("%d ",p[i]);
		printf("\n");
	}while (next_permutation(p,p+n));
	return 0;
}

