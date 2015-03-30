//LCIS
#include<stdio.h>
#include<string.h>

const int maxn=1000+10;
int a[maxn],b[maxn],f[maxn];

int LCIS(int n,int m)
{
	memset(f,0,sizeof(f));
	for(int i=0;i<n;++i){
		int k=0,p=-1;
		for(int j=0;j<m;++j){
			if(a[i]>b[j])
				if(f[j]>k)
					k=f[p=j];
			if(a[i]==b[j])
				if(f[j] < k+1)
					f[j]=k+1;
		}
	}
	int k=0,p=-1;
	for(int i=0;i<m;++i)
		if(f[i]>k) k=f[p=i];

	return k;
}

int main()
{
	int T,n,m;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;++i) scanf("%d",&a[i]);
		scanf("%d",&m);
		for(int i=0;i<m;++i) scanf("%d",&b[i]);
		printf("%d\n",LCIS(n,m));
	}
	return 0;
}

