#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
char s[maxn];

char match[] = {'[',']','<','>','(',')','{','}'};

stack<char> st;

int getpos(char c)
{
	for(int i=0;i<8;++i) if(c == match[i]) return i;
	return -1;
}

int main()
{
	scanf("%s",s);
	int n = strlen(s);
	int ans = 0;
	for(int i=0;i<n;++i)
	{
		if(!st.empty())
		{
			char ch = st.top();
			int p1 = getpos(ch),p2 = getpos(s[i]);
			if(p1&1)
				break;
			else
			{
				if(p2&1)
				{
					st.pop();
					ans += (p1+1 != p2);
				}
				else
					st.push(s[i]);
			}
		}
		else st.push(s[i]);
	}	
	if(st.empty()) printf("%d\n",ans);
	else puts("Impossible");
	return 0;
}
