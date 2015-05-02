#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<map>
#include<vector>
#include<set>
using namespace std;


int main()
{
	//freopen("test.txt","r",stdin);
	//freopen("a.out","w",stdout);
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(3);
	a.push_back(3);
	a.push_back(4);
	a.push_back(5);
	cout<<(a.end()-upper_bound(a.begin(),a.end(),3))<<endl;	
	return 0;
}
