#include<cstdio>
#include<iostream>
using namespace std;

const int maxn=100010;
const int INF=0x7fffffff;
int X[maxn],H[maxn];

int main()
{
//	freopen("test.txt","r",stdin);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i) scanf("%d %d",X+i,H+i);
	int cnt=1,last=1;
	X[n]=INF;H[n]=0;
	for(int i=1;i<n;++i){
		if(last<2){
			if(X[i]-H[i]>X[i-1]){
				last=0;
				++cnt;
			}else if(X[i]+H[i]<X[i+1]){
				last=2;
				++cnt;
			}else last=1;
		}else{
			if(X[i]-H[i]>X[i-1]+H[i-1]){
				last=0;
				++cnt;
			}else if(X[i]+H[i]<X[i+1]){
				last=2;
				++cnt;
			}else last=1;
		}
	}
	printf("%d\n",cnt);
	return 0;
}


