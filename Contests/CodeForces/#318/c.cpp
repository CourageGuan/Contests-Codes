#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	int cur = -1;
	bool flag = true;
	for(int i=0;i<n;++i)
	{
		int x;
		scanf("%d",&x);
		if(flag == false) continue;
		while(x%2 == 0) x/=2;
		while(x%3 == 0) x/=3;
		if(cur != -1 && cur!=x) flag = false;
		cur = x;
	}
	puts(flag?"Yes":"No");
	return 0;
}
