#include<bits/stdc++.h>
using namespace std;

const int maxn = 1010;
const int maxd = 2e6+10;
int n;
vector<int> odd,even;
bool prime[maxd];


void init()
{
	memset(prime,1,sizeof prime);
	prime[1] = 0;
	for(int i=2;i<maxd;++i)
	{
		if(prime[i])
			for(int j=i+i;j<maxd;j+=i) prime[j] = 0;
	}
}

int main()
{
	//freopen("test.txt","r",stdin);
	int t;
	scanf("%d",&n);
	init();
	for(int i=0;i<n;++i)
	{
		scanf("%d",&t);
		if(t&1) odd.push_back(t);
		else even.push_back(t);
	}
	int one = 0;
	for(int i=0;i<odd.size();++i) if(odd[i] == 1) ++one;
	if(one >= 2)
	{
		for(int i=0;i<even.size();++i)
			if(prime[even[i]+1])
			{
				printf("%d\n",one+1);
				for(int j=0;j<one;++j) printf("1 ");
				printf("%d\n",even[i]);
				return 0;
			}
		printf("%d\n",one);
		for(int j=0;j<one;++j) printf("1 ");
		puts("");
		return 0;
	}
	else
	{
		for(int i=0;i<odd.size();++i)
			for(int j=0;j<even.size();++j)
				if(prime[odd[i]+even[j]])
				{
					puts("2");
					printf("%d %d\n",odd[i],even[j]);
					return 0;
				}
	}
	puts("1");
	printf("%d\n",t);
	return 0;
}


