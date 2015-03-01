#include<cstdio>
#include<iostream>
using namespace std;

int main()
{
	int n,m,ans=0;
	scanf("%d %d",&n,&m);
	while(n && m && m+n>=3)
		if(m>n){
			ans++;
			m-=2;
			--n;
		}
		else{
			ans++;
			n-=2;
			--m;
		}
	printf("%d\n",ans);
	return 0;
}
