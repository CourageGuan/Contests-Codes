#include<stdio.h>
#include<cstring>
#include<algorithm>

using namespace std;

const int maxn = 200;
char s[maxn];
char ss[20] = "anniversary";
const int len2 = 11;
int len1;

bool dfs(int cur,int r1,int r2,int op)
{
	if(r2 == len2)
	{
		if(cur <= 3) return true;
		else return false;
	}
	if(r1 >= len1) return false;
	bool flag = false;
	if(s[r1] == ss[r2]) 
	{
		if(op) flag |= dfs(cur,r1+1,r2+1,1);
		else flag |= dfs(cur+1,r1+1,r2+1,1);
	}
	flag |= dfs(cur,r1+1,r2,0);
	return flag;
}

int main()
{
 //   freopen("test.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",s);
        bool flag = false;
        len1 = strlen(s);
        for(int i=0;i<len1;++i)
        {
            if(s[i]=='a')
               if(dfs(0,i,0,0))
               {
                      flag = true;
                    break;
               }
        }
        puts(flag?"YES":"NO");
    }
    return 0;
}

