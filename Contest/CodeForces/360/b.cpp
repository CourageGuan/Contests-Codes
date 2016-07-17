#include<bits/stdc++.h>
using namespace std;

string s,t;

int main()
{
	cin >> s;
	t = s;
	reverse(t.begin(),t.end());
	s = s + t;
	cout << s;
	return 0;
}
