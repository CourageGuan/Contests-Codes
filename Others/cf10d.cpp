//LCIS
#include<stdio.h>
#include<string.h>

const int maxn=1000+10;
int f[maxn],lcis[maxn],a[maxn],b[maxn],prev[maxn];

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
					f[j]=k+1,prev[j]=p;
		}
	}
	int k=0,p=-1;
	for(int i=0;i<m;++i)
		if(f[i]>k) k=f[p=i];

	for(int i=k-1;i>=0;--i)
	{
		lcis[i]=b[p];
		p=prev[p];
	}

	return k;
}

int main()
{
	int n,m;
	scanf("%d",&n);
	for(int i=0;i<n;++i) scanf("%d",&a[i]);
	scanf("%d",&m);
	for(int i=0;i<m;++i) scanf("%d",&b[i]);
	int ans=LCIS(n,m);
	printf("%d\n",ans);
	for(int i=0;i<ans;++i){
		if(i) printf(" ");
		printf("%d",lcis[i]);
	}
	puts("");
	return 0;
}

