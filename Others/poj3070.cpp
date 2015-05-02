//矩阵快速幂
#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
#define maxn 2 

const int mod=10000;
const int  n=2;

struct Matrix{
	int m[maxn][maxn];

	void init(){		//初始化为单位矩阵
		memset(m,0,sizeof m);
		for(int i=0;i<n;++i) m[i][i]=1;
	}

	void print(){
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j)
				printf("%d ",m[i][j]);
			puts("");
		}
	}
};

Matrix add(Matrix a,Matrix b){
	Matrix c;
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			c.m[i][j]=a.m[i][j]+b.m[i][j];
	return c;
}

Matrix mul(Matrix a,Matrix b){
	Matrix c;
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j){
			c.m[i][j]=0;
			for(int k=0;k<n;++k)
				c.m[i][j]+=a.m[i][k]*b.m[k][j];
			c.m[i][j]%=mod;
		}
	return c;
}

Matrix qpow(Matrix a,int n){
	Matrix b;
	b.init();
	while(n){
		if(n&1)
			b=mul(b,a);
		n>>=1;
		a=mul(a,a);
	}
	return b;
}

Matrix sum(Matrix a,int n){	//矩阵的幂和 (a^1+a^2+...+a^n)%mod
	if(n==1) return a;
	int m=n/2;
	Matrix ans,pre;
	pre=sum(a,m);
	ans=add(pre,mul(pre,qpow(a,m)));
	if(n&1)
		ans=add(ans,qpow(a,n));
	return ans;
}


int main()
{
	Matrix M;
	M.m[0][0]=1;
	M.m[0][1]=1;
	M.m[1][0]=1;
	M.m[1][1]=0;
	int m;
	while(~scanf("%d",&m) && m!=-1){
		if(!m) puts("0");
		else {
			Matrix T=qpow(M,m);
			printf("%d\n",T.m[0][1]);
		}
	}
	return 0;
}
