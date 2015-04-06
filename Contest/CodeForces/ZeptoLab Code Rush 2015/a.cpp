#include<bits/stdc++.h>
using namespace std;

int n;
char s[200];

bool solve()
{
	for(int i=0;i<n;++i) if(s[i]=='*'){
		for(int j=1;i+4*j<n;++j){
			int cnt=1;
			for(int k=1;i+k*j<n && k<5;++k)
		   		if(s[i+k*j]=='*') ++cnt;
				else break;
			if(cnt>=5) return true;
		}
	}
	return false;
}

int main()
{
	//freopen("test","r",stdin);
	scanf("%d",&n);
	scanf("%s",s);
	puts(solve()?"yes":"no");
	return 0;
}
