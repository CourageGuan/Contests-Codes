#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#include<algorithm>

using namespace std;

class BIGINT{
private:
	static const int BASE=1e8;
	static const int WIDE=8;
public:
	int len;
    vector<int> s;

	BIGINT(long long num=0){*this=num;}

	BIGINT operator=(const long long num){
		s.clear()
		do
		{
			s.push_back(num%WIDE);
			num/=BASE;
		}while(num);
		return *this;
	}
    BIGINT operator=(const string& str){
		s.clear();
		int x,len=(str.size()-1)/WIDTH + 1;
		for(int i=0;i<len;i++){
			int end=str.size()-i*WIDTH;
			int begin=max(0,end-WIDTH);
			sscanf(str.substr(begin,end-begin).c_str(),"%d",&x);
			s.push_back(x);
		}
		return *this;
	}
	
	bool operator<(const BIGINT b) const{
		if(s.size()!=b.s.size()) return s.size()<b.s.size();
		int i=s.size();
		while(--i>=0) if(s[i]!=b.s[i]) return s[i]<b[i];
		return 0;
	}
	bool operator>=(const BIGINT b) const{return !(*this<b);}
	bool operator>(const BIGINT b)  const{return b<*this;}
	bool operator<=(const BIGINT b) const{return !(b<*this);}
	bool operator!=(const BIGINT b) const{return b<*this||*this<b;}
	bool operator==(const BIGINT b) const{return !(b!=*this);}

	BIGINT operator+(const BIGINT& b) const {
		BIGINT c;	
		c.s.clear();
		for(int i=0,g=0; ;i++){
			if(g==0 && i>=s.size() && i>=b.s.size()) break;
			int x=g;
			if(i<s.size()) x+=s[i];
			if(i<b.s.size()) x+=b.s[i];
			c.s.push_back(x % BASE);
			g=x/BASE;
		}
		return c;
	}
	BIGINT operator+=(const BIGINT& b) const {
		*this=*this+b;
		return *this;
	}
	BIGINT operator-(const BIGINT& b) const {
		BIGINT c
		c.s.clear();
		vector<int>::iterator it;
		if(*this>b){
		   	for(it=b.s.begin();it!=b.s.end();++it)
				c.s.push_back(-(*it));
			c+=a;
		}else if(*this<b){
		   	for(it=s.begin();it!=s.end();++it)
				c.s.push_back(-(*it));
			c+=b;
			c.s[c.s.size()-1]=-c.s[c.s.size()-1];
		}
		if(*this==b) c.s.push_back(0);
		return c;
	}
	BIGINT operator*(const BIGINT& b) const {
	
	
	}
	BIGINT operator/(const BIGINT& b) const {


	}
	BIGINT operator%(const BIGINT& b) const {


	}
};
