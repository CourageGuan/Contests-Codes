#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,x;
	scanf("%d %d",&n,&x);
	int ans=0,cur=0,tr=1;
	while(n--){
		int l,r;
		scanf("%d %d",&l,&r);
		ans+=(l-tr)%x+(r-l+1);
		tr=r+1;
	}
	printf("%d\n",ans);
	return 0;
}
