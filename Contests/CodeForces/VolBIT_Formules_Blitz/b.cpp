#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

typedef long double LDB;

int main()
{
	LDB n,t;
	cin>>n>>t;
	cout << setprecision(23) << n*pow(1.000000011,t) <<'\n';
	return 0;
}
