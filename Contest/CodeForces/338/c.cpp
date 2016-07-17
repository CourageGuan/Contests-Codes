#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define fi first
#define se second
#define mp make_pair 

const int maxn = 2120;
vector<pair<int,int> > ans;

char s[maxn],t[maxn];
int f[maxn];

void getFail(string P)
{
	int m = P.size();
	f[0] = f[1] = 0;
	for(int i=1;i<m;++i)
	{
		int j = f[i];
		while(j && P[j]!=P[i]) j = f[j];
		f[i+1] = P[j] == P[i] ? j+1 : 0;
	}
}

pair<int,int> find(string P,string T)
{
	int m = P.size(),n = T.size();
	int j = 0;
	int pos = 0,len = 0;
	getFail(P);
	for(int i=0;i<n;++i)
	{
		while(j && P[j]!=T[i]) j = f[j];
		if(P[j]==T[i]) ++j;
		if(j > len)
		{
			len = j;
			pos = i;
		}
		if(len >= m) break;
	}
	return mp(pos,len);
}

int cal()
{
	string S(s),T(t),rT(t);
	reverse(rT.begin(),rT.end());	
	pair<int,int> p0,p1;
	int cnt = 0;
	while(S.size())
	{
		string pre = S;
		p0 = find(S,T);
		p1 = find(S,rT);
		//cout<<S<<endl;
		if(p0.se >= p1.se)
		{
			++cnt;
			ans.push_back(mp(p0.fi - p0.se+2,p0.fi+1));
			S = S.substr(p0.se,S.size());
		}
		else
		{
			++cnt;
			ans.push_back(mp(T.size() - (p1.fi - p1.se+2)+1,T.size() - (p1.fi + 1)+1 ));
			S = S.substr(p1.se,S.size());
		}
		if(S == pre) return -1;
	}
	return cnt;
}

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%s %s",t,s);
	int res = cal();
	printf("%d\n",res);
	if(res != -1)  for(int i=0;i<ans.size();++i) printf("%d %d\n",ans[i].fi,ans[i].se);
	return 0;
}




