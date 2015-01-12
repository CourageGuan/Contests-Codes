/*用栈来判断括号匹配，坑爹的是空串合法! 所以只能用getline()了...*/
#include<bits/stdc++.h>
using namespace std;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define SETS(st) while(!st.empty()) st.pop()

int main()
{
	//freopen("test","r",stdin);
	int kase;
	cin>>kase;
	getchar();
	while(kase--){
		stack<char> st;
		string s;
		getline(cin,s);
		if(s.empty()){
			puts("Yes");
			continue;
		}
		int len=s.size()-1;
		bool flag=true;
		F(i,0,len){
			switch(s[i]){
				case '[':st.push('[');break;
				case '(':st.push('(');break;
				case ']':
					 if(!st.empty()) 
						if(st.top()=='[')
							st.pop();
						else flag=false;
					 else flag=false;
					 break;
				case ')':
					 if(!st.empty()) 
						if(st.top()=='(')
							st.pop();
						else flag=false;
					 else flag=false;
					 break;
			}
			//if(!flag) break;
		}
		if(!st.empty()) flag=false;
		puts((flag)?"Yes":"No");	
	}
	return 0;
}

/*
4

(([)(]))
(([()])))
([()[]()])()

Yes
No
No
Yes
*/
