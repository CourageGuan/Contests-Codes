//滑动窗口最大最小值
//用单调队列维护
#include<cstdio>
#include<cctype>
#include<vector>

using namespace std;

const int maxn = 1000010;
vector<int> ans[2];
int q_min[maxn*2],q_max[maxn*2];
int n,k,a[maxn];

int nextint()
{
	char c=getchar();
	int res=0,sign=1;
	while(!isdigit(c) && c!='-') c = getchar();
	if(c=='-')
	{
	   	sign=-1;
		c = getchar();
	}
	while(isdigit(c)) res= res*10 + c-'0',c = getchar();
	return res*sign;
}

void print(int x)
{
	if(x<10)
	{
		putchar(x+'0');
		return;
	}
	print(x/10);
	putchar(x%10+'0');
}

int main()
{
	//freopen("test.txt","r",stdin);
	while(scanf("%d %d",&n,&k)==2)
	{
		for(int i=0;i<2;++i) ans[i].clear();
		int l1,l2,r1,r2;
		l1 = l2 = 1; 
		r1 = r2 = 0;
		for(int i=0;i<n;++i) a[i]=nextint();
		for(int i=0;i<n;++i)
		{
			while(l1<=r1 && a[i]<a[q_min[r1]]) --r1;
			q_min[++r1]=i;
//			printf("%d ",q_min.front());
			while(l2<=r2 && a[i]>a[q_max[r2]]) --r2;
			q_max[++r2]=i;
//			printf(" %d\n",q_max.front());
			if(i<k-1) continue;
			while(l1<=r1 && i-q_min[l1]>=k) ++l1;
			while(l2<=r2 && i-q_max[l2]>=k) ++l2;
			ans[0].push_back(a[q_min[l1]]);
			ans[1].push_back(a[q_max[l2]]);
		}
		for(int i=0;i<ans[0].size();++i)
		{ 
			if(ans[0][i]<0) putchar('-'),print(-ans[0][i]);
			else print(ans[0][i]);
			putchar(i==ans[0].size()-1?'\n':' ');
		}
		for(int i=0;i<ans[1].size();++i) 
		{
			if(ans[1][i]<0) putchar('-'),print(-ans[1][i]);
			else print(ans[1][i]);
			putchar(i==ans[1].size()-1?'\n':' ');
		}
	}
	return 0;
}

