/*构造法，从大到小运用下列原则将k移到kth:
 * 若kth-k为奇数则 exc(k,kth)　否则 exc(k,kth-1) 
   k+=dis/2	 直至k移动到相应位置上*/
#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

typedef pair<int,int> pii;
vector<pii> ans;

const int maxn=10000+5;

int n,a[maxn];

bool is_sort()
{
	for(int i=1;i<=n;++i)
		if(a[i]!=i) return false;
	return true;
}

void exc(int l,int r){
	int m=l+(r-l)/2+1;
	for(int i=0;i<=(r-l)/2;++i) swap(a[l+i],a[m+i]);
}

int main()
{
	//freopen("test","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--){
		ans.clear();
		int cnt=0;
		scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%d",&a[i]);
		int cur=n;
		while(!is_sort())
		{
			int pos=0;
			for(pos=1;pos<=cur;++pos) if(a[pos]==cur) break;
			while(pos!=cur){
				if((cur-pos)&1){
					exc(pos,cur);++cnt;
					ans.push_back(make_pair(pos,cur));
				}
				else{
					exc(pos,cur-1);++cnt;
					ans.push_back(make_pair(pos,cur-1));
				}
				pos+=(cur-pos-1)/2+1;
			}
			--cur;
		}
		printf("%d\n",cnt);
		for(int i=0;i<cnt;++i) printf("%d %d\n",ans[i].first,ans[i].second);
	}
	return 0;
}

