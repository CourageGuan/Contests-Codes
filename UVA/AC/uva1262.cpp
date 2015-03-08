//解码的问题，通过计算k，从5个集合中取第n个元素。
//注意集合不能有重复元素
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	//freopen("test","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--){
		int k;
		scanf("%d",&k);getchar();
		char s[6][10],ss[6][10];
		vector<char> pswd[5];
		for(int i=0;i<6;++i) scanf("%s",s[i]);
		for(int i=0;i<6;++i) scanf("%s",ss[i]);
		for(int i=0;i<5;++i)
			for(int j=0;j<6;++j)
				for(int k=0;k<6;++k)
					if(s[j][i]==ss[k][i]){
						bool flag=true;
						for(int w=0;w<pswd[i].size();++w)
						if(pswd[i][w]==s[j][i]) {flag=false;break;}
						if(flag) pswd[i].push_back(s[j][i]);
					}
		int len[5],all[5];
		for(int i=0;i<5;++i){
			sort(pswd[i].begin(),pswd[i].end());
			len[i]=pswd[i].size();
			//for(int k=0;k<len[i];++k) cout<<pswd[i][k];
			//puts("");
		}
		for(int i=4;i>=0;--i) all[i]=(i==4?len[i]:all[i+1]*len[i]);
		if(k>all[0]){
			puts("NO");
			continue;
		}
		//for(int i=0;i<5;++i) cout<<all[i]<<" ";
		for(int i=1;i<5;++i){
			int cnt=0;
			//cout<<cur<<" "<<k<<endl;
			while(k>all[i]){
				k-=all[i];
				++cnt;
			}
			printf("%c",pswd[i-1][cnt]);
		}
		printf("%c",pswd[4][k-1]);
		puts("");
	}
	return 0;
}

