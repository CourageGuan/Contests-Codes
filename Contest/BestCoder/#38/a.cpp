#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
typedef double DB;

DB x[4],y[4],z[4];

DB len(DB x,DB y,DB z)
{
	return  x*x+y*y+z*z;
}

bool yes()
{
	DB ds[6];
	int cnt=0;
	for(int i=0;i<4;++i)
		for(int j=i+1;j<4;++j)
			ds[cnt++]=len(x[i]-x[j],y[i]-y[j],z[i]-z[j]);
	double d1=ds[0],d2;
	cnt=0;
	for(int i=0;i<6;++i){
		if(ds[i]==0) return false;
		if(ds[i]==d1) ++cnt;
	}
	if(cnt!=2 && cnt!=4) return false;
	int i;
	for(i=1;i<6;++i)
		if(ds[i]!=d1) break;
	d2=ds[i];
	cnt=0;
	for(int j=0;j<6;++j)
		if(d2==ds[j]) ++cnt;
	if(cnt!=4 && cnt!=2) return false;
	if(d1>d2) swap(d1,d2);
	if(d2!=2*d1) return false;
	return true;
}

int main()
{
	//freopen("test.txt","r",stdin);
	int T,kase=0;
	scanf("%d",&T);
	while(T--){
		for(int i=0;i<4;++i) scanf("%lf %lf %lf",x+i,y+i,z+i);
		printf("Case #%d: ",++kase);
		puts(yes()?"Yes":"No");
	}
	return 0;
}

