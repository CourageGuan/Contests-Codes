#include<bits/stdc++.h>
using namespace std;

int n,k,N;

bool solve()
{
	if(k>(N+1)/2) return false;
	puts("YES");
	int cnt=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if((j-i+1)&1 && cnt<k){
				putchar('L');
				++cnt;
			}else putchar('S');
		}
		puts("");
	}
	return true;
}

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %d",&n,&k);
	N=n*n;
	if(!solve()) puts("NO");
	return 0;
}
