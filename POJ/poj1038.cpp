//三进制状态压缩dp
//我的方法是枚举状态再判断，然而不知道为什么WA了
//正解在下面
#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;

#define pb push_back

//typedef long long LL; 
const int maxn = 200;
const int maxs = 59049;
int d[2][maxs];
vector<int> ST[3];
vector<int> st[maxn],pos[maxn];
int G[maxn][12];
int n,m,K;

inline int qpow(int a,int n)
{
	int res = 1;
	while(n)
	{
		if(n&1) res*=a;
		n>>=1;
		a*=a;
	}
	return res;
}

void dfs(int p,int s1,int s2,int num)
{
	if(p>m+1) return;
	if(p==m+1)
	{
		ST[0].pb(s1);
		ST[1].pb(s2);
		ST[2].pb(num);
		return ;
	}

	dfs(p+3,s1*qpow(3,3)+qpow(3,3)-1,s2*qpow(3,3)+13,num+1);	 //3*2
	dfs(p+2,s1*qpow(3,2)+qpow(3,2)-1,s2*qpow(3,2),num+1);		 //2*3

	//填虚结点
	dfs(p+1,s1*3+1,s2*3+2,num);		//s1空一格
	dfs(p+1,s1*3,s2*3+1,num);		//s1空两格
	dfs(p+1,s1*3+2,s2*3+2,num);		//整列填满不空
}

void init()
{
	for(int i=0;i<3;++i) ST[i].clear();
	for(int i=1;i<=n;++i){
	   	st[i].clear();pos[i].clear();
	}
	memset(G,0,sizeof G);
	memset(st,0,sizeof st);
	dfs(1,0,0,0);
}

inline bool ok(int i,int j)
{
	bool flag=true;
	int t=ST[0][j];
	for(int k=0;k<pos[i].size();++k)
	{
		int tt=st[i][k];
		int ttt=(t/qpow(3,m-pos[i][k]))%3;
		if(!ttt) continue;
		else if(ttt==2) flag = false;
		else flag = (tt<=1);
		if(!flag) continue;
	}
	/*for(int k=m;k>=1;--k)
	{
		int tt=t%3; t/=3;
		if(!tt) continue;
		else if(tt==2) flag = (st[i][k]==0);
		else flag = (st[i][k]<=1);
		if(!flag) break;
	}
	*/
	return flag;
}

int main()
{
	freopen("test.txt","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d %d",&n,&m,&K);
		init();
		for(int i=0;i<K;++i)
		{
			int x,y;
			scanf("%d %d",&x,&y);
			G[x][y] = 1;
		}
		for(int j=1;j<=m;++j)
		{
		   	st[1].pb(2);
			pos[1].pb(j);
		}
		for(int i=2;i<=n;++i)
		{
			for(int j=1;j<=m;++j)
			{
			   	int t = (G[i-1][j]<<1)+G[i][j];
				if(t)
				{
				   	st[i].pb(t);
					pos[i].pb(j);
				}
			}
		}


//		for(int i=1;i<=n;++i)
//			for(int j=1;j<=m;++j)
//				printf("%d%c",G[i][j],j==m?'\n':' ');
//		puts("");


//		for(int i=1;i<=n;++i)
//		{
//			for(int j=0;j<pos[i].size();++j)
//				printf("*%d , %d* ",pos[i][j],st[i][j]);
//			puts("");
//		}

//		printf("%d\n",ST[0].size());

		memset(d,0,sizeof d);
		int ans = 0;
		for(int i=2;i<=n;++i)
		{
			int t=i&1;
			for(int j=0;j<ST[0].size();++j)
			{
				if(ok(i,j))
				{
					d[t][ST[0][j]] = max(d[t][ST[0][j]],d[t^1][ST[1][j]]+ST[2][j]);
				}
			}
			memset(d[t^1],0,sizeof d[t^1]);
		}
		for(int i=0;i<maxs;++i) ans = max(ans,d[n&1][i]);
		printf("%d\n",ans);
	}
	return 0;
}


/*
#include<cstdio>   
#include<cstring>   
#include<algorithm>

using namespace std;

int n,m,k,t,x,y,p,pw[11]={1};   
bool f1[152][12],f2[152][12];   
int a[2][59050];  
   
void dfs(int x,int s1,int s2,int n)   
{   
	if(x>m+1)return;   
	if(x==m+1){a[p&1][s1]=max(a[p&1][s1],a[1-p&1][s2]+n); return;}   
	if(f1[p][x])dfs(x+3,s1*27,s2*27+13,n+1);   
	if(f2[p][x])dfs(x+2,s1*9,s2*9+8,n+1);   
	dfs(x+1,s1*3+2,s2*3+1,n);   
	dfs(x+1,s1*3+1,s2*3,n);   
	dfs(x+1,s1*3,s2*3,n);   
}   
   
int main()   
{   
//	for(int i=1;i<11;i++)pw[i]=pw[i-1]*3;   
	freopen("test.txt","r",stdin);
	scanf("%d",&t);   
	while(t--)   
	{   
		scanf("%d%d%d",&n,&m,&k);   
		memset(a[1],0,sizeof(a[1]));   
		memset(f1,1,sizeof(f1));   
		memset(f2,1,sizeof(f2));   
		while(k--)   
		{   
			scanf("%d%d",&x,&y);   
			for(int i=0;i<2;i++)   
				for(int j=0;j<3;j++)   
				{   
					if(y-j>=0)f1[x+i][y-j]=0;   
					if(y-i>=0)f2[x+j][y-i]=0;   
				}   
		}   
		for(int i=0;i<12;i++)f2[2][i]=0;   
		for(p=2;p<=n;p++)   
		{   
			memset(a[p&1],0,sizeof(a[p&1]));   
			dfs(1,0,0,0);   
		}   
		printf("%d\n",a[n&1][0]);   
	}   
}  
*/

