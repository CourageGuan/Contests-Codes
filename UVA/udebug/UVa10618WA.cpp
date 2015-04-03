//决策太多。。。　de不下去了...
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>
using namespace std;

const int maxn=70 + 10;
const int INF=0x3f3f3f3f;
int d[maxn][4][4][3];
string s;
char res[maxn];

inline int cost(int a,int b)
{
	if(a==b) return 3;
	if(a>b) swap(a,b);
	if(a==1 && b==2) return 7;
	if(b-a<=2) return 5; 
	return 7;
}


// 0,1,2,3 	上，左，下，右     0,1,2  不动，左脚，右脚
int dp(int i,int x,int y,int st) // 阶段，左脚位置，右脚位置，上一次用脚
{
	if(i>=s.size()) return 0;
	int& ans=d[i][x][y][st];
	if(ans) return ans;
	ans=INF;
	if(s[i]=='.'){
		if(ans>dp(i+1,x,y,0)+1){
			res[i]='.';	
			ans=dp(i+1,x,y,0)+1;
		}

		if(y!=1){	//右脚不在左箭头
			for(int j=0;j<4;++j){
				if(j!=y && ans>dp(i+1,j,y,1)+cost(x,j)){
					ans=dp(i+1,j,y,1)+cost(x,j);
					res[i]='L';
				}
			}
		}

		if(x!=3){	//左脚不在右箭头
			for(int j=0;j<4;++j){
				if(j!=x && ans>dp(i+1,x,j,2)+cost(y,j)){
					ans=dp(i+1,x,j,2)+cost(y,j);
					res[i]='R';
				}
			}
		}
	}
	else{
		if(s[i]=='U'){
			if(y!=1){
				if(y!=0 && ans>dp(i+1,0,y,1)+cost(x,0)){
					ans=dp(i+1,0,y,1)+cost(x,0);
					res[i]='L';
				}
			}
			if(x!=3){	
				if(x!=0 && ans>dp(i+1,x,0,2)+cost(y,0)){
					ans=dp(i+1,x,0,2)+cost(y,0);
					res[i]='R';
				}
			}
		}
		if(s[i]=='L'){
			if(y!=1){
				if(ans>dp(i+1,1,y,1)+cost(x,1)){
					ans=dp(i+1,1,y,1)+cost(x,1);
					res[i]='L';
				}
			}
			if(x!=3){	
				if(x!=1 && ans>dp(i+1,x,1,2)+cost(y,1)){
					ans=dp(i+1,x,1,2)+cost(y,1);
					res[i]='R';
				}
			}
		}
		if(s[i]=='D'){
			if(y!=1){
				if(y!=2 && ans>dp(i+1,2,y,1)+cost(x,2)){
					ans=dp(i+1,2,y,1)+cost(x,2);
					res[i]='L';
				}
			}
			if(x!=3){	
				if(x!=2 && ans>dp(i+1,x,2,2)+cost(y,2)){
					ans=dp(i+1,x,2,2)+cost(y,2);
					res[i]='R';
				}
			}
		}
		if(s[i]=='R'){
			if(y!=1){
				if(y!=3 && ans>dp(i+1,3,y,1)+cost(x,3)){
					ans=dp(i+1,3,y,1)+cost(x,3);
					res[i]='L';
				}
			}
			if(x!=3){
				if(ans>dp(i+1,x,3,2)+cost(y,3)){
					ans=dp(i+1,x,3,2)+cost(y,3);
					res[i]='R';
				}
			}
		}
	}

	return ans;
}

int main()
{
	//freopen("UVa10618.in","r",stdin);
	while(getline(cin,s) && s[0]!='#'){
		memset(res,'\0',sizeof(res));
		memset(d,0,sizeof(d));
		cout<<dp(0,1,2,0)<<endl;
		//printf("%s\n",res);
	}
	return 0;
}

