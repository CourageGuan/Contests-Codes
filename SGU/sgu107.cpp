/*sgu...水题都这么...	//事实证明C++的性能是远好于Python的...
	for(LL i=100000000;i<10000000000;++i)
		if((i*i)%1000000000==987654321)	cout<<i<<endl;
  花样乱搞,先暴搜出n＝9，10时候的结果，然后发现规律...
  另外，输出用cout　TLE...*/
#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int n;
	cin>>n;
	if(n<=8){
		cout<<0<<endl;
		return 0;
	}
	if(n==9){
		cout<<8<<endl;
		return 0;
	}
	n-=10;
	cout<<72;
	for(int i=0;i<n;++i) printf("0");
	cout<<endl;
	return 0;
}
