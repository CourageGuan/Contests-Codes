#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

const int maxn=1000 + 10;

vector<int> p1[7],p2[7];
int q1[7],q2[7];


int main()
{
	int n;
	//freopen("test.txt","r",stdin);
	scanf("%d",&n);
	int w;
	memset(q1,0,sizeof(q1));
	memset(q2,0,sizeof(q2));
	for(int i=0;i<n;++i){
		scanf("%d",&w);
		p1[w].push_back(i+1);
	}
	for(int i=0;i<n;++i){
		scanf("%d",&w);
		p2[w].push_back(i+1);
	}
	for(int i=0;i<7;++i){
		int m;
		m=min(p1[i].size(),p2[i].size());
		for(int j=0;j<m;++j) printf("%d %d\n",p1[i][j],p2[i][j]);
		q2[i]=q1[i]=m;
	}
	for(int L=1;L<=6;++L)
	{
		int kase=1;
		for(int i=6;i>0;--i){
			int j=i-L;
			if(j<0) continue;

			if(!kase){

				if(q1[i]<p1[i].size() && q2[j]<p2[j].size()){
					printf("%d %d\n",p1[i][q1[i]],p2[j][q2[j]]);
					q1[i]++;
					q2[j]++;
					kase^=1;
				}
			}
			if(kase){

				if(q1[j]<p1[j].size() && q2[i]<p2[i].size()){
					printf("%d %d\n",p1[j][q1[j]],p2[i][q2[i]]);
					q1[j]++;
					q2[i]++;
					kase^=1;
				}
            }
		}
		kase=0;
		for(int i=6;i>0;--i){
			int j=i-L;
			if(j<0) continue;

			if(!kase){

				if(q1[i]<p1[i].size() && q2[j]<p2[j].size()){
					printf("%d %d\n",p1[i][q1[i]],p2[j][q2[j]]);
					q1[i]++;
					q2[j]++;
					kase^=1;
				}
			}
			if(kase){

				if(q1[j]<p1[j].size() && q2[i]<p2[i].size()){
					printf("%d %d\n",p1[j][q1[j]],p2[i][q2[i]]);
					q1[j]++;
					q2[i]++;
					kase^=1;
				}
            }
		}

	}
	return 0;
}

