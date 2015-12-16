#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char board[11][11];
bool checked[11][11];

void wall()
{
	for ( int i = 0; i < 11; ++i )
	{
		board[i][0] = 'x';
		board[0][i] = 'x';
		board[10][i] = 'x';
		board[i][10] = 'x';
	}
}

void read()
{
	char line[9];
	for ( int i = 0; i < 9; ++i )
		for ( int j = 0; j < 9; ++j )
			cin >> board[i+1][j+1];
}

int dfs( int i, int j, int rec )
{
	if ( checked[i][j] )
		return 0;

	//printf( "[%d] search (%d,%d) char=%c\n", rec, i, j, board[i][j] );

	int ans = 0;

	if ( board[i][j] == 'x' )
		return 0;

	checked[i][j] = true;

	if ( board[i][j] == '.' )
		return 1;

	if ( i != 0 )
		ans += dfs( i - 1, j, rec + 1 );
	if ( j != 0 )
		ans += dfs( i, j - 1, rec + 1 );
	if ( i != 10 )
		ans += dfs( i + 1, j, rec + 1 );
	if ( j != 10 )
		ans += dfs( i, j + 1, rec + 1 );
	
	return ans;
}

bool solve()
{
	memset( board, 0, 11 * 11 );
	memset( checked, 0, 11 * 11 );
	wall();
	read();

	//for ( int i = 0; i < 11; ++i, printf( "\n" ) )
	//	for ( int j = 0; j < 11; ++j )
	//		printf( "%c", board[i][j] );

	bool ans = false;

	for ( int i = 0; i < 11; ++i )
		for ( int j = 0; j < 11; ++j )
			if ( board[i][j] == 'o' && !checked[i][j] )
			{
				memset( checked, 0, 11 * 11 );
				int x = dfs( i, j, 0 );
				//printf( "dfs at (%d,%d) result=%d\n", i, j, x );
				if ( x == 1 )
					return true;
			}
	return false;
}

int main()
{
	freopen( "test.txt", "r", stdin );
	int T; cin >> T;
	for ( int t = 1; t <= T; ++t )
	{
		if ( solve() )
			printf( "Case #%d: Can kill in one move!!!\n", t );
		else
			printf( "Case #%d: Can not kill in one move!!!\n", t );
	}
	return 0;
}

