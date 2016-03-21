#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<sstream>
using namespace std;

const int maxn=30+5;

void swp(int a[],int k,int n)
{
	for(int i=0;i<(n-k+1)/2;++i)
		swap(a[i],a[n-k-i]);
}

bool sorted(int a[],int b[],int n)
{
	for(int i=0;i<n;++i)
		if(a[i]!=b[i]) return false;
	return true;
}
	
void solve(int a[],int n)
{
	int b[maxn];
	for(int i=0;i<n;++i){
		if(i) cout<<" ";
		cout<<a[i];
		b[i]=a[i];
	}
	cout<<endl;
	sort(b,b+n);
	if(sorted(a,b,n)){
		cout<<0<<endl;
		return;
	}
	int cnt=0;
	for(int i=n-1;i>=0;--i){
		for(int j=0;j<n;++j){
			//cout<<j<<" "<<a[j]<<" "<<i<<" "<<b[i];
			if(a[j]==b[i]){
				cnt++;
				if (cnt==n-j) break;
				if(j!=0){
					swp(a,n-j,n);
					cout<<n-j<<" ";
				}
				//if(cnt==n-j) break;
				swp(a,cnt,n);
				cout<<cnt<<" ";
				/*cout<<endl;
				for(int i=0;i<n;++i){
					if(i) cout<<" ";
					cout<<a[i];
				}
				cout<<endl;*/
				break;
			}
		}
		if(sorted(a,b,n)){
			cout<<0<<endl;
			return;
		}
	}
	cout<<0<<endl;
}

int main()
{
	//freopen("test","r",stdin);
	string s;
	while(getline(cin,s)){
		int n=0,a[maxn];
		stringstream ss(s);
		while(ss>>a[n]) n++;
		solve(a,n);
	}
	return 0;
}

