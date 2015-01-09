#include<iostream>
#include<algorithm>
#include<climits>
#include<cstring>
#define MAXN 510
#define LIM INT_MAX>>1
using namespace std;

int a[MAXN],b[MAXN],c[MAXN];
int f[MAXN][MAXN];

int dp(int x,int y)		//Çø¼äDP 
{
	if(x>y) 
		return(LIM);
	if(f[x][y]<LIM) 
		return(f[x][y]);
	if (a[x]==a[y])
		f[x][y]=min(f[x][y],max(3-b[x]-b[y],0))+dp(x+1,y-1);
	for(int i=x;i<y;i++)
		f[x][y]=min(f[x][y],dp(x,i)+dp(i+1,y));
	return f[x][y];
}

int main()
{
	memset(f,LIM,sizeof(f));
	//cout<<f[0][0]<<endl;
	int n,l=0;
	cin>>n;
	c[0]=-LIM;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		if(c[i]!=c[i-1])		//sum the same
		{
			l++;
			a[l]=c[i];			
			b[l]=1;
			f[l-1][l-1]=max(3-b[l-1],1);
		}
		else
			b[l]++;
	}
	f[l][l]=max(3-b[l],1);
	/*cout<<l<<endl;
	for(int i=1;i<=l;i++)
    	cout<<a[i]<<" "<<b[i]<<endl;*/
	cout<<dp(1,l)<<endl;
	return 0;	
}


