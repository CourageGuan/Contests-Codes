#include<bits/stdc++.h>
using namespace std;

const int maxn = 110;
int d[maxn*2];
char s[maxn];


int main()
{
//	freopen("test.txt","r",stdin);
	int n,p,q;
	scanf("%d %d %d",&n,&p,&q);
	scanf("%s",s);
	memset(d,0,sizeof d);
	d[0] = 1;
	for(int i=0;i<n;++i)
	{
		if(d[i])
		{
			d[i+p] = 1;
			d[i+q] = 1;
		}
	}
	if(!d[n]) puts("-1");
	else
	{
		int cnt = 0,cur = n;
		vector<int> pos;
		pos.push_back(n);
		while(cur)
		{
			if(cur - p >= 0 && d[cur - p])
			{
				pos.push_back(cur - p);
				cur -= p;
			}
			if(cur - q >= 0 && d[cur-q])
			{
				pos.push_back(cur - q);
				cur -= q;
			}
		}
		printf("%d\n",pos.size()-1);
		cur = 0;
		for(int i=pos.size()-1;i>0;--i)
		{
			for(int j=pos[i];j<pos[i-1];++j) putchar(s[j]);
			puts("");
		}
	}
	return 0;
}
