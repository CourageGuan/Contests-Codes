#include<cstdio>
#include<vector>
#include<iostream>
using namespace std;

template<class T>
bool lexSmaller(vector<T> a,vector<T> b)
{
	int n=a.size(),m=b.size();
	for(int i=0;i<m && i<n;++i)
		if(a[i]<b[i]) return true;
		else if(a[i]<b[i]) return false;
	return n<m;	
}

int main()
{
	vector<char> a,b;
	a.push_back('a');
	a.push_back('b');
	a.push_back('c');
	b.push_back('a');
	b.push_back('b');
	b.push_back('c');
	b.push_back('a');
	cout<<lexSmaller(a,b)<<endl;
	return 0;
}
