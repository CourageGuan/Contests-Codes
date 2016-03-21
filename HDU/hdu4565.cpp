#include<cstdio>
#include<cstring>


const int maxn = 3;
typedef long long LL;
typedef LL Matrix[maxn][maxn];


const int sz = 2; //矩阵大小
LL mod; //模

void matrix_mul(Matrix A,Matrix B,Matrix res)
{
    Matrix C;
    memset(C,0,sizeof(C));
    for(int i = 0;i < sz;++i)
        for(int j = 0;j < sz;++j)
            for(int k = 0;k < sz;++k)
                C[i][j] = ((C[i][j]  + A[i][k] * B[k][j])%mod + mod) % mod;
    memcpy(res,C,sizeof(C));
}

void matrix_pow(Matrix A,LL n,Matrix res)
{
    Matrix a,r;
    memcpy(a,A,sizeof(a));
	memset(r,0,sizeof r);

	for(int i=0;i<sz;++i) r[i][i] = 1;
    while(n)
    {
        if(n&1) matrix_mul(r,a,r);
        n >>= 1;
        matrix_mul(a,a,a);
    }
    memcpy(res,r,sizeof(r));
}

int main()
{
	//freopen("test.txt","r",stdin);
	LL a,b,n;
	while(scanf("%lld %lld %lld %lld",&a,&b,&n,&mod)==4)
	{
		Matrix A,T,res;
		memset(A,0,sizeof A);
		memset(T,0,sizeof T);

		T[0][0] = 2*(a*a +b)%mod ;		// S2
		T[1][0] = 2*a % mod;	// S1

		A[0][0] = 2*a % mod;
		A[0][1] = ((b - a*a)%mod +mod) % mod;
		A[1][0] = 1;

		if(n==1)
		{
			printf("%lld\n",T[1][0]);
			continue;
		}	
		else if(n==2)
		{
			printf("%lld\n",T[0][0]);
			continue;
		}

		matrix_pow(A,n-2,res);
		matrix_mul(res,T,res);

		printf("%lld\n",((res[0][0]%mod)+mod) % mod);
	}
	return 0;
}


