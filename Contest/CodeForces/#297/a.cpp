#include<bits/stdc++.h>
using namespace std;

int mp[255];


int main()
{
	int n;
	scanf("%d%*c",&n);
	int m=2*n-2,ans=0;
	memset(mp,0,sizeof(mp));
	for(int i=1;i<=m;++i)
		if(i&1) mp[getchar()]++;
		else {
			char c=getchar()+32;
			if(mp[c]) --mp[c];
			else ++ans;
		}
	printf("%d\n",ans);
	return 0;
}	
