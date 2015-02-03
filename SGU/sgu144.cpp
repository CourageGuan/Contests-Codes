/*线性规划，sgu越做越欢乐...*/
#include<iostream>
#include<cstdio>
using namespace std;

#define pow(t) ((t)*(t))

int main()
{
	double x,y,z;
	cin>>x>>y>>z;
	printf("%.7lf\n",1-pow(1-(z/(60*(y-x)))));
	return 0;
}
