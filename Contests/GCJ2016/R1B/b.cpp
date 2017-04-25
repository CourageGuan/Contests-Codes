#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3f;

const int maxn = 50;
LL res;
LL rA,rB;
char s[maxn];
char t[maxn];
int len;

void dfs(int cur,int flag,LL A,LL B)  //0 == , 1 s > t , 2 s < t
{
   // printf("*****%d  %d %llu  %llu\n",cur,flag,A,B);
    if(cur >= len)
    {
        LL t;
		if(A > B) t = A-B;
		else t = B-A;
        if(res < 0)
        {
            res = t;
            rA = A;
            rB = B;
        }
        else if(t < res || (t == res && A < rA) ||
            (t == res && A == rA && B < rB))
        {
            res = t;
            rA = A;
            rB = B;
        }
        return;
    }

    if(flag == 0)
    {
        if(s[cur] == '?' && t[cur] == '?')
        {
            dfs(cur+1,0,A*10,B*10);
            dfs(cur+1,2,A*10+0,B*10+1);
            dfs(cur+1,1,A*10+1,B*10+0);
        }
        else if(s[cur] == '?')
        {
            LL c = t[cur]-'0';
            dfs(cur+1,0,A*10+c,B*10+c);
            if(c != 9)
                dfs(cur+1,1,A*10+c+1,B*10+c);
            if(c != 0)
                dfs(cur+1,2,A*10+c-1,B*10+c);
        }
        else if(t[cur] == '?')
        {

            LL c = s[cur]-'0';
            dfs(cur+1,0,A*10+c,B*10+c);
            if(c != 9)
                dfs(cur+1,2,A*10+c,B*10+c+1);
            if(c != 0)
                dfs(cur+1,1,A*10+c,B*10+c-1);

        }
        else
        {
            LL c1 = s[cur]-'0';
            LL c2 = t[cur]-'0';
            int tflag;
            if(c1 == c2)
                tflag = 0;
            else if(c1 > c2)
                tflag = 1;
            else
                tflag = 2;
            dfs(cur+1,tflag,A*10+c1,B*10+c2);
        }


    }
    else if(flag == 1)
    {
        LL nxtA = A;
        LL nxtB = B;
        if(s[cur] == '?')
            nxtA = nxtA * 10;
        else
            nxtA = nxtA * 10 + s[cur]-'0';
        if(t[cur] == '?')
            nxtB = nxtB * 10 + 9;
        else
            nxtB = nxtB * 10 + t[cur]-'0';
        dfs(cur+1,flag,nxtA,nxtB);
    }
    else
    {
        LL nxtA = A;
        LL nxtB = B;
        if(s[cur] == '?')
            nxtA = nxtA * 10 + 9;
        else
            nxtA = nxtA * 10 + s[cur]-'0';
        if(t[cur] == '?')
            nxtB = nxtB * 10;
        else
            nxtB = nxtB * 10 + t[cur]-'0';
        dfs(cur+1,flag,nxtA,nxtB);
    }

}


char buf[maxn];


int con(LL num)
{
    int cur = 0;
    while(num)
    {
        buf[cur++] = num%10 + '0';
        num /= 10;
    }
    reverse(buf,buf+cur);
    return cur;
}

void print(LL num)
{
    memset(buf,0,sizeof(buf));
    int t = con(num);
    int need = len-t;
    for(int i = 0;i < need;++i)
        putchar('0');
    printf("%s",buf);
}

int main()
{
    //freopen("./test.txt","r",stdin);
    freopen("./B-large.in","r",stdin);
    freopen("./out.txt","w",stdout);
    int kase;
    scanf("%d",&kase);
    for(int z = 1;z <= kase;++z)
    {
        scanf("%s %s",s,t);
        len = strlen(s);
        res = -1;
        dfs(0,0,0,0);
        printf("Case #%d: ",z);
        print(rA);
        putchar(' ');
        print(rB);
        putchar('\n');

    }

    return 0;
}

