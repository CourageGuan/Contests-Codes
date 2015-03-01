#include<bits/stdc++.h>
using namespace std;

inline char upcase(char c){
	if(c>=97) c-=32;
	return c;
}

inline char lowcase(char c){
	if(c<97) c+=32;
	return c;
}

map<char,int> mp;

int main()
{
	//freopen("test","r",stdin);
	mp.clear();
	string s,t;
	cin>>s>>t;
	int y=0,w=0;
	for(int i=0;i<s.size();++i) mp[s[i]]++;
	for(int i=0;i<t.size();++i)
		if(mp[t[i]]){
			y++;
			mp[t[i]]--;
			t[i]=' ';
		}
	for(int i=0;i<t.size();++i){
		if(t[i]==' ') continue;
		if(mp[upcase(t[i])]){ 
			w++;
			mp[upcase(t[i])]--;
		}else if(mp[lowcase(t[i])]){
			w++;
			mp[lowcase(t[i])]--;
		}
	}
	/*for(int i=0;i+s.size()<=t.size();++i){
		int y,w;y=w=0;
		for(int j=0;j<s.size();++j){
			if(t[i+j]==s[j]) y++;
			else if(upcase(t[i+j])==upcase(s[j])) w++;
		}
		if(y>yay){
			yay=y;
			whoops=w;
		}else if(y==yay) whoops=max(w,whoops);
	}
	for(int i=0;i+s.size()<=t.size();++i){
		int y,w;y=w=0;
		for(int j=s.size()-1;j>=0;--j){
			//cout<<t[i+s.size()-1-j]<<" "<<s[j]<<endl;
			if(t[i+s.size()-1-j]==s[j]) y++;
			else if(upcase(t[i+s.size()-1-j])==upcase(s[j])) w++;
		}
		if(y>yay){
			yay=y;
			whoops=w;
		}else if(y==yay) whoops=max(w,whoops);
	}*/
	printf("%d %d\n",y,w);
	return 0;
}

