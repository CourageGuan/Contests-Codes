#include<stdio.h>
#include<string.h>

const int maxn = 260;

struct F
{
    int m,s;
    F(int m = 0,int s = 0):m(m),s(s) {}
};

struct House
{
    int num,c,s;
    House(int num = 0,int c = 0,int s = 0):num(num),c(c),s(s) {}
};

int n;
int fn,hn;
F frd[maxn];
House house[maxn];
int can,s1,s2;

int main()
{
 //   freopen("./test.txt","r",stdin);
    scanf("%d %d %d",&can,&s1,&s2);
    //puts("OK");
    scanf("%d",&fn);
    for(int i = 0;i < fn;++i)
        scanf("%d %d",&frd[i].m,&frd[i].s);
    scanf("%d",&hn);
    for(int i = 0;i < hn;++i)
        scanf("%d %d %d",&house[i].num,&house[i].c,&house[i].s);

   // for(int i = 0;i < hn;++i)
     //   printf("%d %d %d",house[i].num,house[i].c,house[i].s);
//printf("%d\n",can);

    int cur = -1;
    int res = -1,mode = -1;
    int cf = -1;
    for(int i = 0;i < hn;++i)
    {
        if(can >= house[i].c)
        {//puts("OK");
            int t = house[i].s + (house[i].num == 1?s1:s2);
            if(t > cur)
                res = i,mode = 1,cur = t;
        }
        if(house[i].num == 2)
        {
            for(int j = 0;j < fn;++j)
            {
                if(2*can >= house[i].c && 2*frd[j].m >= house[i].c)
                {
                    int t = house[i].s + frd[j].s;
                    if(t > cur)
                        res = i,mode = 2,cf = j,cur = t;
                }
            }
        }
    }

    if(res == -1)
        puts("Forget about apartments. Live in the dormitory.");
    else
    {
        if(mode == 1)
        {
            printf("You should rent the apartment #%d alone.\n",res+1);
        }
        else
        {
            printf("You should rent the apartment #%d with the friend #%d.\n",res+1,cf+1);
        }
    }
    return 0;
}
