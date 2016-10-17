#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string s;
inline int find(string s)
{
	int i,j,k,l,N = s.length(); s += s;
	for(i=0,j=1;j < N;)
	{
		for(k=0;k<N && s[i+k] == s[j+k];++k);
		if(k >= N) break;
		if(s[i+k]<s[j+k]) j += k+1;
		else l=i+k,i=j,j=max(l,j)+1;
	}	
//	cout << s.substr(i,N) << '\n';
	return i;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		cin >> s;
		printf("%d\n",find(s)+1);
	}
	return 0;
}
