#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
#define N 5

const int mod=1000007;
int n;

typedef struct{
	int m[N][N];

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
} Matrix;

Matrix add(Matrix a,Matrix b){
	Matrix c;
	for(int i=0;i<N;++i)
		for(int j=0;j<N;++j)
			c.m[i][j]=a.m[i][j]+b.m[i][j];
	return c;
}

Matrix mul(Matrix a,Matrix b){
	Matrix c;
	for(int i=0;i<N;++i)
		for(int j=0;j<N;++j){
			c.m[i][j]=0;
			for(int k=0;k<N;++k)
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
	scanf("%d",&n);
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
            scanf("%d",&a.m[i][j]);
	a.print();
	a=sum(a,2);
	a.print();
	return 0;
}


