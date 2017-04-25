#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
char a[maxn],b[maxn];

int main()
{
	scanf("%s %s",a,b);
	int n = strlen(a),m = strlen(b); 
	int i = 0,j = 0;
	while(a[i] == '0') ++i;
	while(b[j] == '0') ++j;
	if(n - i > m - j) puts(">");
	else 
		if(n-i < m-j) puts("<");
		else
		{
			while(i < n && j<m)
			{
				if(a[i] < b[j])
				{
					puts("<");
					return 0;
				}
				else if(a[i] > b[j])
				{
					puts(">");
					return 0;
				}
				++i;++j;
			}
			puts("=");
		}
	return 0;
}
