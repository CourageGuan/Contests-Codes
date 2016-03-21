/*贪心，每次取最大的找最小的匹配。*/
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn=100000+10;

int main()
{
	//freopen("test","r",stdin);
	int kase;
	scanf("%d",&kase);
	while(kase--){
		int n,bin,len[maxn],cnt=0;
		scanf("%d",&n);
		scanf("%d",&bin);
		for(int i=0;i<n;++i) scanf("%d",&len[i]);
		sort(len,len+n);
		int l=0,r=n-1;
		while(l<=r){
			//cout<<len[l]<<" "<<len[r]<<endl;
			if(l==r){
				cnt++;
				break;
			}
			if(len[l]+len[r]<=bin){
				cnt++;
				r--;l++;
			} 
			else{
				cnt++;
				r--;
			}
		}
		printf("%d\n",cnt);
		if(kase) puts("");
	}
	return 0;
}
