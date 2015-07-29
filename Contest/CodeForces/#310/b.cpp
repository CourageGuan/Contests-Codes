#include<bits/stdc++.h>

using namespace std;
const int maxn=1010;
int n;
int g[maxn];


bool yes(){
	for(int t=0;t<n;++t){
		bool flag=true;
		for(int i=0;i<n;++i){
			if(i&1) g[i]=g[i]-1+n;
			else ++g[i]; 
			g[i]%=n;
			if(g[i]!=i) flag=false;
		}
		if(flag) return true;
	}
//	for(int i=0;i<n;++i) printf("%d\n",g[i]);
	return false;
}

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d",&n);
	for(int i=0;i<n;++i) scanf("%d",g+i);	
	puts(yes()?"Yes":"No");
	return 0;
}
