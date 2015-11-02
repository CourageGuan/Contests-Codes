#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<n;++i)
const int sz = 9;
const int P[6][3] = {{0,1,2},{0,2,1},{1,0,2},{1,2,0},{2,0,1},{2,1,0}};

int pic[sz][sz];
int ans,cnt;

int gcd(int a,int b)
{
	return !b?a:gcd(b,a%b);
}

void input()
{
	rep(i,sz) rep(j,sz) scanf("%d",&pic[i][j]);

	rep(i,sz)
	{
		int sum = 0;
		rep(j,sz) sum += pic[i][j];
		assert(sum == 45);	
	}

	rep(j,sz)
	{
		int sum = 0;
		rep(i,sz) sum += pic[i][j];
		assert(sum == 45);	
	}
}

void output()
{
	rep(i,sz)
	{
		rep(j,sz) printf("%d ",pic[i][j]);
		puts("");
	}
	puts("-*-*-*-*-*-*-*-*-*-*-*-*-*");
}

bool check()
{
	rep(i,sz)
	{
		if(pic[i][i] == 1 || pic[i][sz - 1 - i] == 1 ) return true;
		if(pic[i][i] == 2 || pic[i][sz - 1 - i] == 2 ) return true;
	}
	return false;
}

void SWAP(int a,int b)
{
	for(int i=0;i<sz;++i) swap(pic[i][a],pic[i][b]);
}

void make(int num,int p)
{
	switch(p)
	{
		case 0:break;
		case 1:swap(pic[num*3+1],pic[num*3+2]);break;
		case 2:swap(pic[num*3],pic[num*3+1]);break;
		case 3:swap(pic[num*3],pic[num*3+1]);swap(pic[num*3+1],pic[num*3+2]);break;
		case 4:swap(pic[num*3],pic[num*3+1]);swap(pic[num*3],pic[num*3+2]);break;
		case 5:swap(pic[num*3],pic[num*3+2]);break;
	}
}

void MAKE(int num,int p)
{
	switch(p)
	{
		case 0:break;
		case 1:SWAP(num*3+1,num*3+2);break;
		case 2:SWAP(num*3,num*3+1);break;
		case 3:SWAP(num*3,num*3+1);SWAP(num*3+1,num*3+2);break;
		case 4:SWAP(num*3,num*3+1);SWAP(num*3,num*3+2);break;
		case 5:SWAP(num*3,num*3+2);break;
	}
}

void solve()
{
	input();

	cnt = 0;
	ans = 0;
	int tmp[sz][sz],tmp1[sz][sz],tmp2[sz][sz],tmp3[sz][sz],tmp4[sz][sz],tmp5[sz][sz];
	memcpy(tmp,pic,sizeof pic);

	rep(a,6)
	{
		memcpy(pic,tmp,sizeof pic);
		make(0,a);
		memcpy(tmp1,pic,sizeof pic);

		rep(b,6)
		{
			memcpy(pic,tmp1,sizeof pic);
			make(1,b);
			memcpy(tmp2,pic,sizeof pic);
			rep(c,6)
			{
				memcpy(pic,tmp2,sizeof pic);
				make(2,c);
				memcpy(tmp3,pic,sizeof pic);

				rep(i,6) 
				{
					memcpy(pic,tmp3,sizeof pic);
					MAKE(0,i);
					memcpy(tmp4,pic,sizeof pic);

					rep(j,6)
					{ 
						memcpy(pic,tmp4,sizeof pic);
						MAKE(1,j);
						memcpy(tmp5,pic,sizeof pic);

						rep(k,6)
						{
							memcpy(pic,tmp5,sizeof pic);
							MAKE(2,k);
							++cnt;
							if(!check())
							{
							   	++ans;
							}
						}
					}
				}
			}
		}
	}
	int t = gcd(ans,cnt);
	printf("%d/%d\n",ans/t,cnt/t);
	// ans/cnt *  6670903752021072936960 --- by python
}

int main()
{
	freopen("test.txt","r",stdin);
	rep(i,3) solve();
	return 0;
}


