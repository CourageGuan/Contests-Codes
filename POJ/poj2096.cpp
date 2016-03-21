//概率dp入门
//求期望用逆推 d[i][j] 表示所选bug，有i个分类，分别属于j个子系统
//其可以推到 
//i/n+j/s d[i][j] 
//(n-i)/n+j/s d[i+1][j]
//i/n+s-j/s d[i][j+1]
//(n-i)/n + d[i+1][j+1]
//四个阶段
//然后将递推式移项
#include<cstdio>
#include<cstring>

const int maxn = 1010;
double d[maxn][maxn];
int n,s;

int main()
{
	while(scanf("%d %d",&n,&s)==2)
	{
		d[n][s] = 0;
		for(int i=n;i>=0;--i)
		{
			for(int j=s;j>=0;--j)
			{
				if(i==n && j==s) continue;
				d[i][j] = ((n-i)*j*d[i+1][j] + i*(s-j)*d[i][j+1] + (n-i)*(s-j)*d[i+1][j+1] + n*s)/(n*s - i*j);
			}
		}
		printf("%.4f",d[0][0]);
	}
	return 0;
}
