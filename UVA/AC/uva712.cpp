/*毋须建树，每个叶节点在该行的位置即每次查询的二进制数*/
#include<bits/stdc++.h>
using namespace std;


int main()
{
	//freopen("test","r",stdin);
	int n,kase=1;
	while(cin>>n && n){
		getchar();
		string s;
		getline(cin,s);
		getline(cin,s);
		int m;
		printf("S-Tree #%d:\n",kase++);
		cin>>m;
		getchar();
		while(m--){
			int ans=0;
			for(int i=n;i>0;--i){
				char ch=getchar();
				int c=ch-48;
				ans+=c*(1<<(i-1));
			}
			getchar();
			cout<<s[ans];
		}
		puts("\n");
	}
}
			
					
			
