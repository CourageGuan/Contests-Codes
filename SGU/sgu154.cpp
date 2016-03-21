/*SGU太狠了,极限数据超0.06sTLE...是一道不错的水题
  正解二分答案...(比较坑的是自然数的定义...)*/

/*#include<cstdio>
//#include<ctime>
//using namespace std;

typedef long long LL;

inline int div(int n){
	int t=0;
	while(n && n%5==0){
		n/=5;
		t++; 
	}
	return t;
}


int main()
{
	//freopen("test","r",stdin);
	int q;
	~scanf("%d",&q);
	if(q==0){
		printf("1\n");
		return 0;
	}
	int i,ans=0;
	for(i=0;i<q;i+=div(ans*5)) ans++;
	if(i!=q) printf("No solution\n");
	else printf("%d\n",ans*5);
	//~printf("\nTIME WASTED  %.2f s\n",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}*/


#include<iostream>
#include<cstdio>
using namespace std;

#define MX 400000016
#define MN 0

int zero(int n)
{
	int t=0;
	while(n){
		t+=n/5;
		n/=5;
	}
	return t;
}

int low_bound(int q,int l,int r)
{
	int m;
	while(l<r){
		m=l+(r-l)/2;
		if(zero(m)>=q) r=m; 
		else l=m+1;
	}
	if(zero(l)!=q) return -1;
	return l;
}

int main()
{
	int q;
	cin>>q;
	if(q==0){
		puts("1");
		return 0;
	}
	int ans=low_bound(q,MN,MX);
	if(ans==-1)
		cout<<"No solution\n";
	else
		cout<<ans<<endl;
	return 0;
}


