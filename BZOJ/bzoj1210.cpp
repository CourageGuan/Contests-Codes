//插头DP
//括号表示法
//这题会爆long long 所以要开高精度...
//最后答案*2因为有顺时针逆时针两种走法，注意n==1 or m==1 时要特判
#include<cstdio>
#include<cstring>
#include<stack>

using namespace std;
typedef long long LL;
const int HASH = 10007;
const int maxd = 100010;
int R,C,tx,ty;

const int MAX_LEN = 200;
const int BASE = 10000;
const int WIDTH = 4;

struct BigInteger
{
    int A[MAX_LEN];

    BigInteger(const char* num)
    {
        memset(A,0,sizeof(A));
        int len = strlen(num);
        int time = (len-1)/WIDTH+1;
        for(int i = 0;i < time;++i)
        {
            int end = len - i*WIDTH;
            int start = max(end-WIDTH,0);
            int t = 0;
            for(int j = start;j < end;++j)
                t = t*10 + (num[j]-'0');
            A[MAX_LEN-i-1] = t;
        }
    }


    BigInteger(long long num = 0)
    {
        memset(A,0,sizeof(A));
        for(int i = MAX_LEN-1;i >= 0;--i)
        {
            A[i] = num % BASE;
            num /= BASE;
        }
    }

    BigInteger(const BigInteger& num)
    {
        memcpy(A,num.A,MAX_LEN*sizeof(int));
    }

    void print()
    {
        int i = 0;
        while(i < MAX_LEN && !A[i]) i++;
        printf("%d",A[i++]);
        while(i < MAX_LEN)
            printf("%04d",A[i++]);   //如果改变WIDTH,这里也需要更改
    }

};

BigInteger operator + (const BigInteger& a,const BigInteger& b)
{
    BigInteger res;
    int g = 0;
    for(int i = MAX_LEN-1;i >= 0;--i)
    {
        g += a.A[i] + b.A[i];
        res.A[i] = g % BASE;
        g /= BASE;
    }
    return res;
}

struct HashTable
{
	int state[maxd];
	BigInteger d[maxd];
	int head[HASH],next[maxd],size;

	void clear()
	{
		size = 0;
		memset(head,-1,sizeof head);	
	}

	void push(int st,BigInteger ans)
	{
		int h = st%HASH;
		for(int i=head[h];i!=-1;i=next[i])
			if(st == state[i])
			{
				d[i] = d[i] + ans;
				return ;
			}
		state[size] = st;
		d[size] = ans;
		next[size] = head[h];
		head[h] = size++;
	}

} h[2];

struct  State
{
	int up[13];

	int encode()
	{
		int k = 0;
		for(int i=0;i<=C;++i)
		{
			k|=up[i]<<(i*2);
		}
		return k;
	}
};

State decode(int k)
{
	State T;
	for(int i=0;i<=C;++i)
	{
		T.up[i] = k&3;
		k>>=2;
	}
	return T;
}

void solve()
{
	h[0].clear();
	h[0].push(0,1);
	int cur = 0;
	for(int i=0;i<R;++i)
		for(int j=0;j<C;++j)
		{
			cur ^= 1;
			h[cur].clear();
			for(int z=0;z<h[cur^1].size;++z)
			{
				int k = h[cur^1].state[z];
				if(j==0) k<<=2;
				BigInteger d = h[cur^1].d[z];
				State S = decode(k);
				//	for(int t=0;t<C;++t) printf("%d ",S.up[t]);
				//	puts("");
				int lft = S.up[j],up = S.up[j+1];
				if(lft && up)
				{
					S.up[j] = S.up[j+1] = 0;
					if(lft == up )
					{
						stack<int> st;
						if(lft == 1)
						{
							st.push(1);
							for(int t=j+2;t<=C;++t) 
								if(S.up[t]==2 && st.size()==1)
								{
									S.up[t] = 1;
									break;
								}
								else if(S.up[t]==2) st.pop();
								else if(S.up[t]==1) st.push(1);
						}
						else
						{
							st.push(2);
							for(int t=j-1;t>=0;--t) 
								if(S.up[t]==1 && st.size()==1)
								{
									S.up[t] = 2;
									break;
								}
								else if(S.up[t]==1) st.pop();
								else if(S.up[t]==2) st.push(2);
						}
						h[cur].push(S.encode(),d);
					}
					else if(lft == 2 || (i == tx && j == ty)) 
					{
						h[cur].push(S.encode(),d);
					}
				}
				else if(lft || up)
				{
					int t = (lft)?lft:up;
					if((t==up && j!=C-1) || (t==lft && i!=R-1) ) h[cur].push(k,d);
					if((t==up && i!=R-1 ) || (t==lft && j!=C-1 ) ) h[cur].push(k^(t<<(2*j))^(t<<(2*(j+1))),d);
				}
				else if(i!=R-1 && j!=C-1 ) h[cur].push(k^(1<<(2*j))^(2<<(2*(j+1))),d);
			}
		}
	BigInteger ans;
	for(int i = 0;i<h[cur].size;++i) if(!h[cur].state[i])
	{
		ans = h[cur].d[i]+h[cur].d[i];
		ans.print();
		puts("");
		return ;
	}
	puts("0");
}


int main()
{
//	freopen("test.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	while(scanf("%d %d",&C,&R)==2)
	{
		tx = R-1 , ty = C-1;
		if(C==1 || R==1) puts("1");
		else solve();
	}
	return 0;
}

