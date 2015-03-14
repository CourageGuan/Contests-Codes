//计数排序
//还可以输入优化...
#include<cstdio>
#include<cstring>
#include<cctype>
using namespace std;

const int maxn=100+5;
int n,cnt[maxn];

inline int Nextint()
{
	char c=getchar();
	while(!isdigit(c)) c=getchar();

	int x=0;
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}

int buf[10];
inline void Writeint(int i){
	int p=0;
	if(i==0) p++;
	else while(i){
		buf[p++]=i%10;
		i/=10;
	}
	for(int j=p-1;j>=0;--j) putchar('0'+buf[j]);
}



int main()
{
	while(n=Nextint()){
		memset(cnt,0,sizeof(cnt));
		for(int i=0;i<n;++i){
			cnt[Nextint()]++;
		}
		int first=-1;
		for(int i=1;i<=100;++i)
			if(cnt[i])
				for(int j=0;j<cnt[i];++j){
					if(++first) putchar(' ');
					Writeint(i);	
				}
		putchar('\n');	
	}
	return 0;
}
