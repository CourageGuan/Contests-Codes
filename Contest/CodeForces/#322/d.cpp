#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int c[8][3] = {{0,0,0},{0,0,1},{0,1,0},{0,1,1},{1,0,0},{1,0,1},{1,1,0},{1,1,1}};
const int p[6][3] = {{0,1,2},{0,2,1},{1,0,2},{1,2,0},{2,0,1},{2,1,0}};
const char ch[3] = {'A','B','C'};

int x[3][2];


int main()
{
	//freopen("test.txt","r",stdin);
	for(int i=0;i<3;++i)
	{
		scanf("%d %d",&x[i][0],&x[i][1]);
	}
	int n = -1;
	for(int i=0;i<6;++i)
	{
		int p0 = p[i][0],p1 = p[i][1],p2 = p[i][2];
		for(int j=0;j<8;++j)
		{
			int c0 = c[j][0],c1 = c[j][1],c2 = c[j][2];
			int d0 = c0^1,d1 = c1^1,d2 = c2^1;
			int t = x[p0][c0];
			if(t == x[p1][c1] && t == x[p2][c2] && (t == x[p0][d0] + x[p1][d1] + x[p2][d2]))
			{
				n = t;
				printf("%d\n",t);
				for(int i=0;i<x[p0][d0];++i)
				{
					for(int j=0;j<n;++j) 
						putchar(ch[p0]);
					puts("");
				}
				for(int i=0;i<x[p1][d1];++i)
				{
					for(int j=0;j<n;++j) 
						putchar(ch[p1]);
					puts("");
				}
				for(int i=0;i<x[p2][d2];++i)
				{
					for(int j=0;j<n;++j) 
						putchar(ch[p2]);
					puts("");
				}
				break;
			}
			if(t == (x[p1][d1] + x[p2][d2]) && (x[p1][c1] == x[p2][c2]) && (t ==  x[p2][c2] + x[p0][d0]))
			{
				n = t;
				printf("%d\n",t);
				for(int i=0;i<x[p0][d0];++i)
				{
					for(int j=0;j<n;++j) 
						putchar(ch[p0]);
					puts("");
				}
				for(int i=0;i<x[p1][c1];++i)
				{
					for(int j=0;j<x[p1][d1];++j) putchar(ch[p1]);
					for(int j=0;j<x[p2][d2];++j) putchar(ch[p2]);
					puts("");
				}
				break;
			}
		}
		if(n!=-1) break;
	}
	if(n==-1) printf("%d\n",-1);
	return 0;
}


