#include<cstdio>
#include<string>
#include<cstring>
#include<cstdio>
#include<iostream>
using namespace std;

#define F(i,a,b) for(int i=a;i<=b;++i)

const int maxn=100+5;
bool flag[2][maxn]; 

int gcd(int a,int b){return (b<=0)?a:gcd(b,a%b);}

int main()
{
	int m,n; 
	scanf("%d %d",&n,&m);
	F(i,0,1){
		int sum;
		scanf("%d",&sum);
		while(sum--){
			int d;scanf("%d",&d);
			flag[i][d]=1;
		}
	}
	F(i,0,2*m*n/gcd(m,n)){
	 	bool d;	
		d=flag[0][i%n] || flag[1][i%m];
		flag[0][i%n]=flag[1][i%m]=d;
	}
	bool yes=true;
	F(i,0,n-1)
		if(!flag[0][i]){
			yes=false;
			break;
		}
	F(i,0,m-1)
		if(!flag[1][i] || !yes){
			yes=false;
			break;
		}
	puts(yes?"Yes":"No");
	return 0;
}

