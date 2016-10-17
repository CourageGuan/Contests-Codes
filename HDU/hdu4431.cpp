#include<bits/stdc++.h>
using namespace std;

#define F(i,a,b) for(register int i=(a);i<=(b);++i)

int MJ[5][22];
int rem[22];

inline void init()
{
    memset(MJ,0,sizeof MJ);
	memset(rem,0,sizeof rem);
}

inline void input()
{
    char s[2];
    F(i,1,13)
    {
        scanf("%s",s);
        int t = s[0] - '0';
        if(s[1] == 'm')
            MJ[1][t]++,rem[1]++;
        if(s[1] == 's')
            MJ[2][t]++,rem[2]++;
        if(s[1] == 'p')
            MJ[3][t]++,rem[3]++;
        if(s[1] == 'c')
            MJ[4][t]++,rem[4]++;
    }
}

inline string get(register int j,int i)
{
    char ch[3];
    ch[0] = i+'0';
    ch[2] = '\0';
    switch(j)
    {
        case 1: ch[1]='m';break;
        case 2: ch[1]='s';break;
        case 3: ch[1]='p';break;
        case 4: ch[1]='c';break;
    }
    string res = ch;
    return res;
}

inline bool hu13()
{
    int er = 0;
    for(register int i=1;i<=3;++i)
    {
        if(!MJ[i][1] || !MJ[i][9]) return 0;
        if(MJ[i][1] == 2) ++er;
        if(MJ[i][9] == 2) ++er;
    }
    for(register int i=1;i<=7;++i)
	{
		if(!MJ[4][i]) return 0;
		if(MJ[4][i] == 2) ++er;
	}
    return er == 1;
}

inline bool hu7()
{
    for(register int i=1;i<=4;++i)
        for(register int j=1;j<10;++j)
        {
            if(i == 4 && j > 7) break;
            if(MJ[i][j] && MJ[i][j] != 2) return 0;
        }
    return 1;
}

bool dfs(register int x,int rem)
{
	if(x == 4)
	{
		for(register int i=1;i<=7;++i) if(MJ[4][i] && MJ[4][i] != 3) return 0;
		return 1;
	}

	if(!rem) return 1;
	if(rem%3) return 0;

	int flag = 0;

	for(register int i=1;i<=9;++i)
	{
		if(MJ[x][i])
		{
			--MJ[x][i];
			for(register int j=i;j<=min(i+1,9);++j)
			{
				if(MJ[x][j])
				{
					--MJ[x][j];
					for(register int k=j;k<=min(j+1,9);++k)
					{
						if(MJ[x][k])
						{
							--MJ[x][k];
							if((i == j && j == k) || (i + 1 == j && j + 1 == k))
								flag = dfs(x,rem-3);
							++MJ[x][k];
							if(flag) break;
						}
					}
					++MJ[x][j];
					if(flag) break;
				}
			}
			++MJ[x][i];
			if(flag) break;
		}
	}

	return flag;
}

inline bool judge()
{
    if(hu13()) return 1;
    if(hu7()) return 1;

    for(register int i=1;i<=4;++i)
    {
        for(register int j=1;j<10;++j)
        {
            if(i == 4 && j > 7) break;
            if(MJ[i][j] >= 2)
            {

                MJ[i][j] -= 2;
				rem[i] -= 2;
				if(dfs(1,rem[1]) && dfs(2,rem[2]) && dfs(3,rem[3]) && dfs(4,rem[4]))
				{
					MJ[i][j] += 2;
					rem[i] += 2;
					return 1;
				}
				rem[i] += 2;
                MJ[i][j] += 2;
            }
        }
    }
    return 0;
}

inline void solve()
{
    vector<string> ans;
    for(register int i=1;i<=4;++i)
    {
        for(register int j=1;j<10;++j)
        {
            if(i == 4 && j > 7) break;
            if(MJ[i][j] < 4)
            {
                //printf("%d %d\n",i,j);
                ++MJ[i][j];
				++rem[i];
                if(judge())
                {
                 //   printf("%d %d\n",i,j);
                    ans.push_back(get(i,j));
                }
				--rem[i];
                --MJ[i][j];
            }
        }
    }

    if(!ans.size())
	{
		puts("Nooten");
		return ;
	}
    printf("%d",ans.size());
    for(register int i=0;i<ans.size();++i) printf(" %s",ans[i].c_str());
    puts("");
}

int main()
{
    //freopen("test.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        init();
        input();
		solve();
    }
    return 0;
}
