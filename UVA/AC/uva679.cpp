/*简单模拟，记录小球到达每层时的次序，
  奇数，遍历左子树；偶数遍历右子树
  题目保证i<=2^d-1,若不保证则加下述条件 */
#include<cstdio>
#include<iostream>
using namespace std;

int main()
{
	int kase;
	while(scanf("%d",&kase) && kase!=-1){
		while(kase--){
			int d,i;
			scanf("%d%d",&d,&i);
			//i%=(1<<d)-1;  when I>nodes 
			int k=1,n=1;
			while(n<d){
				if(i&1){
					k*=2;
					i+=1;
					i/=2;
				}
				else{
					k=2*k+1;
					i/=2;
				}
				n++;
			}
			printf("%d\n",k);
		}
	}
}
