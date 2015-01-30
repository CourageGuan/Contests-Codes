#include<bits/stdc++.h>
using namespace std;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
int pic[1005][1005];

bool yes(int x,int y)
{
	bool flag=true;
	F(i,x-1,x)
		F(j,y-1,y)
			if(!pic[i][j]){
				flag=false;
				break;
			}
	if(flag) return 1;
	flag=true;
	F(i,x,x+1)
		F(j,y-1,y)
			if(!pic[i][j]){
				flag=false;
				break;
			}
	if(flag) return 1;
	flag=true;
	F(i,x-1,x)
		F(j,y,y+1)
			if(!pic[i][j]){
				flag=false;
				break;
			}
	if(flag) return 1;
	flag=true;
	F(i,x,x+1)
		F(j,y,y+1)
			if(!pic[i][j]){
				flag=false;
				break;
			}
   return flag;
} 

int main()
{
	memset(pic,0,sizeof(pic));
	int m,n,k,ans=0;
	cin>>m>>n>>k;
	F(t,1,k){
		int i,j;
		cin>>i>>j;
		if(ans) continue;
		if(pic[i][j]) continue;
		else pic[i][j]=1;
		if(yes(i,j)) ans=t;
	}
	cout<<ans<<endl;
	return 0;
}

