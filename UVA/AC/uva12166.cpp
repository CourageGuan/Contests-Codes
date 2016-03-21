/*基本都是照着网上的题解写到的，思想是正难则反，统计每一个
 叶节点不变时整棵树的重量，即 W=w*2^dep，最后统计相同重量最多的情况，
 即最多的可能不变的叶节点，然后用所有叶节点数目减去之即为最少改变
 使整棵树平衡，感觉此题非常巧妙*/
#include<bits/stdc++.h>
using namespace std;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define fi first
#define se second
#define max(a,b) (a>b)?a:b

const int maxn=1<<20;
int sum;
char s[maxn];
map<long long,int> wei;

void init()
{
	sum=0;
	wei.clear();
}

void dfs(int l,int r,int dep)
{
	if(s[l]=='['){
		int pos=0;
		F(i,l+1,r-1){
			if(s[i]=='[') pos++;
			if(s[i]==']') pos--;
			if(s[i]==',' && pos==0){
				dfs(l+1,i-1,dep+1);
				dfs(i+1,r-1,dep+1);
			}
		}
		return;
	}
	int weight;
	s[r+1]='\0';
	sscanf(s+l,"%d",&weight);
	wei[(long long)weight<<dep]++;
}
	
	
int main()
{
	//freopen("test","r",stdin);
	int kase;
	cin>>kase;
	while(kase--){
		init();
		scanf("%s",s);
		dfs(0,strlen(s)-1,0);
		int mx=0;
		for(map<long long,int>::iterator it=wei.begin();it!=wei.end();++it){
			sum+=it->se;
			mx=max(mx,it->se);
		}
		//cout<<sum<<" "<<mx<<endl;
		printf("%d\n",sum-mx);
	}
	return 0;
}


