#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()
{
//	freopen("input.txt","r",stdin);
	int m, n;
	int kase = 1;
	int tmp;
	int minval = 99999;
	while ( scanf( "%d%d", &m, &n ) == 2 )
	{
		minval = 999999;
		if ( m == 0 && n == 0 )
			break;
		for ( int i = 0; i < m; ++i )	
		{
			scanf( "%d", &tmp );
			minval = min( minval, tmp );
		}
		for ( int i = 0; i < n; ++i )
			scanf( "%d", &tmp );
		if ( n >= m )
			printf( "Case %d: 0\n", kase );
		else
		{
			printf( "Case %d: %d %d\n", kase, m - n, minval );
		}
		kase++;
	}
	return 0;
}
