//矩阵快速幂
// |f(n)  |  = |A B|x|f(n-1)|	
// |f(n-1)|	   |1 0| |f(n-2)|
#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
#define N 2

const int mod=7;

struct Matrix{ 
	int m[N][N];
	void init(){
		memset(m,0,sizeof m);
		for(int i=0;i<N;++i) m[i][i]=1;
	}
};

Matrix mul(Matrix a,Matrix b){
	Matrix c;
	for(int i=0;i<N;++i)
		for(int j=0;j<N;++j){
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
		if(n&1)
		   	b=mul(b,a);
		n>>=1;
		a=mul(a,a);
	}
	return b;
}

int main()
{
	int a,b,n;
	Matrix M;
	while(~scanf("%d %d %d",&a,&b,&n) && (a+b+n)){
		if(n<=2){
		   	puts("1");
			continue;
		}
		M.m[0][0]=a;M.m[0][1]=b;M.m[1][0]=1;M.m[1][1]=0;
		//cout<<M.m[0][0]<<endl;
		M=qpow(M,n-2);
		printf("%d\n",(M.m[0][0]+M.m[0][1])%7);
	}
	return 0;
}

