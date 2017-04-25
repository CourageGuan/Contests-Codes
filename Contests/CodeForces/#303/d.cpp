#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn=100010;
int save[maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i) scanf("%d",save+i);
	sort(save,save+n);
	int cnt=1;
	LL cur=save[0];
	for(int i=1;i<n;++i){
		if(save[i]>=cur){
		   	++cnt;
			cur+=save[i];
		}
	}
	printf("%d\n",cnt);
	return 0;
}
