#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<set>
#include<vector>
#include<map>
using namespace std;

#define REP(i,n) for(int i=0;i<n;++i)
#define F(i,a,b) for(int i=a;i<=b;++i)
#define Fd(i,a,b) for(int i=a;i>=b;--i)

const int maxn=100;
char pic[maxn][maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	int n,m;
	while(~scanf("%d %d%*c",&n,&m)){
		int mxx=0,mxy=0,mnx=100,mny=100;
		REP(i,n){ REP(j,m)
			{	
				pic[i][j]=getchar();
				if(pic[i][j]=='*'){
					mxx=max(j,mxx);
					mnx=min(j,mnx);
					mxy=max(i,mxy);
					mny=min(i,mny);
				}
			}
			getchar();
		}
		F(i,mny,mxy) {
			F(j,mnx,mxx)
			putchar(pic[i][j]);
			putchar('\n');
		}
	}
	return 0;
}



