#include<iostream>
#include<iomanip>
#include<cassert>
#include<cmath>
using namespace std;

typedef long double LDB;

int main()
{
	LDB a,b,c;
	cin>>a>>b>>c;
	assert(a != 0);
	LDB q = sqrtl(b*b - 4*a*c); 
	LDB r1 = (-b+q)/2/a,r2 = (-b-q)/2/a;
	if(r1 < r2) swap(r1,r2);
	cout << setprecision(23) << r1 << '\n' << r2 << '\n'; 
	return 0;
}
