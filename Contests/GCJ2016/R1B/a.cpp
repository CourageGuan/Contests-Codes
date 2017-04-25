#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 2010;
char dig[10][10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
char s[maxn];
int cnt[256];
int ans[10];

int main()
{
	//freopen("test.txt","r",stdin);
	freopen("A-large.in","r",stdin);
	freopen("ansA.txt","w",stdout);
	int T;
	scanf("%d",&T);
	for(int z=1;z<=T;++z)
	{
		memset(cnt,0,sizeof cnt);
		memset(ans,0,sizeof ans);
		scanf("%s",s);
		int len = strlen(s);
		for(int i=0;i<len;++i) ++cnt[s[i]];
		printf("Case #%d: ",z);

		int cur = cnt['Z'];
		ans[0] += cur;
		for(int j=0;j<strlen(dig[0]);++j) cnt[dig[0][j]] -= cur;

		cur = cnt['W'];
		ans[2] += cur;
		for(int j=0;j<strlen(dig[2]);++j) cnt[dig[2][j]] -= cur;

		cur = cnt['G'];
		ans[8] += cur;
		for(int j=0;j<strlen(dig[8]);++j) cnt[dig[8][j]] -= cur;

		cur = cnt['H'];
		ans[3] += cur;
		for(int j=0;j<strlen(dig[3]);++j) cnt[dig[3][j]] -= cur;

		cur = cnt['R'];
		ans[4] += cur;
		for(int j=0;j<strlen(dig[4]);++j) cnt[dig[4][j]] -= cur;

		cur = cnt['O'];
		ans[1] += cur;
		for(int j=0;j<strlen(dig[1]);++j) cnt[dig[1][j]] -= cur;

		cur = cnt['X'];
		ans[6] += cur;
		for(int j=0;j<strlen(dig[6]);++j) cnt[dig[6][j]] -= cur;

		cur = cnt['S'];
		ans[7] += cur;
		for(int j=0;j<strlen(dig[7]);++j) cnt[dig[7][j]] -= cur;

		cur = cnt['V'];
		ans[5] += cur;
		for(int j=0;j<strlen(dig[5]);++j) cnt[dig[5][j]] -= cur;

		cur = cnt['I'];
		ans[9] += cur;
		for(int j=0;j<strlen(dig[9]);++j) cnt[dig[9][j]] -= cur;

		for(int i=0;i<10;++i)
			for(int j=0;j<ans[i];++j) putchar('0'+i);
		puts("");
	}
	return 0;
}


