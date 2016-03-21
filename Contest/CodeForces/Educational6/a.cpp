#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()
{
	//freopen("test.txt","r",stdin);
	int x,y,tx,ty;
	scanf("%d %d %d %d",&x,&y,&tx,&ty);
	printf("%d\n",max(abs(x-tx),abs(y-ty)));
	return 0;
}
