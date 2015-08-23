//bfs，但是n=30状态数会爆表
//通过打印发现对于相同的p,e,t，随着k增大，相邻两个k之间的概率差会越来越小
//这题精度要求只有1e-5，所以只bfs最多到n=20就行了
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>

using namespace std;

int K;
double R,L,P,E,T;

struct Node
{
	int k;
	double l,r,p;
	Node(int k,double l,double r,double p):k(k),l(l),r(r),p(p) {}
}; 
double bfs(int k)
{
	queue<Node> Q;
	Q.push(Node(0,L,R,1));
	double ans = 0;
	while(!Q.empty())
	{
		Node p = Q.front(); Q.pop();
		if(p.k == k)
		{
			double h = (p.l+p.r)/2;
			if(fabs(h-T)<=E) ans+=p.p;
			continue;
		}
		double h = (p.l+p.r)/2;
//		printf("%lf\n",h);
		if(h>=T)
		{
			Q.push(Node(p.k+1,h,p.r,p.p*(1-P)));
			Q.push(Node(p.k+1,p.l,h,p.p*P));
		}
		else
		{
			Q.push(Node(p.k+1,p.l,h,p.p*(1-P)));
			Q.push(Node(p.k+1,h,p.r,p.p*P));
		}
	}
	return ans;
}	

int main()
{
	//freopen("test.txt","r",stdin);
	while(scanf("%d %lf %lf %lf %lf %lf",&K,&R,&L,&P,&E,&T)==6)
	{
		if(K<=20) printf("%lf\n",bfs(K));
		else printf("%lf\n",bfs(20));
	}
	return 0;
}


