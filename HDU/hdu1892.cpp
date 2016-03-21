//二维树状数组
//这份诡异TLE...
#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;


const int maxn=1005;
int C[maxn][maxn];

inline int lowbit(int x){
	return x&-x;
}

inline int sum(int x,int y){
	int res=0;
	for(int i=x;i>0;i-=lowbit(i))
		for(int j=y;j>0;j-=lowbit(j))
			res+=C[i][j];
	return res;
}

inline void add(int x,int y,int d){
	for(int i=x;i<maxn;i+=lowbit(i))
		for(int j=y;j<maxn;j+=lowbit(j))
			C[i][j]+=d;
}

inline void init(){
	memset(C,0,sizeof C);
	for(int i=1;i<maxn;++i)
		for(int j=1;j<maxn;++j)
			add(i,j,1);
}

inline int cal(int x1,int y1,int x2,int y2){
	return sum(x2,y2)-sum(x1-1,y2)-sum(x2,y1-1)+sum(x1-1,y1-1);
}

int main()
{
	//freopen("test.txt","r",stdin);
	int T,Q,kase=0;
	scanf("%d",&T);
	while(T--){
		init();
		scanf("%d%*c",&Q);
		printf("Case %d:\n",++kase);
		while(Q--){
			char s;
			int x1,x2,y1,y2,t;
			scanf("%c",&s);
			switch(s){
				case 'S':{
							 scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
							 ++x1;++x2;++y1;++y2;
							 if(x1>x2) swap(x1,x2);
							 if(y1>y2) swap(y1,y2);
							 int ans=cal(x1,y1,x2,y2);
							 printf("%d\n",ans);
							 break;
						 }
				case 'A':{
							 scanf("%d %d %d",&x1,&y1,&t);
							 add(x1+1,y1+1,t);
							 break;
						 }
				case 'D':{
							 scanf("%d %d %d",&x1,&y1,&t);
							 t=min(t,cal(x1+1,y1+1,x1+1,y1+1));
							 add(x1+1,y1+1,-t);
							 break;
						 }
				case 'M':{
							 scanf("%d %d %d %d",&x1,&y1,&x2,&y2,&t);
							 ++x1;++x2;++y1;++y2;
							 t=min(t,cal(x1,y1,x1,y1));
							 add(x1,y1,-t);
							 add(x2,y2,t);
							 break;
						 }
			}
		}
	}
	return 0;
}
