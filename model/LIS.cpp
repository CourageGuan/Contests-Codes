/*最长递增子序列,O(n^2)及O(nlogn) 算法*/
#include<bits/stdc++.h>
using namespace std;

#define F(i,a,b) for(int i=a;i<=b;++i)
const int maxn=100000*2+5;

/*
int dp[maxn],a[maxn];

int main()
{
	freopen("input","r",stdin);
	freopen("outa","w",stdout);
	int kase;
	cin>>kase;
	while(kase--){
		int n;
		cin>>n;
		F(i,0,n-1) scanf("%d",&a[i]);
		memset(dp,0,sizeof(dp));
		F(i,0,n-1) 
			F(j,0,i-1)
				if(a[i]>a[j]) dp[i]=max(dp[i],dp[j]+1);
		int ans=0;
		F(i,0,n-1) ans=max(ans,dp[i]);
		printf("%d\n",ans+1);
	}
	printf("\nTIME WASTED  %.2f s\n",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}
*/

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

int main()
{
    freopen("input","r",stdin);
    freopen("outb","w",stdout);
	int kase;
	cin>>kase;
	while(kase--){
		int n;
		int a[maxn],ans=1;
		scanf("%d",&n);
		F(i,0,n-1) scanf("%d",&a[i]);
		s.ins(mp(a[0],1));
		F(i,1,n-1){
			bool flag=false;
			it=s.low(mp(a[i],inf));
			if(it==s.begin()) flag=true;
			if(it==s.end() || (a[i]<it->fi && it!=s.begin())) it--;
			//cout<<it->fi<<" "<<it->se<<endl;
			while(it!=s.begin() && it->fi==a[i]) s.erase(it--);
			int cur=1;
			cur+=(flag || it->fi>=a[i])?0:it->se;
			//cout<<cur<<endl;
			s.ins(mp(a[i],cur));
			ans=max(ans,cur);
			it=s.find(mp(a[i],cur));
			//cout<<"!"<<it->fi<<" "<<it->se<<endl;
			it++;
			while(it!=s.end() && (*it).se<=cur && (*it).fi>=a[i]) s.erase(it++);
			//for(ii=s.begin();ii!=s.end();++ii) cout<<(*ii).fi<<" "<<(*ii).se<<endl;
			//cout<<endl;
		}
		s.clear();
		cout<<ans<<endl;
		//cout<<"--------------"<<endl;
	}
	printf("\nTIME WASTED  %.2f s\n",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}
