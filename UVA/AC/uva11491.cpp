/*附加条件的单调栈，当删除元素足够时直接加入栈尾*/
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn=100000+5;

int main()
{
	//freopen("test","r",stdin);
	int n,d,s[maxn],p[maxn];
	while(scanf("%d %d",&n,&d)==2 && n){
		getchar();
		for(int i=0;i<n;++i){
			char ch=getchar();
			//cout<<ch;
			s[i]=ch-'0';
		}
		int q[maxn],r=-1;	// dequeue
		int cnt=0;
		for(int i=0;i<n;++i){
			if(cnt>=d){
				q[++r]=s[i];
				continue;
			}
			if(i==0 || q[r]>=s[i]) q[++r]=s[i];
			else{
				while(q[r]<s[i] && r>=0 && cnt<d){
					--r;
					++cnt;
				}
				q[++r]=s[i];
			}
		}
		r=min(r,n-d-1);
		for(int i=0;i<=r;++i) printf("%d",q[i]);
		puts("");
	}
	return 0;
}

