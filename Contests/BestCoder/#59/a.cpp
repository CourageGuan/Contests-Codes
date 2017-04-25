#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long LL;
const int maxn = 110;

struct St
{
	char* name;
	double sc;
	int male;
	St() {}
	St(char *name,double sc,int male):name(name),sc(sc),male(male) {}
	bool operator<(const St& rhs) const
	{
		return sc > rhs.sc;
	}
};

vector<St> save;
double s1[maxn],s2[maxn];
char name[maxn][30],ma[maxn][10];

int main()
{
	//freopen("test.txt","r",stdin);
	int T;	
	scanf("%d",&T);
	while(T--)
	{
		int n,m;
		scanf("%d %d",&n,&m);
		puts("The member list of Shandong team is as follows:");
		double mx1 = 0,mx2 = 0;
		bool famale = false;
		for(int i=0;i<n;++i)
		{
			scanf("%s %s %lf %lf",name[i],ma[i],s1+i,s2+i);
			if(ma[i][0] == 'f') famale = true;
			mx1 = max(mx1,s1[i]);
			mx2 = max(mx2,s2[i]);
		}
		save.clear();
		for(int i=0;i<n;++i)
		{
			save.push_back(St(name[i],s1[i]*(300/mx1)*0.3+s2[i]*(300/mx2)*0.7,ma[i][0] == 'm'));
		}
		sort(save.begin(),save.end());
		for(int i=0;i<n;++i)
		{
			if(!m) break;
			if(m == 1 && famale && save[i].male) continue;
			if(!save[i].male && famale)
			{
				famale = false;
			}
			printf("%s\n",save[i].name);
			--m;
		}
	}
	return 0;
}



