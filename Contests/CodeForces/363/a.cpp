#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 2e5 + 10;
int x[maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	int n;
	cin >> n;
	string s;
	cin >> s;
	for(int i=0;i<n;++i) scanf("%d",x+i);
	int t = 0x3f3f3f3f;
	for(int i=1;i<n;++i) if(s[i-1] == 'R' && s[i] == 'L') t = min(t,(x[i]-x[i-1])/2);
	if(t == 0x3f3f3f3f)
		puts("-1");
	else
		printf("%d\n",t);
	return 0;
}
