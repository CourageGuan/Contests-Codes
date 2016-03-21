/*Catalan数 h(n)=h(n-1)h(0)+h(n-2)h(1)+...+h(0)h(n-1) (n>=2)*/
#include<iostream>
#include<cstring>
using namespace std;

long long ans[35];

int main()
{
	memset(ans,0,sizeof(ans));
	int n;
	cin>>n;
	ans[0]=1;
	ans[1]=1;
	ans[2]=2;
	for(int j=3;j<=n;++j)
		for(int i=0;i<j;++i)
			ans[j]+=ans[i]*ans[j-i-1];
	cout<<ans[n]<<" "<<n+1<<endl;
	return 0;
}
