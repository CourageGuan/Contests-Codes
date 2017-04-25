#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define pb push_back

const int re[10][4]={{0,0,0,0},{0,0,0,0},{2,0,0,0},{3,0,0,0},{2,2,3,0},{5,0,0,0},{3,5,0,0},{7,0,0,0},{2,2,2,7},{2,3,3,7}};

const int maxn=15+5;
int s[maxn]; 
vector<int> res;

int main()
{
	int n;
	scanf("%d%*c",&n);
	for(int i=0;i<n;++i){
		char c=getchar();
		s[i]=c-'0';
	}
	for(int i=0;i<n;++i){
		if(s[i]<=1) continue;
		for(int k=0;k<=3;++k){
			if(re[s[i]][k]==0) break;
			res.pb(re[s[i]][k]);
		}
	}
	sort(res.begin(),res.end());
	for(int i=1;i<=res.size();++i) printf("%d",res[res.size()-i]);
	puts("");
	return 0;	
}

