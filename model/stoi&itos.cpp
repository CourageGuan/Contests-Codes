#include <iostream>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <string>
using namespace std;

long long stoi(string s)
{
	long long n;
	int len=s.size();
	for(int i=0;i<=len-1;i++)
	{
		n+=s[i]-48;
		n*=10;
	}
	return n/10;
}

string itos(long long n)
{
	char s[50];
	int len=(int)log10(n)+1;
	for(int i=len-1;i>=0;i--)
	{
		s[i]=(char)(n%10+48);
		n/=10;
	}
	string ss=s;
	return ss;
}

int main()
{
	srand(time(0));
	//freopen("test","w",stdout);
	string s;
	cin>>s;
	cout<<itos(stoi(s));
	return 0;
}

