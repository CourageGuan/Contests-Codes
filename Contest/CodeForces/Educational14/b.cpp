#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

char cset[] = "AHIMOoTUVvWwXxY";

int main()
{
	//freopen("test.txt","r",stdin);
	string s;
	cin >> s;
	for(int i=0;i<=s.size()/2;++i)
	{
		int j = s.size()-i-1;
		if(s[i] != s[j])
		{
			if((s[i] == 'b' && s[j] == 'd') || (s[i] == 'd' && s[j] == 'b') || (s[i] == 'p' && s[j] == 'q') || (s[i] == 'q' && s[j] == 'p') ) continue;
			puts("NIE");
			return 0;
		}
		else
		{
			bool flag = false;
			for(int k=0;k<strlen(cset);++k) if(s[i] == cset[k])
			{
				flag = true;
				break;
			}
			if(flag) continue;
			puts("NIE");
			return 0;
		}
	}
	puts("TAK");
	return 0;
}
