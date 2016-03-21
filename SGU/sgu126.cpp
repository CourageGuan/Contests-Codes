/*又是一道数学题，不妨设a<=b {a,b}->{2a,b-a}->...->{a+b,0}
  刚开始以为是q=2的等比数列和，所以求log2((a+b)/a),为整数即为正解
  反之输出-1，不过一直在第14个点WA,后来改成log2((a+b)/gcd(a,b))AC了
  暂时找不出反例，不知道原来的解法错在哪里。*/
#include<bits/stdc++.h>
using namespace std;

const double eps=1e-12;

int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}

int main()
{
	double a,b;
	cin>>a>>b;
	double c=a+b;
	double ans;
	if((int)c&1)
		ans=-1;
	else{
		if(a>b) swap(a,b);
		c/=(double)gcd((int)a,(int)b);
		//printf("%.20lf\n",c);
		/*if(abs(c-round(c))>eps){
			cout<<-1<<endl;
			return 0;
		}*/
		ans=log2(c);
		//printf("%.20lf\n",log2(c));
		if(abs(ans-round(ans))>eps) ans=-1;
	}
	if(a==0 || b==0) ans=0;
	cout<<(int)ans<<endl;
	return 0;
}
