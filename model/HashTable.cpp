#include<cstdio>
#include<cstring>
using namespace std;

const int maxn=100000 + 10;
const long long mod=100007;

struct HashTable{
	struct Edge{
		long long num;
		int next;
	} edges[maxn<<1];
	int head[mod + 5];
	int size;

	void init()
	{
		memset(head,-1,sizeof(head));
		size=0;
	}

	void add(long long num)
	{
		int start=num%mod;
		edges[size].next=head[start];
		edges[size].num=num;
		head[start]=size;
		size++;
	}

	int find(long long num)
	{
		int start=num%mod;
		int pos;
		for(pos=head[start]; pos!=-1; pos=edges[pos].next) if(num==edges[pos].num) break;
		return pos;
	}
} hash;

int main()
{
	int n;
	scanf("%d",&n);
	hash.init();
	for(int i=0;i<n;++i){
		long long t;
		scanf("%lld",&t);
		hash.add(t);
	}
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		long long t;
		scanf("%lld",&t);
		printf("%d\n",hash.find(t));
	}
	return 0;
}

