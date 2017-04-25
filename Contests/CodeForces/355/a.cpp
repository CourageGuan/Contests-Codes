#include<bits/stdc++.h>
using namespace std;
typedef long long LL;


int main()
{
	//freopen("test.txt","r",stdin);
	int n,h	;
	cin >> n >> h;
	int sum = 0;
	for(int i=0;i<n;++i) 
	{
		int a;
		cin >> a;
		sum += (a > h?2:1);
	}
	cout << sum << '\n';
	return 0;
}
