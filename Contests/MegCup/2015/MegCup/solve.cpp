#include<bits/stdc++.h>
using namespace std;

const int maxn = 110;
const int INF = 0x3f3f3f3f;
map<string,int> id;

double mo;

void init()
{
	mo = 0;
	for(int i=1;i<=16;++i)
	{
		mo += pow((double)i,-1.2);
	}
//	printf("%lf\n",(88888 - 4000)*1/mo);
}

struct P
{
	string name;
	bool vis[maxn];
	int t,num,t1;

	P()
	{
		memset(vis,0,sizeof vis);
		t1 = t = INF;
		num = 0;
	}

	bool operator<(const P& rhs) const
	{
		return num > rhs.num || (num == rhs.num && t1 < rhs.t1);
	}
} p[maxn];

vector<pair<string,double> > ans;

int main()
{
	//freopen("test.txt","r",stdin);
	freopen("megcup.in","r",stdin);
	freopen("out.txt","w",stdout);
	init();
	int cnt = 0;
	id.clear();
	int t;
	char ch ;
	string name,st;
	while(cin>>t>>ch>>st>>name)
	{
		if(id[name])
		{
			if(st != "WA")
			{
				p[id[name]].t1 = t;
				if(p[id[name]].vis[ch - 'A']) continue;
				p[id[name]].vis[ch - 'A'] = 1;
				++p[id[name]].num;
				if(p[id[name]].num<=5) p[id[name]].t = t;
			}
		}
		else
		{
			id[name] = ++cnt;
			p[id[name]].name = name;
			if(st != "WA")
			{
				p[id[name]].vis[ch - 'A'] = 1;
				++p[id[name]].num;
				p[id[name]].t = t;
				p[id[name]].t1 = t;
			}
		}
	}
//	printf("%d\n",cnt);
	sort(p+1,p+cnt+1);
	ans.clear();
	for(int i = 1; i <= cnt ; ++ i)
	{
	//	cout<<p[i].name<<" "<<p[i].num<<'\n';
		if(p[i].num >= 5)
			ans.push_back(make_pair(p[i].name,(double)(88888 - p[i].t)*pow(i,-1.2)/mo));
		else
			ans.push_back(make_pair(p[i].name,(double)(88888 - 55000)*pow(i,-1.2)/mo));
	}
	sort(ans.begin(),ans.end());
	for(int i=0;i<ans.size();++i) printf("%.2lf\t%s\n",ans[i].second,ans[i].first.c_str());
	return 0;
}

