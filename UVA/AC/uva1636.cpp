//概率题，随机旋转无子弹的概率为 n(0)/(n(0)+n(1)) 
//下一个位置无子弹的概率为 n(00)/(n(00)+n(01))
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
using namespace std;

const double eps=1e-8;

int main()
{
	char s[1000+5];
	while(scanf("%s",s)==1){
		getchar();
		//cout<<s<<endl;
		int len=strlen(s);
		int zero,zz,oz;
		zero=zz=oz=0;
		s[len]=s[0];
		for(int i=0;i<len;++i)
			if(s[i]=='0'){
				zero++;
				if(s[i+1]=='1') oz++;
				else zz++;
			}
		double p1,p2,dzero,dzz,doz,dlen;
		dzero=zero;dzz=zz;doz=oz;dlen=len;
		p1=dzero/dlen;
		if(dzz+doz==0) p2=1;
		else p2=dzz/(dzz+doz);
		//cout<<p1<<" "<<p2<<endl;
		if(fabs(p1-p2)<eps) puts("EQUAL");
		else puts(p1<p2?"SHOOT":"ROTATE");
	}
	return 0;
}

