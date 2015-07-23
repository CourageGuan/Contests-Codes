//字符串Hash，相信概率，不必容错....
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
using namespace std;

const int mod=20000003;
bool Hash[mod];
char s[mod];
int asc[256];
int m,k,n;

int solve(){
	n=strlen(s); if(n<m) return 0;
	memset(asc,0,sizeof asc);
	int cnt=0,cur=0,h=1; 
	for(int i=0;i<n;++i) if(!asc[s[i]]) asc[s[i]]=++cnt;
	cnt=1;
	memset(Hash,0,sizeof Hash);
	for(int i=0;i<m;++i){
		if(i) h=(h*k)%mod;
	   	cur=(cur*k+asc[s[i]])%mod;
	}
	Hash[cur]=1;
	for(int i=1;i<=n-m;++i){
		cur=(k*(cur-h*asc[s[i-1]])+asc[s[i+m-1]])%mod;
		if(cur<0) cur+=mod;
		if(!Hash[cur]){
			++cnt;
			Hash[cur]=1;
		}
	}
	return cnt;
}

int main()
{
//	freopen("test.txt","r",stdin);
	while(scanf("%d %d %s",&m,&k,s)==3) printf("%d\n",solve());
	return 0;
}

