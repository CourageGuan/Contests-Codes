#include<bits/stdc++.h>
using namespace std;

const int maxn = 1100 ;
string s[maxn];
string t;
int star[maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		cin >> n;
		for(int i=0;i<n;++i) cin >> s[i];
		getchar();
		getline(cin,t);
		memset(star,0,sizeof star);
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<t.size();++j)
			{
				if(j + s[i].size()-1 >= t.size()) break;
				bool flag = 1;
				for(int k=0;k<s[i].size();++k)
				{
					if(tolower(s[i][k]) != tolower(t[j+k]))
					{
						flag = 0;
						break;
					}
				}
				if(flag)
					for(int k=0;k<s[i].size();++k)
						star[k+j] = 1;
			}
		}
		for(int i=0;i<t.size();++i) if(star[i]) t[i] = '*';
		cout << t << '\n';
	}
	return 0;
}
