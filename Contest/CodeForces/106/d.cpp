#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=a;i<=b;++i)
#define R(i,n) for(int i=0;i<n;++i)

const int maxn = 710;
const int mod = 1e9 + 7;
LL d[maxn][maxn][3][3];
int match[maxn];

LL dp(int L,int R,int l,int r)
{
	if(L >= R) return 1;
	LL& res = d[L][R][l][r];
	if(res != -1) return res;
	res = 0;
	if(match[L] != R)
	{
		if(l != 1) res = (res + dp(L+1,match[L]-1,1,0)*dp(match[L]+1,R,0,r) %mod) %mod;
		if(l != 2) res = (res + dp(L+1,match[L]-1,2,0)*dp(match[L]+1,R,0,r) %mod) %mod;
		res = (res + dp(L+1,match[L]-1,0,1)*dp(match[L]+1,R,1,r) %mod) %mod;
		res = (res + dp(L+1,match[L]-1,0,2)*dp(match[L]+1,R,2,r) %mod) %mod;
	}
	else
	{
		if(l != 1) res = (res + dp(L+1,R-1,1,0)) %mod;
		if(l != 2) res = (res + dp(L+1,R-1,2,0)) %mod;
		if(r != 1) res = (res + dp(L+1,R-1,0,1)) %mod;
		if(r != 2) res = (res + dp(L+1,R-1,0,2)) %mod;
	}
	return res;
}

string s;
stack<int> st;

int main()
{
	//freopen("test.txt","r",stdin);
	cin >> s;
	R(i,s.size())
	{
		if(s[i] == ')')
		{
			match[i] = st.top();
			match[st.top()] = i;
			st.pop();
		}
		else st.push(i);
	}
	LL ans = 0;
	memset(d,-1,sizeof d);
	printf("%d\n",dp(0,s.size()-1,0,0));
	return 0;
}

