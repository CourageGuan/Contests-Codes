//数论
//A = a*10^(k+1) + b*10^k + c
//B = a*10^k + c
//N = A + B = (11a+b)*10^k + 2*c
//其中b是一位数,只需枚举k即可求出A,B
//由于2*c可能会进位，而最多进一位,所以算两次,N/10^k=11a+b,N/10^k=11a+b+1也可用下面规则
//形如 M=an+b 的形式(b<n) a=M/n,b=M%n;
#include<stdio.h>
#include<iostream>
#include<set>
using namespace std;


const int power[]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
set<int> ans;

int main()
{
	int n;
	while(~scanf("%d",&n) && n){
		ans.clear();
		for(int i=0;power[i]<=n;++i){
			int a=((n/power[i])/11),b=((n/power[i])%11)%10,c=(n%power[i])/2;
			int X=a*power[i+1]+b*power[i]+c,Y=a*power[i]+c;
			if(X+Y==n) ans.insert(X);
			a=((n/power[i]-1)/11),b=((n/power[i]-1)%11)%10,c=(n%power[i]+power[i])/2;
			X=a*power[i+1]+b*power[i]+c,Y=a*power[i]+c;
			if(X+Y==n) ans.insert(X);
		}
		set<int>::iterator it;
		if(ans.empty()) printf("No solution.");
		else for(it=ans.begin();it!=ans.end();++it){
			if(it!=ans.begin()) printf(" ");
		   	printf("%d",*it);
		}
		puts("");
	}
	return 0;
}
