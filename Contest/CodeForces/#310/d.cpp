//WA
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
const int maxn=2*100010;
int id[maxn];

struct Is{
	int id;
	LL l,r;
	bool operator<(const Is& rhs) const {
		return r<rhs.r || (r==rhs.r && l<rhs.l);
	}
} is[maxn];
struct Br{
	int id;
	LL d;
	bool operator<(const Br& rhs) const {
		return d<rhs.d;
	}
} br[maxn];

bool cmp(const Is& a,const Is& b) {
	return a.l<b.l || (b.l==b.l && a.r<b.r);
}

int main()
{
//	freopen("test.txt","r",stdin);
	int n,m; bool flag=true;
	scanf("%d %d",&n,&m);
	LL L,R;
	scanf("%lld %lld",&L,&R);
	for(int i=1;i<n;++i){
		LL l,r;
		scanf("%lld %lld",&l,&r);
		is[i-1].id=i-1;
		is[i-1].r=r-L;
		is[i-1].l=l-R;
		L=l;R=r;
	}
	--n;
	sort(is,is+n);
	//for(int i=0;i<n;++i){
	//	printf("%lld %lld ---- %d\n",is[i].l,is[i].r,is[i].id);
	//}
	for(int i=0;i<m;++i){
		scanf("%lld",&br[i].d);
		br[i].id=i;
	}
	sort(br,br+m);
	//for(int i=0;i<m;++i){
	//	printf("%lld ---- %d\n",br[i].d,br[i].id);
	//}
	int i=0,j=0;
	memset(id,-1,sizeof id);
	while(i<n && j<m){
		if(j>=m || m-j<n-i){
			flag=false;
			break;
		}
		while(j<m){
			if(br[j].d<=is[i].r && br[j].d>=is[i].l){
				id[is[i++].id]=br[j++].id;
				break;
			}
			++j;
		}
	}
	if(i<n) flag=false;
	if(flag){
		puts("Yes");
		for(int i=0;i<n;++i) printf("%d%c",id[i]+1,i!=n-1?' ':'\n');
	}else{
		i=j=0;
		memset(id,-1,sizeof id);
		sort(is,is+n,cmp);
		while(i<n && j<m){
			if(j>=m || m-j<n-i){
				puts("No");
				return 0;
			}
			while(j<m){
				if(br[j].d<=is[i].r && br[j].d>=is[i].l){
					id[is[i++].id]=br[j++].id;
					break;
				}
				++j;
			}
		}
		if(i<n){
			puts("No");
			return 0;
		}
		puts("Yes");
		for(int i=0;i<n;++i) printf("%d%c",id[i]+1,i!=n-1?' ':'\n');
	}
	return 0;
}


