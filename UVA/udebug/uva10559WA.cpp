/*dp少一维状态*/
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

#define pow(b) (b)*(b)
#define max(a,b) ((a)>(b))?(a):(b)

const int maxn=233;
int a[maxn],b[maxn],f[maxn][maxn];

int main()
{
	//freopen("test","r",stdin);
	int t;
	cin>>t;
	for(int kase=1;kase<=t;++kase){
		int n,i=1,tot=1,c[maxn];
		cin>>n;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		cin>>c[1];
		a[1]=c[1];
		b[1]=1;
		while(i<n){
			i++;	
			cin>>c[i];
			if(c[i]==c[i-1])
				b[tot]++;	
			else{
				tot++;
				a[tot]=c[i];
				b[tot]++;
			}
		}
		/*for(int k=1;k<=tot;k++)
			cout<<a[k]<<" "<<b[k]<<endl;*/
		memset(f,0,sizeof(f));
		for(int j=1;j<=tot;++j) f[j][j]=pow(b[j]);
		for(int j=1;j<=tot-1;++j)
			for(int i=1;i+j<=tot;++i){
				if(a[i]==a[i+j])
					f[i][i+j]=f[i+1][i+j-1]+pow(b[i]+b[i+j]);
				for(int k=0;i+k+1<=i+j;k++)
					f[i][i+j]=max(f[i][i+j],f[i][i+k]+f[i+k+1][i+j]);
		}
		/*for(int k=1;k<=tot;k++){
			for(int j=1;j<=tot;j++)
				cout<<f[k][j]<<" ";
			cout<<endl;
		}*/
		cout<<"Case "<<kase<<": "<<f[1][tot]<<endl;
	}
	return 0;
}
