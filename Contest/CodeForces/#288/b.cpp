#include<bits/stdc++.h>
using namespace std;

char s[100000+10];

int main()
{
	cin>>s;
	int len=strlen(s),ok=0,mn=0,num=s[len-1]-'0';
	for(int i=0;i<len-1;++i)
		if(!((s[i]-'0') & 1)){
			ok=1;
			mn=max(mn,i);
			if(s[i]-'0'<num){
				swap(s[i],s[len-1]);	
				cout<<s<<endl;
				return 0;	
			}
		}
	if(ok){
		swap(s[mn],s[len-1]);	
		cout<<s<<endl;
	}else cout<<-1<<endl;
	return 0;
}
