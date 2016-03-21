/*这道题目不是典型的最长递增子序列，读题啊，少年
  但是和LIS类似*/
#include<bits/stdc++.h>
using namespace std;

#define F(i,a,b) for(int i=a;i<=b;++i)
#define Fd(i,a,b) for(int i=a;i>=b;--i)

const int maxn=200000+5;
const int inf=0x7fffffff;
#define ins insert
#define mp make_pair
#define fi first
#define se second
#define low lower_bound
#define up upper_bound
typedef pair<int,int> PII;

set<PII> s;
set<PII>::iterator it,ii; 
int f[maxn],g[maxn];

int main()
{
    //freopen("input","r",stdin);
	int kase;
	cin>>kase;
	while(kase--){
		int n;
		int a[maxn],ans=1;
		scanf("%d",&n);
		F(i,0,n-1) scanf("%d",&a[i]);
		g[0]=1;f[n-1]=1;
		F(i,1,n-1) if(a[i]>a[i-1]) g[i]=g[i-1]+1; else g[i]=1; 
		Fd(i,n-2,0) if(a[i+1]>a[i]) f[i]=f[i+1]+1; else f[i]=1;
		s.ins(mp(a[0],g[0]));
		F(i,1,n-1){
			bool flag=true;
			PII p(a[i],g[i]);
			it=s.low(p);
			if(it!=s.begin()){
				PII last=*(--it);
				int cur=f[i]+last.se;
				ans=max(ans,cur);
				if(p.se<=last.se) flag=false;
			}
			if(flag){
				s.erase(p);
				s.ins(p);
				it=s.find(p);
				//cout<<"!"<<it->fi<<" "<<it->se<<endl;
				it++;
				while(it!=s.end() && it->se<=g[i] && it->fi>a[i]) s.erase(it++);
			}
			//for(ii=s.begin();ii!=s.end();++ii) cout<<(*ii).fi<<" "<<(*ii).se<<endl;
			//cout<<endl;
		}
		s.clear();
		cout<<ans<<endl;
		//cout<<"--------------"<<endl;
	}
	//printf("\nTIME WASTED  %.2f s\n",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}
