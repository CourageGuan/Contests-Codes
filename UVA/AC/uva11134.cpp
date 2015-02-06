#include<bits/stdc++.h>
using namespace std;

#define F(i,n) for(int i=0;i<n;++i)

const int maxn=5000+5;

struct P{
	int a,b,id,ans;
	bool operator<(const P &ot)const {
		return (b!=ot.b)?b<ot.b:a<ot.a;
	}
}x[maxn],y[maxn];

bool cmp(const P& x,const P& y){return x.id<y.id;}

bool vx[maxn],vy[maxn];

bool solve(int n)
{
	memset(vx,0,sizeof(vx));
	memset(vy,0,sizeof(vy));
	sort(x,x+n);
	sort(y,y+n);
	/*F(i,n) cout<<y[i].a<<" ";
	cout<<endl;
	F(i,n) cout<<y[i].b<<" ";
	cout<<endl;*/
	F(i,n){
		bool flag=false;
		for(int j=x[i].a;j<=x[i].b;++j)
			if(!vx[j]){
				vx[j]=1;
				x[i].ans=j;
				flag=true;
				break;
			}
		if(!flag) return false;
		flag=false;
		for(int j=y[i].a;j<=y[i].b;++j)
			if(!vy[j]){
				vy[j]=1;
				y[i].ans=j;
				flag=true;
				break;
			}
		if(!flag) return false;
	}
	sort(x,x+n,cmp);
	sort(y,y+n,cmp);
	F(i,n)
		cout<<x[i].ans<<" "<<y[i].ans<<endl;
	return true;
}

int main()
{
	//freopen("test","r",stdin);
	int n;
	while(scanf("%d",&n)==1 && n){
		F(i,n){
			~scanf("%d%d%d%d",&x[i].a,&y[i].a,&x[i].b,&y[i].b);
			x[i].id=i;
			y[i].id=i;
		}
		if(!solve(n)) puts("IMPOSSIBLE");
	}
	return 0;
}

