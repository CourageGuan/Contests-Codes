#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
#define N 4

int mod,l;

struct Matrix{
	int m[N][N];
	void init(){
		memset(m,0,sizeof m);
		for(int i=0;i<N;++i) m[i][i]=1;
	}
};

Matrix mul(Matrix a,Matrix b)
{
	Matrix c;
	for(int i=0;i<N;++i)
		for(int j=0;j<N;++j)
		{
			c.m[i][j]=0;
			for(int k=0;k<N;++k) c.m[i][j]+=a.m[i][k]*b.m[k][j];
			c.m[i][j]%=mod;
		
		}
	return c;
}

Matrix qpow(Matrix a,int n){
	Matrix b;
	b.init();
	while(n){
		if(n&1) b=mul(b,a);
		n>>=1;
		a=mul(a,a);
	}
	return b;
}

int main()
{
	while(~scanf("%d %d",&l,&mod)){
		if(l<5){
			switch(l){
				case 1:printf("%d\n",2%mod);break;
				case 2:printf("%d\n",4%mod);break;
				case 3:printf("%d\n",6%mod);break;
				case 4:printf("%d\n",9%mod);break;
			}
			continue;
		}
		Matrix c; 
		memset(c.m,0,sizeof (c.m));
		c.m[0][0]=c.m[0][2]=c.m[0][3]=c.m[1][0]=c.m[2][1]=c.m[3][2]=1;
		c=qpow(c,l-4);
		printf("%d\n",(9*c.m[0][0]+6*c.m[0][1]+4*c.m[0][2]+2*c.m[0][3]) % mod);
	}
	return 0;
}
