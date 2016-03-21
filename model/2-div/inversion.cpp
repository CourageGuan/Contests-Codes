#include<iostream>
using namespace std;

const int maxn=123456;

int inversion(int a[],int t[],int x,int y)
{
	if(y-x<=1) return 0;
	int m=x+(y-x)/2,ans=0;
	ans+=inversion(a,t,x,m);
	ans+=inversion(a,t,m,y);
	int p=x,q=m,cnt=x;
	while(p<m || q<y){
		if(q>=y || (p<m && a[p]<=a[q])) t[cnt++]=a[p++];
		else{
			t[cnt++]=a[q++];
			ans+=m-p;
		}
	}
	//cout<<ans<<"!"<<endl;
	for(int i=x;i<y;++i) a[i]=t[i];
	return ans;
}

int main()
{
	int a[maxn],t[maxn],n;
	cin>>n;
	for(int i=0;i<n;++i) cin>>a[i];
	cout<<inversion(a,t,0,n)<<endl;
	return 0;
}

