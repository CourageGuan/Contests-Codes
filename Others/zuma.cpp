/*区间DP，将连续相同的珠子分成几个色块
  区间两端色块相同时考虑加入色块情况
  考虑长度为1的区间依次到长度为n的*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#define MAXN 510
using namespace std;

const int LIM=0x3f;
int a[MAXN],b[MAXN],c[MAXN];
int f[MAXN][MAXN];

int main()
{
	//freopen("test","r",stdin);
	memset(f,0x3f,sizeof(f));
	//cout<<f[0][0]<<endl;
	int n,l=0;
	cin>>n;
	c[0]=-1;
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
	/*for(int i=1;i<=l;i++)
		cout<<a[i]<<" "<<b[i]<<endl;*/
	for(int i=1;i<=l;i++)
		f[i][i]=max(3-b[i],1);
	for(int j=1;j<=l-1;++j)
		for(int i=1;j+i<=l;++i){
			if(a[i]==a[i+j])
				f[i][i+j]=((b[i]+b[i+j]==2)?1:0)+f[i+1][i+j-1];
			for(int k=1;k<=j;++k)
				f[i][i+j]=min(f[i][i+j],f[i][i+k-1]+f[i+k][i+j]);
	}
	/*for(int i=1;i<=l;++i){
		for(int j=1;j<=l;++j)
			cout<<f[i][j]<<" ";
		cout<<endl;
	}*/
	cout<<f[1][l]<<endl;
	return 0;	
}

