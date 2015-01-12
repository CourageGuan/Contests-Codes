/*做这道题时候脑洞开的有点大，一开始想的用特殊条件判断出栈序列是否合法，
 想出来几个，证明下来都是错的，还是数学太渣;最后想想可以直接模拟，
 即当前出栈元素要么在栈顶，要么还没入栈，这两个都不符合时即非法*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 & Author: GYH
 & Created Time:  2015年01月07日 星期三 17时23分52秒
 & File Name: uva514.cpp
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#include<cstdio>
#include<stack>
using namespace std;

#define F(i,a,b) for(int i=a;i<=b;i++)
#define Fd(i,a,b) for(int i=a;i>=b;i++)
#define min(a,b) a<b?a:b
#define SETS(s) while(!s.empty()) s.pop()


const int maxn=1234;

int main()
{
	//freopen("test","r",stdin);
	//freopen("2","w",stdout);
	int n;
	while(scanf("%d",&n)==1 && n){
		int out=1;
		while(1){
			bool flag=true,ok=true;
			stack<int> s;
			int a=1;	//a 表示当前未进栈的第一个元素
			F(i,1,n){
				scanf("%d",&out);
				if(out==0){
					flag=false;
					break;
				}
				if(!s.empty() && s.top()!=out && out<a)  //表示out 在栈中 且被压
					ok=false;
				if(ok){
					if(a<=out){
						F(i,a,out)
							s.push(i);
						a=out+1;
					}
					if(!s.empty()) s.pop();
				}
			}
			if(!flag){
				puts("");
				break;
			}
			puts(ok?"Yes":"No");
		}
	}
}


		
