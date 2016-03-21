#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LDB;


const char ans[13][10] = {"x^y^z","x^z^y","(x^y)^z","(x^z)^y","y^x^z","y^z^x","(y^x)^z","(y^z)^x","z^x^y","z^y^x","(z^x)^y","(z^y)^x"};

LDB cal(int op,LDB x,LDB y,LDB z)
{
	LDB res = 0;
	switch(op){
		case 0: res= pow(y,z)*log(x);break;
		case 1: res= pow(z,y)*log(x);break;
		case 2: 
		case 3: res = y*z*log(x);break;

		case 4: res= pow(x,z)*log(y);break;
		case 5: res= pow(z,x)*log(y);break;
		case 6: 
		case 7: res = x*z*log(y);break;

		case 8: res=pow(x,y)*log(z);break;
		case 9: res=pow(y,x)*log(z);break;
		case 10: 
		case 11: res = x*y*log(z);break;
	}
	return res;
}

int main()
{
	//freopen("test.txt","r",stdin);
	LDB a,b,c;
	cin>>a>>b>>c;
	LDB res = cal(0,a,b,c);
	int cur = 0;
	for(int i=1;i<12;++i)
	{
		LDB val = cal(i,a,b,c);
//		cout<<val<<" "<<i<<endl;
		if(res < val)
		{
			res = val;
			cur = i;
		}
	}
//	cout<<cur<<'\n';
	cout<< ans[cur] << '\n';
	return 0;
}

