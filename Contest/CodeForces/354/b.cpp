#include<bits/stdc++.h>
using namespace std;

double d[13][13];

int main()
{
	int n,t;
	cin >> n >> t;
	int sum = 0;
	memset(d,0,sizeof d);
	while(t--)
	{
		d[1][1] += 1;
		for(int i=n-1;i>=1;--i)
		{
			for(int j=1;j<=i;++j)
			{
				if(d[i][j] > 1)
				{
					d[i+1][j] += (d[i][j]-1)/2;
					d[i+1][j+1] += (d[i][j]-1)/2;
					d[i][j] = 1;
				}
			}
		}
	}
	for(int i=1;i<=n-1;++i)
	{
		for(int j=1;j<=i;++j)
		{
			if(d[i][j] > 1)
			{
				d[i+1][j] += (d[i][j]-1)/2;
				d[i+1][j+1] += (d[i][j]-1)/2;
				d[i][j] = 1;
			}
		}
	}
	for(int i=1;i<=n;++i) 
		for(int j=1;j<=i;++j)
		{
			if(d[i][j] >= 1) ++sum;
	//		cout << d[i][j] << endl;
		}
	cout << sum << '\n';
	return 0;
}
