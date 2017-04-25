#include<bits/stdc++.h>

using namespace std;
const int maxn = 2*100010;
stack<int> st;

char s[maxn];
int main()
{
	//fropen("test.txt","r",stdin);
	int n;
	scanf("%d",&n);
	scanf("%s",s);
	int i=0;
	while(i<n){
		if(st.empty()){
			st.push(s[i++]-'0');
			continue;
		}
		if(st.top()+s[i]-'0'==1) st.pop();
		else st.push(s[i]-'0');
		++i;
	}
	printf("%d\n",st.size());
	return 0;
}
