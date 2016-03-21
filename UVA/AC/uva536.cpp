/*基础，二叉树的递归构建，已知前序和中序遍历，*/
#include<bits/stdc++.h>
using namespace std;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

const int maxn=30;
char pre[maxn],in[maxn];

void dfs(int l1,int r1,int l2,int r2)	//l1..r1 pre中的一棵(子)树 l2..r2 in中对应的一棵(子)树
{
	if(l2>r2) return;
	int cnt=l2;
	while(pre[l1]!=in[cnt]) cnt++;
	int num=cnt-l2;
	dfs(l1+1,l1+num,l2,cnt-1);
	dfs(l1+num+1,r1,cnt+1,r2);
	cout<<pre[l1];
}


int main()
{
	//freopen("test","r",stdin);
	while(scanf("%s %s",pre,in)==2){
		int n=strlen(pre);
		dfs(0,n-1,0,n-1);
		cout<<endl;
	}
	return 0;
}
