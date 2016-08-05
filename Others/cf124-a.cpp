#include<bits/stdc++.h>
using namespace std;

const double pi = acos(-1.0);

int main()
{
//	freopen("test.txt","r",stdin);
	int a,b,r;
	cin >> a >> b >> r;
	puts(a >= 2*r && b >= 2*r ?"First":"Second");
	return 0;
}
