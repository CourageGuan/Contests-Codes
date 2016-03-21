/*小学奥赛题目，画线分饼(找规律)
  line 0 1 2 3 4 5...
  pack 1 2 4 7 11 16...*/
#include<iostream>
using namespace std;

int main()
{
	long long n;
	cin>>n;
	cout<<(n+1)*n/2+1<<endl;
	return 0;
}
