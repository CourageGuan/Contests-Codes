#include<bits/stdc++.h>
using namespace std;


int main()
{
	int ran[20][20],n;
	cin>>n;
	memset(ran,0,sizeof(ran));
	ran[1][1]=1;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j){
			if(i==1 && j==1) continue;
			ran[i][j]=ran[i-1][j]+ran[i][j-1];
		}
	cout<<ran[n][n]<<endl;
	return 0;
}
