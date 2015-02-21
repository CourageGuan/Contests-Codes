/*学了一个从两边向中间枚举，把最坏情况降到O(n/2) */
#include<cstdio>
#include<map>

const int maxn=200000+5;
int a[maxn],prev[maxn],next[maxn];

std::map<int,int> cur;

inline bool unique(int p,int l,int r){
	return prev[p]<l && next[p]>r;
}

bool solve(int x,int y)
{
	if(x>=y) return 1;
	for(int d=0;x+d<=y-d;++d){
		if(unique(x+d,x,y)) return solve(x,x+d-1) && solve(x+d+1,y);
		else if((x+d!=y-d) && unique(y-d,x,y)) return solve(x,y-d-1) && solve(y-d+1,y);
	}
	return 0;
}

int main()
{
	//freopen("test","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		cur.clear();
		scanf("%d",&n);
		for(int i=0;i<n;++i){
			scanf("%d",&a[i]);
			if(!cur.count(a[i])) prev[i]=-1;
			else prev[i]=cur[a[i]];
			cur[a[i]]=i;
		}
		cur.clear();
		a[n]=-1;
		bool flag=true;
		for(int i=n-1;i>=0;--i){
			if(a[i]==a[i+1]){
				flag=false;
				break;
			}
			if(!cur.count(a[i])) next[i]=n;
			else next[i]=cur[a[i]];
			cur[a[i]]=i;
		}
		if(!flag){
			puts("boring");
			continue;
		}
		puts(solve(0,n-1)?"non-boring":"boring");
	}
	return 0;
}

