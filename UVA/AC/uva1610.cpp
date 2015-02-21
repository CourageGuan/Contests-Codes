/*好开心，我爱WJY*/
/*竟然是诡异AC...*/
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

const int maxn=1000+10;

int main()
{
	//freopen("test","r",stdin);
	int n;
	while(scanf("%d",&n)==1 && n){
		string s[maxn];
		for(int i=0;i<n;++i) cin>>s[i];
		sort(s,s+n);
		int m=n/2-1,cnt=0;
		string s1=s[m],s2=s[m+1],ans;
		while(s1[cnt]==s2[cnt]) cnt++;
		ans[cnt]='\0';
		ans=s1.substr(0,cnt);
		//cout<<ans<<" "<<s1<<" "<<s2<<endl; 
		if(ans>=s1){
			cout<<ans<<endl;
			continue;
		}
		while(1){
			if(ans[cnt]=='\0'){
				ans.resize(cnt+1);
				ans[cnt]=s1[cnt];
			}
			else ans[cnt]++;
			if(ans>=s1 && ans<s2) break;
			//cout<<ans<<endl;
			if(ans>=s2 || ans[cnt]>='Z'){	//这里是细节
				ans[cnt]=s1[cnt];
				ans[++cnt]='\0';
			}
		}
		//cout<<(ans>=s1)<<(ans<s2)<<endl;
		cout<<ans<<endl;
	}
	return 0;
}
