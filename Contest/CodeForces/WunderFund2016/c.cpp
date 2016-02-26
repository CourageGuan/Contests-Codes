#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

struct Point{
	LL x,y;
	int id;
	Point() {}
	Point(LL x,LL y,int id):x(x),y(y),id(id) {}
	bool operator<(const Point& rhs) const
	{
		return x<rhs.x || (x == rhs.x && y<rhs.y);
	}
};

vector<Point> save;
int n;

bool judge(Point a,Point b,Point c)
{
	return !((b.x-a.x)*(c.y-a.y) == (c.x-a.x)*(b.y-a.y));
}

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		LL x,y;
		scanf("%lld %lld",&x,&y);
		save.push_back(Point(x,y,i+1));
	}
	sort(save.begin(),save.end());
	for(int i=2;i<save.size();++i)
	{
		if(judge(save[0],save[1],save[i]))
		{
			printf("%d %d %d\n",save[0].id,save[1].id,save[i].id);
			return 0;
		}
	}
	return 0;
}
