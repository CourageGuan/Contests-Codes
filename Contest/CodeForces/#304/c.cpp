#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define fi first
#define se second
#define len(x) ((int)log10(x)+1)

typedef long long  LL;
typedef pair<LL,LL> PLL;
set<PLL> vis;
const int maxn=10;
LL s[2];
int n;

inline bool check(LL n){
	if(n/(LL)pow(10,max(0,len(n)-2))==10) return 1;
	return 0;
}

bool bfs(){
	vis.clear();
	queue<PLL> q;
	queue<int> d;
	q.push(mp(s[0],s[1]));
	d.push(0);
	vis.insert(mp(s[0],s[1]));

	while(!q.empty()){
		PLL	u = q.front(); q.pop();
		int t=d.front(); d.pop();
		if(u.fi==0){
			printf("%d 2\n",t);
			return true;
		}else if(u.se==0){
			printf("%d 1\n",t);
			return true;
		}

		LL p1=u.fi/(LL)pow(10,len(u.fi)-1-(check(u.fi)?1:0)),t1=u.fi%(LL)pow(10,len(u.fi)-1-(check(u.fi)?1:0));
		LL p2=u.se/(LL)pow(10,len(u.se)-1-(check(u.se)?1:0)),t2=u.se%(LL)pow(10,len(u.se)-1-(check(u.se)?1:0));

    //	printf("%lld %lld\n",p1,p2);
	//	printf("%lld %lld\n",t1,t2);

		if(p1>p2){
			t1*=100;
			if(p1==10) p2*=10;
			t1+=p2*10+p1;
		}else {
			t2*=100;
			if(p2==10) p1*=10;
			t2+=p1*10+p2;
		}

	//	printf("%lld %lld\n",t1,t2);
	//	puts("");

		if(vis.find(mp(t1,t2))==vis.end()){
			vis.insert(mp(t1,t2));
			q.push(mp(t1,t2));
			d.push(t+1);
		}

	}
	return false;
}

int main()
{
	freopen("test.txt","r",stdin);
	scanf("%d",&n);
	for(int i=0;i<2;++i){
		int t,x;
		scanf("%d",&t);
		s[i]=0;
		for(int j=1;j<=t;++j){
			scanf("%d",&x);
			if(x==10) s[i]*=10;
			s[i]+=x*(LL)pow(10,t-j);
		}
	}
	printf("%lld %lld\n",s[0],s[1]);
	if(!bfs()){
		puts("-1");
	}
	return 0;
}

