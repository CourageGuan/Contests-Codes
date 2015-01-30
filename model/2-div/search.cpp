#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=123456;

int _search(int a[],int n,int x,int y)
{
	if(y<=x) return -1;
	int m=x+(y-x)/2;		
	if(a[m]==n) return m;
	if(a[m]>n) return _search(a,n,x,m);
	else return _search(a,n,m+1,y);
}

int search(int a[],int n,int x,int y)
{
	int m;
	while(x<y){
		m=x+(y-x)/2;
		if(a[m]==n) return m;
		if(a[m]>n) y=m;
		if(a[m]<n) x=m+1;
	}
	return -1;
}

int low_bound(int a[],int n,int x,int y)
{
	int m;
	while(x<y){
		m=x+(y-x)/2;
		if(a[m]>=n) y=m;
		else x=m+1;
	}
	if(a[x]!=n) return -1;
	return x;
}

int up_bound(int a[],int n,int x,int y)
{
	int m;
	while(x<y){
		m=x+(y-x)/2;
		if(a[m]<=n) x=m+1;
		else y=m;
	}
	if(a[y-1]!=n) return -1; 
	return y-1;
}

int main()
{
	int a[maxn],n;
	cin>>n;
	for(int i=0;i<n;++i) cin>>a[i];
	sort(a,a+n);
	int t;
	cin>>t;
	int pos=search(a,t,0,n);
	if(pos==-1){
		puts("Not Found");
		return 0;
	}
	cout<<"Pos "<<pos<<":"<<a[pos]<<endl;
	return 0;
}
