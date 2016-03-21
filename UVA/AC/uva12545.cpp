/*先判断是否能使两边0 1数目相等，若不能则输出-1
  ans=max(sum(01),sum(10))+sum(?) 	//01 上0下1  10 上1下0  ? 上?下?
  优先交换，10只能通过交换，01可以通过交换和变0为1，?先默认和下面对应字符匹配，
  若不能完全匹配，剩下的用于交换*/
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

const int maxn=200+5;

int main()
{	
	//freopen("test","r",stdin);
	int kase,cnt=0;
	scanf("%d",&kase);
	while(kase--){
		int a[maxn],b[maxn],c[maxn],zero,one,why,ans;
		ans=zero=one=why=0;
		char s[maxn];
		scanf("%s",s);
		for(int i=0;i<strlen(s);++i){
			switch(s[i]){
				case '0':++zero;a[i]=0;break;
				case '1':++one;a[i]=1;break;
				case '?':++why;a[i]=2;break;
			}
		}
		int zo=0,oz=0;
		ans+=why;zero+=why;
		scanf("%s",s);
		for(int i=0;i<strlen(s);++i){
			b[i]=(s[i]=='0')?0:1;
			if(b[i]) --one;
			else --zero;
			if(a[i]==0 && b[i]==1) ++zo;
			else if(a[i]==1 && b[i]==0) ++oz;
		}
		if(zero<0 || one>0 ){
			printf("Case %d: %d\n",++cnt,-1);
			continue;
		}
		ans+=max(zo,oz);
		printf("Case %d: %d\n",++cnt,ans);
	}
	return 0;
}

