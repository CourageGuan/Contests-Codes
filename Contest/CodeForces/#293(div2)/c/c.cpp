#include<bits/stdc++.h>
using namespace std;

const int maxn=100000 + 5;
int a[maxn],pos[maxn];

int main()
{
	//freopen("test","r",stdin);
	int n,m,k;
	long long ans=0;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<n;++i){
		scanf("%d",&a[i]);
		pos[a[i]]=i;
	}
	ans+=m;
	for(int i=0;i<m;++i){
		int op;
		scanf("%d",&op);
		if(pos[op]){
			ans+=pos[op]/k;
			swap(a[pos[op]],a[pos[op]-1]);
			pos[a[pos[op]]]=pos[op];
			pos[op]-=1;
		}
	}
	cout<<ans<<endl;
	return 0;
}
