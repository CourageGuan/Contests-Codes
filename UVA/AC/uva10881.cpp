//跳跃性思维
//蚂蚁相碰可以视为穿过,而对于输入的每只蚂蚁的相对位置不变
//因此按照与最左端距离排序后可知输入的蚂蚁在哪个位置，所以之后的状态只需按每只蚂蚁目前朝向前进Tcm然后再排序，因为相对位置不变，可以按照输入顺序输出。
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn=10000 + 5;

const char dirName[3][10]={"L","Turning","R"};

struct Ant{
	int d;
	int turn;
	int id;

	bool operator<(const Ant& rhs ) const {
		return d<rhs.d;
	}

	void init(int id,int d,char ch[])
	{
		switch(ch[0]){
			case 'L': turn=-1;break;
			case 'R': turn=1;break;
			case 'T': turn=0;break;
		}
		this->d=d;
		this->id=id;
	}

} before[maxn],after[maxn];

int order[maxn];

int main()
{
	//freopen("test","r",stdin);
	int L,T,N,n,kase=0;
	char turn[10];
	scanf("%d\n",&N);
	while(N--){
		printf("Case #%d:\n",++kase);
		scanf("%d %d %d",&L,&T,&n);
		int dis;
		for(int i=0;i<n;++i){
			scanf("%d %s",&dis,turn);
			before[i].init(i,dis,turn);
			after[i].init(0,dis+before[i].turn*T,turn);
		}
		sort(before,before+n);
		for(int i=0;i<n;++i)
			order[before[i].id]=i;
		sort(after,after+n);
		for(int i=0;i<n-1;++i)
			if(after[i].d==after[i+1].d) after[i].turn=after[i+1].turn=0;
		for(int i=0;i<n;++i){
			int t=order[i];
			if(after[t].d<0 || after[t].d>L) puts("Fell off"); 
			else printf("%d %s\n",after[t].d,dirName[after[t].turn+1]);
		}
		puts("");
	}
	return 0;
}
