/*汝佳说此题非常重要，基本上是按照白书上打的
　一是引用传值，二是递归调用，这两个思想很重要
  !w1 !w2 必须分开写，因为一个传递的是左子树的值，
  另一个是右子树，在调用完flag1=solve(w1)时w1已经改变，
  如果写在一起,在返回到w1=w2=0那层时,不能进行w2的调用,　　　　
  然后返回的是  左子树是否平衡&&右子树是否平衡&&左右子树力矩是否相等*/
#include <iostream>
#include <cstdio>
using namespace std;

bool solve(int &w)
{
	bool flag1=true,flag2=true;
	int w1,d1,w2,d2;
	cin>>w1>>d1>>w2>>d2;
	if(!w1) flag1=solve(w1);
	if(!w2)	flag2=solve(w2);
	w=w1+w2;
	return flag1 && flag2 && (w1*d1==w2*d2);
}
		
int main()
{
	//freopen("test","r",stdin);
	int n;
	cin>>n;
	while(n--){
		int w;
		puts(solve(w)?"YES":"NO");
		if(n) puts("");
	}
	return 0;
}
