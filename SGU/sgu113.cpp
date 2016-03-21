/*判断是否存在两个质因子之积为这个数，朴素算法即可*/
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

bool prime(int n)
{
	if(n==1) return false;
	if(n==2) return true;
	for(int i=2;i<=((int)sqrt(n)+1);++i)
		if (n%i==0) return false;
	return true;
}

bool solve(int m)
{
	for(int i=2;i<=(int)sqrt(m)+1;++i)
		if(m%i==0 && prime(i) && prime(m/i)) return true;
	return false;
}

int main()
{
	int n;
	cin>>n;
	while(n--){
		int m;
		cin>>m;
		puts(solve(m)?"Yes":"No");
	}
	return 0;
}
