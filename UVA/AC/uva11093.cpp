/*贪心，每次从油量不足的下一个点开始扫描，直到满足条件，注意扫描起点要保证一直递增*/
#include<iostream>
#include<cstdio>
using namespace std;

const int maxn=100001+5;
int pe[maxn],wa[maxn];

int main()
{
	//freopen("test","r",stdin);
	int T,kase=1;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;++i) scanf("%d",&pe[i]);
		for(int i=0;i<n;++i) scanf("%d",&wa[i]);
		int cur,pos,cnt,beg=0;
		bool yes;
		while(1){
			yes=true;pos=-1;cur=0;cnt=0;
			for(int i=beg;cnt++<n;i=(i+1)%n){
				beg=(i+1>beg)?i+1:beg;
				cur+=pe[i];
				cur-=wa[i];
				if(cur<0){
					yes=false;
					break;
				}else if(pos==-1) pos=i;
			}
			//cout<<beg<<" "<<cnt<<endl;
			if(yes || beg>=n ) break;
		}
		printf("Case %d: ",kase++);
		if(!yes) puts("Not possible");
		else printf("Possible from station %d\n",pos+1);
	}
	return 0;
}

