#include<set>
#include<iostream>
#include<cmath>
using namespace std;

struct wtf{
	double d;
	wtf(double d=0.0):d(d) {}
	bool operator <(const wtf& b) const {
		if(fabs(d-b.d)<1e-10) return false;
		else return d<b.d;
	}
	bool operator >(const wtf& b) const {
		if(fabs(d-b.d)<1e-10) return false;
		else return d>b.d;
	}
	bool operator ==(const wtf& b) const {
		return fabs(d-b.d)<1e-10;
	}
};

set<wtf> s;

int main()
{
	wtf x,y;
	int n,ans=0;
	cin>>n>>x.d>>y.d;
	s.clear();
	for(int i=0;i<n;++i){
		wtf a,b;	
		cin>>a.d>>b.d;
		a.d=a.d-x.d;
		b.d=b.d-y.d;
		//cout<<a/b<<endl;
		if(!s.count(wtf(a.d/b.d))){
			ans++;
			s.insert(wtf(a.d/b.d));
		}
	}
	cout<<ans<<endl;
	return 0;
}

