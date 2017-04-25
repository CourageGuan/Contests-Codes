#include<stdio.h>
#include<iostream>
#include<string.h>
#include<ctype.h>
#include<vector>
#include<map>
using namespace std;
const int maxn=1000 + 10;
char s1[maxn],s2[maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	int ans;
	while(scanf("%s",s1)==1){
		scanf("%s",s2);
		int len1=strlen(s1),len2=strlen(s2);
		int k1,k2;
		k1=k2=ans=0;
		while(k1<len1 && k2<len2){
			if(s1[k1]=='L' && s2[k2]=='L')
			{
				++k1;
				++k2;
				++ans;
				continue;
			}
			if(s1[k1]!='L') ++k1;
			if(s2[k2]!='L') ++k2;
			++ans;
		}
		ans+=max(len1-k1,len2-k2);
		printf("%d\n",ans);
	}
	return 0;
}
		

