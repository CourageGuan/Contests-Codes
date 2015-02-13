/*带权中位数*/
#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=15000+5;

struct position{
	int x,p;
	bool operator <(const position b) const{
		return x<b.x;
	}
} pos[maxn];

int main()
{
	int n,sum=0;
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d %d",&pos[i].x,&pos[i].p);
		sum+=pos[i].p;
	}
	sort(pos,pos+n);
	int ave=(sum+1)/2,cur=0;
	int i;
	for(i=0;i<n;++i){
		cur+=pos[i].p;
		if(cur>=ave) break;
	}
	printf("%.5f\n",(double)pos[i].x);
	return 0;
}
