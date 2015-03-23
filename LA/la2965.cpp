//中途相遇法 涉及位运算
//通过保存中间值使n减半，尤其是复杂度较高时效果明显
#include<cstdio>
#include<cctype>
#include<cstring>
#include<map>
#include<iostream>
using namespace std;


const int maxn=24;
int arr[maxn+5];

map<int,int> table;

int cal(int a,int b)
{
	int cnt=0;
	while(a || b){
		if(a&1) ++cnt; 
		if(b&1) ++cnt;
		a>>=1;b>>=1;
	}
	return cnt;
}

void print(int n)
{
	while(n){
		if(n&1) printf("1");
		else printf("0");
		n>>=1;
	}
	puts("");
}

int main()
{
	//freopen("test","r",stdin);
	int n;
	char s[1000];
	while(scanf("%d",&n)==1 && n){
		table.clear();
		for(int i=1;i<=n;++i){
			scanf("%s",s);
			int t=0;
			for(int j=0;j<strlen(s);++j)
				t^=1<<(s[j]-65);
			arr[i]=t;
		}
		int ans=0,sub=0;
		int base=1<<(n/2);
		for(int i=0;i<base;++i){
			int bit=i;
			int res=0,cnt=1;
			while(bit){
				if(bit&1)
					res^=arr[cnt];
				bit>>=1;
				++cnt;
			}
			table[res]=i;
		}
		base=1<<(n-n/2);
		for(int i=0;i<base;++i){
			int bit=i;	
			int res=0,cnt=n/2+1;
			while(bit){
				if(bit&1)
					res^=arr[cnt];
				bit>>=1;
				++cnt;
			}
			if(table.count(res)){
				int t=cal(table[res],i);
				if(ans<t){
					ans=t;
					sub=table[res]+(i<<(n/2));
				}
			}
		}
		printf("%d\n",ans);
		int cnt=1,first=0;
		while(sub){
			if(sub&1){
				if(first++) printf(" ");
				printf("%d",cnt);
			}
			sub>>=1;
			++cnt;
		}
		printf("\n");
	}
	return 0;
}

