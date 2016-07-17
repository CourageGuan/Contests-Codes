#include<bits/stdc++.h>
using namespace std;

int t,s,x;

bool yes()
{
	if(x == t) return true;
	x -= t;
	x -= s;
	if(x < 0) return false;
	if(x%s == 0) return true;
	x -= 1;
	if(x < 0) return false;
	if(x%s == 0) return true;
	return false;
}

int main()
{
	cin >> t>> s>> x;
	puts(yes()?"YES":"NO");
	return 0;
}
