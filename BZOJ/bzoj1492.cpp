#include<bits/stdc++.h>

#define F(i,a,b) for(int i=(a);i<=(b);++i)

const int maxn = 1e5 + 10;
const double eps = 1e-9;

struct P
{
	int id;
	double x,y,r,a,b,k;
	bool operator<(const P& rhs) const
	{
		return k > rhs.k;
	}
} t[maxn],p[maxn];
double d[maxn];
int n,st[maxn];

double slope(int i,int j)
{
	if(!j) return -1e20;
	if(fabs(p[i].x-p[j].x) < eps) return 1e20;
   	return (p[i].y-p[j].y)/(p[i].x-p[j].x);
}

void cdq(int l,int r)
{
	if(l == r)
	{
		d[l] = std::max(d[l],d[l-1]);
		p[l].y = d[l]/(p[l].a*p[l].r + p[l].b);
		p[l].x = p[l].y*p[l].r;
		return;
	}
	int m = (l+r)>>1,top=0,l1 = l,l2 = m+1,j=1;
	F(i,l,r) if(p[i].id <= m) t[l1++] = p[i]; else t[l2++] = p[i];
	F(i,l,r) p[i] = t[i];
	cdq(l,m);
	F(i,l,m)
	{
		while(top > 1 && slope(st[top-1],st[top]) < slope(st[top],i)+eps) --top;
		st[++top] = i;
	}
	st[++top] = 0;
	F(i,m+1,r)
	{
		while(j < top && slope(st[j],st[j+1])+eps > p[i].k) ++j;
		d[p[i].id] = std::max(d[p[i].id],p[st[j]].x*p[i].a+p[st[j]].y*p[i].b);
	}
	cdq(m+1,r);

	l1 = l,l2 = m+1;
	F(i,l,r)
		if(l1 <= m && (l2>r || p[l1].x < p[l2].x)) t[i] = p[l1++];
		else t[i] = p[l2++];
	F(i,l,r) p[i] = t[i];
}


int main()
{
	//freopen("input.txt","r",stdin);
	scanf("%d%lf",&n,&d[0]);
	F(i,1,n)
	{
		scanf("%lf%lf%lf",&p[i].a,&p[i].b,&p[i].r);
		p[i].id = i;
		p[i].k = -p[i].a/p[i].b;
	}
	std::sort(p+1,p+1+n);
	cdq(1,n);
	printf("%.3lf\n",d[n]);
	return 0;
}
