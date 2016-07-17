#include<bits/stdc++.h>
using namespace std;

int cnt[10];
int n;
string s;

bool judge()
{
	if(cnt[1] && cnt[9]+cnt[0]) return true;
	if(cnt[2] && cnt[0]) return true;
	if(cnt[3] && cnt[7]+cnt[0]) return true;

	if(cnt[1] && cnt[6] && cnt[7]) return true;
	if(cnt[3] && cnt[4] && cnt[9]) return true;
	if(cnt[2] && cnt[4] && cnt[9]) return true;
	if(cnt[2] && cnt[7] && cnt[9]) return true;
	if(cnt[2] && cnt[7] && cnt[6]) return true;

	return false;
}

int main()
{

	cin >> n;
	cin >> s;

	for(int i=0;i<n;++i)
	{
		++cnt[s[i]-'0'];
	}

	puts(judge()?"YES":"NO");
	return 0;
}
