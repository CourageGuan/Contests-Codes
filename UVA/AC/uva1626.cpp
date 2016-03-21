//经典的括号匹配问题
//根据题目可知两种转移:
//	1.[s] 转移到 s 
//	2.s 至少有两个字符ab 转移到ab
//	无论如何两种转移都要进行  因为这种情况 [][] 转移到了][
//	用d[i][j]表示i~j最少需要添加字符
#include<cstdio>
#include<iostream>
using namespace std;

const int maxn=100 + 5;

int n;
char S[maxn];
int d[maxn][maxn];	//表示i~j至少需要添加多少括号

bool match(char a,char b)
{
	return (a=='[' && b==']') || (a=='(' && b==')');
}

void dp()
{
	for(int i=0;i<n;++i){
		d[i+1][i]=0;
		d[i][i]=1;
	}

	for(int i=n-2;i>=0;--i)
		for(int j=i+1;j<n;++j){
			d[i][j]=n;
			if(match(S[i],S[j])) d[i][j]=min(d[i][j],d[i+1][j-1]);
			for(int k=i;k<j;++k)
				d[i][j]=min(d[i][j],d[i][k]+d[k+1][j]);
		}
}

void print(int i,int j)
{
	if(i>j) return ;
	if(i==j) {
		if(S[i]=='(' || S[i]==')') printf("()");
		else printf("[]");
		return;
	}
	int ans=d[i][j];
	if(match(S[i],S[j]) && ans==d[i+1][j-1]){
		printf("%c",S[i]);
		print(i+1,j-1);
		printf("%c",S[j]);
		return;
	}
	for(int k=i;k<j;++k)
		if(ans==d[i][k]+d[k+1][j]){
			print(i,k);
			print(k+1,j);
			return;
		}
}


int main()
{
	//freopen("test","r",stdin);
	int kase;
	scanf("%d%*c",&kase);
	getchar();
	while(kase--){
		n=0;
		char c;
		while(1){
			c=getchar();
			if(c=='\n') break;
			S[n++]=c;
		}
		if(n==0)
			puts("");
		else{
			dp();
			print(0,n-1);
			puts("");
		}
		if(kase) puts("");
		getchar();
	}
	return 0;
}



