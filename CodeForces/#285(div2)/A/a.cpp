#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int a,b,c,d;
	cin>>a>>b>>c>>d; 
	int m=max(3*a/10,a-a/250*c),v=max(3*b/10,b-b/250*d);
	if(m==v) cout<<"Tie"<<endl;
	if(m>v) cout<<"Misha"<<endl;
	if(m<v) cout<<"Vasya"<<endl;
	return 0;
}

