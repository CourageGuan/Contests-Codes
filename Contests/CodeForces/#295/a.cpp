#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n,cnt=0;
	bool mp[30];
	memset(mp,0,sizeof(mp));
	char s[1000];
	cin>>n;
	cin>>s;
	for(int i=0;i<n;++i){
		if(s[i]>=97) s[i]-=32;
		s[i]-=65;
		if(!mp[s[i]]){
			cnt++;
			mp[s[i]]=1;
		}
	}
	if(n>=26 && cnt>=26) puts("YES");
	else puts("NO");
	return 0;
}
