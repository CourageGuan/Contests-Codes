#include<bits/stdc++.h>
using namespace std;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

const int maxn=123;

struct aa{
	int id,v;
	bool operator <(const aa a)const {
		return v<a.v;
	}
} a[maxn];

int main()
{
	//freopen("test","r",stdin);
	int n,k;
	cin>>n>>k;
	F(i,0,n-1){
		cin>>a[i].v;
		a[i].id=i+1;
	}
	sort(a,a+n);
	int all=0,cnt=0;
	F(i,0,n-1){
		all+=a[i].v;
		if(all>k) break;
		cnt++;
	}
	cout<<cnt<<endl;
	if(cnt){
		F(i,0,cnt-1){ 
			if(i) cout<<" ";
			cout<<a[i].id;
		}
	cout<<endl;
	}
	return 0;
}


