//集合dp
//d(i,s1,s2)=min(d(i+1,s1,s2),c[i]+d(i+1,s1',s2')) 前一项i>=m时才加入,表示不选当前雇员的花费
//d(i,s1,s2) 表示前i个人，教一门课的集合为s1,两门课以上的集合为s2
#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

const int maxn=125,maxs=(1<<8);
const int INF=0x3f3f3f3f;
int n,m,s,c[maxn],st[maxn],d[maxn][maxs][maxs];

void print(int n)
{
	while(n){
		printf("%d",n&1);
		n=(n>>1);
	}
	puts("");
}


int dp(int i,int s0,int s1,int s2)//前i个人，不能教科目集合，一人教科目集合，至少二人教科目集合
{
	if(i>=m+n) return s2==(1<<s)-1?0:INF;
	int& ans=d[i][s1][s2];
	if(ans>=0) return ans;
	ans=INF;
	if(i>=m) ans=dp(i+1,s0,s1,s2);
	int m0=st[i]&s0;	//没人教恰能教科目集合
	int m1=st[i]&s1;	//有人教和能教科目集合
	s0^=m0;			//去掉没人教恰能教科目
	s1=(s1^m1)|m0;	//去掉有人教恰能教科目,加上没人教恰能教科目
	s2|=m1;			//加上有人教恰能教科目
	ans=min(ans,c[i]+dp(i+1,s0,s1,s2));
	return ans;
}

int main()
{
	//freopen("test","r",stdin);
	while(scanf("%d %d %d",&s,&m,&n)==3 && s){
		for(int i=0;i<m+n;++i){
			scanf("%d",&c[i]);
			int S=0;
			char ch=getchar();
			while(ch!='\n'){
				ch=getchar();
				if(ch<'0' || ch>'9') continue;
				S|=(1<<(ch-'1'));
			}
			st[i]=S;
		}
		memset(d,-1,sizeof(d));
		printf("%d\n",dp(0,(1<<s)-1,0,0));
	}
	return 0;
}

