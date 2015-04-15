//#include<bits/stdc++.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<assert.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
inline int len(int n){	//返回数字长度
	if(!n) return 1;
	return (int)log10(n)+1;
}

class BigInt{
public:
	static const int BASE=1000;
	static const int LEN=4;
	vector<int> s;	//若改BASE则改为long long 
   	int sign;

	//构造
	BigInt();
	BigInt(int);
	BigInt(long long);  //隐式转换 不需要再写其后面操作
	BigInt(const char *);
	//转化
	string toStr() const;
	//输入输出
	friend istream& operator>>(istream &,BigInt &);
	friend ostream& operator<<(ostream &,const BigInt &);
	//赋值
	BigInt operator=(int);
	BigInt operator=(long long);
	BigInt operator=(const char*);
	BigInt operator=(const string&);
	//比较
	bool operator<(const BigInt&) const;
	bool operator<=(const BigInt&) const;
	bool operator>(const BigInt&) const;
	bool operator>=(const BigInt&) const;
	bool operator==(const BigInt&) const;
	bool operator!=(const BigInt&) const;
	//四则运算
	BigInt operator+(const BigInt&) const;
	BigInt operator++();
	BigInt operator++(int);
	BigInt operator+=(const BigInt&);

	BigInt operator-(const BigInt&) const;
	BigInt operator--();
	BigInt operator--(int);
	BigInt operator-=(const BigInt&);

	BigInt operator*(const BigInt&) const;
	BigInt operator*=(const BigInt&);

	BigInt div(const int) const;			//高除单
	BigInt operator/(const BigInt&) const;  //高除高
	BigInt operator/=(const BigInt&);

	//四则衍生运算
	BigInt operator%(const BigInt&) const;
	BigInt operator%=(const BigInt&) ;

	BigInt pow(const BigInt&) const;
	BigInt sqrt() const;  //向下取整
	BigInt factorial() const;

	//More ...
	BigInt neg() const; //取负
	BigInt ABS() const; //绝对值
	int len() const;	//长度
};
//特殊处理
string NoLeadZero(const string&);	//消除字符串的前导0

//构造部分
BigInt::BigInt() {
	s.clear();
	sign=0;
};
BigInt::BigInt(int n) {*this=n; }
BigInt::BigInt(long long n){ *this=n; }
BigInt::BigInt(const char *s){ *this=s; }

//赋值部分
BigInt BigInt:: operator=(int n) {
	s.clear();
	if(n!=0) sign=(n>0)?1:-1;
	else sign=0;
	n=abs(n);
	do{
		s.push_back(n%BASE);
		n/=BASE;
	} while(n);
	return *this;
}
BigInt BigInt:: operator=(long long n) {
	s.clear();
	if(n!=0) sign=(n>0?1:-1);
	else sign=0;
	n=abs(n);
	do{
		s.push_back(n%BASE);
		n/=BASE;
	} while(n);
	return *this;
}

BigInt BigInt::operator=(const string& str) { //ss
	s.clear();
	//string str=NoLeadZero(ss);
	if(str.size()!=1)sign=(str[0]=='-'?-1:1);
	else sign=(str[0]=='0')?0:1;
	int len=str.length()-(sign==-1?1:0);
	for(int i=0;i<(len -1)/LEN+1;++i){
		int end=str.length()-i*LEN;
		int start=max((len!=str.length()),end-LEN);
		int temp;
		sscanf(str.substr(start,end-start).c_str(),"%d",&temp);
		s.push_back(temp);
	}
	return *this;
}

BigInt BigInt::operator=(const char* str) {
	s.clear();
	int size=strlen(str);
	if(size!=1) sign=(str[0]=='-'?-1:1);
	else sign=(str[0]=='0')?0:1;
	int len=size-(sign==-1?1:0);
	for(int i=0;i<(len -1)/LEN+1;++i){
		int end=size-i*LEN;
		int start=max((len!=size),end-LEN);
		int temp;
		char st[10];
		strncpy(st,str+start,end-start);
		st[end-start]='\0';
		sscanf(st,"%d",&temp);
		s.push_back(temp);
	}
	return *this;
}


//转化部分
string BigInt::toStr() const {
	string res;
	char ss[10];
	res="";
	sprintf(ss,"%d",s[s.size()-1]);
	res=res+ss;
	for(int i=s.size()-2;i>=0;--i){
		sprintf(ss,"%04d",s[i]); //视BASE而定
		res=res+ss;
	}
	if(sign<0) res="-"+res;
	return res;
}

//输入输出
istream &operator>>(istream &in,BigInt &n) {
	string str;
	in>>str;
	n=str;
	return in;
}

ostream &operator<<(ostream &out,const BigInt &n) {
	out<<n.toStr();
	return out;
}

//比较部分
bool BigInt::operator<(const BigInt& rhs) const{
    if(sign!=rhs.sign) return sign<rhs.sign;
	if(sign>=0){
		if(s.size()!=rhs.s.size()) return s.size()<rhs.s.size();
		else for(int i=s.size()-1;i>=0;--i) if(s[i]!=rhs.s[i]) return s[i]<rhs.s[i];
	}
	else{
		if(s.size()!=rhs.s.size()) return s.size()>rhs.s.size();
		else for(int i=s.size()-1;i>=0;--i) if(s[i]!=rhs.s[i]) return s[i]>rhs.s[i];
	}
	return false;
}
bool BigInt::operator>(const BigInt& rhs) const { return rhs<*this; }
bool BigInt::operator<=(const BigInt& rhs) const{ return !(rhs<*this); }
bool BigInt::operator>=(const BigInt& rhs) const{ return !(*this<rhs); }
bool BigInt::operator!=(const BigInt& rhs) const{ return *this>rhs || *this<rhs; }
bool BigInt::operator==(const BigInt& rhs) const{ return !(*this>rhs) && !(*this<rhs); }

//运算部分
BigInt BigInt::operator+(const BigInt& b) const{
	if(sign==0) return b;
	if(b.sign==0) return *this;
	BigInt res;
	switch(sign+b.sign){
		case 0:if(sign==-1) return b-(*this).neg();
				else return *this-b.neg();break;
		case  2:res.sign=1;break;
		case -2:res.sign=-1;break;
	}
	res.s.clear();
	for(int i=0,g=0;;++i){
		if(g==0 && i>=s.size() && i>=b.s.size()) break;
		int x=g;
		if(i<s.size()) x+=s[i];
		if(i<b.s.size()) x+=b.s[i];
		res.s.push_back(x%BASE);
		g=x/BASE;
	}
	return res;
}
BigInt BigInt::operator++(){
	*this=*this+1;
	return *this;
};
BigInt BigInt::operator++(int){
	BigInt old=*this;
	*this=*this+1;
	return old;
};
BigInt BigInt::operator+=(const BigInt& rhs){
	*this=*this+rhs;
	return *this;
};

BigInt BigInt:: operator-(const BigInt& c) const{
	if(sign==0) return c.neg();
	if(c.sign==0) return *this;
	if(*this==c) return 0;
	BigInt res,a=*this,b=c;
	switch(a.sign+b.sign){
		case 0:return a + b.neg();break;
		case 2:if(a.ABS()<b.ABS()){ res.sign=-1;swap(a,b);}
				   else res.sign=1;break;
		case -2:if(b.ABS()<a.ABS()) res.sign=-1;
					else{ res.sign=1;swap(a,b);} break;
	}
	res.s.clear();
	for(int i=0,g=0;;++i){
		if(i>=a.s.size() && g==0) break;
		int x=g;
		if(i<a.s.size()) x+=a.s[i];
		if(i<b.s.size()) x-=b.s[i];
		if(x!=0 || (x==0 && i<a.s.size()-1))
			res.s.push_back((x+BASE)%BASE);

		g=-(-x+BASE-1)/BASE;
	}
	return res;
}
BigInt BigInt:: operator--(){
	*this=*this-1;
	return *this;
}

BigInt BigInt:: operator--(int){
	BigInt old=*this;
	*this=*this-1;
	return old;
}
BigInt BigInt:: operator-=(const BigInt& rhs){
	*this=*this-rhs;
	return *this;
}

BigInt BigInt::operator*(const BigInt& b) const{
	if(sign==0 || b.sign==0) return 0;
	BigInt res;
	res.sign=sign*b.sign;
	res.s.resize(s.size()+b.s.size(),0);
	for(int i=0;i<s.size();++i)
		for(int j=0;j<b.s.size();++j){
			long long t=s[i]*b.s[j];
			res.s[i+j+1]+=(res.s[i+j]+t)/BASE;
			res.s[i+j]=(res.s[i+j]+t)%BASE;
		}
	int cnt=res.s.size()-1;
	while(!res.s[cnt]) --cnt;
	res.s.resize(cnt+1);
	return res;
}

BigInt BigInt::operator*=(const BigInt& rhs){
	*this=*this*rhs;
	return *this;
}

BigInt BigInt:: div(const int b) const {
	assert(b!=0);
	BigInt res=*this;
	if(res.sign==0) return 0;
	if(res.ABS()<abs(b)) return 0;
	res.sign*=b>0?1:-1;
	for(int i=res.s.size()-1,g=0;i>=0;--i){
		res.s[i]+=g*BASE;
		g=res.s[i]%b;
		res.s[i]/=b;
	}
	int cnt=res.s.size()-1;
	while(!res.s[cnt]) --cnt;
	res.s.resize(cnt+1);
	return res;
}

BigInt BigInt::operator/(const BigInt& b) const{
	assert(b!=0);
	if(sign==0) return 0;
	if(b.ABS()>(*this).ABS()) return 0;
	int sig=sign*b.sign;
	BigInt L=1,R=(*this).ABS();
	while(R>=L)
	{
		BigInt M=(R+L).div(2);
		if(b.ABS()*M>(*this).ABS()) R=M-1;
		else L=M+1;
	}
	R.sign=sign;
	return R;
}

BigInt BigInt::operator/=(const BigInt& rhs){
	*this=*this/rhs;
	return *this;
}

BigInt BigInt:: operator%(const BigInt& b) const{
	return *this-(*this/b)*b;
}
BigInt BigInt:: operator%=(const BigInt& rhs){
	*this=*this%rhs;
	return *this;
}

BigInt BigInt:: pow(const BigInt& n) const{
	BigInt res=1,i=1;
	for(i=0;i<n;++i) res=res*(*this);
	return res;
}

BigInt BigInt:: factorial() const{
	BigInt i,res=1;
	for(i=2;i<=*this;++i) res=res*i;
	return res;
};


BigInt BigInt:: sqrt() const { //向下取整
	if(sign==0) return 0;
	assert(sign>0);
	int len=(*this).len();
	string s1,s2;
	s1=s2="1";
	for(int i=(len/2-3);i>0;--i) s1+="0";
	for(int i=(len/2+2);i>0;--i) s2+="0";
	BigInt L,R;
	L=s1,R=s2;
	while(R>=L){
		BigInt M=(L+R).div(2);
		if(M*M>*this) R=M-1;
		else L=M+1;
	}
	R.sign=1;
	return R;
}

BigInt BigInt::neg() const {
	BigInt a=*this;
	a.sign=-sign;
	return a;
}

BigInt BigInt::ABS() const {
	BigInt a=*this;
	if(sign) a.sign=1;
	return a;
}
int BigInt::len() const {
	if(!s.size()) return 0;
	return(::len(s[s.size()-1])+LEN*(s.size()-1));
}

//特殊情况处理
string NoLeadZero(const string& s) {	//消除字符串的前导0
	string res="";
	int	t=0;
	if(s[t]=='-') ++t,res="-";
	while(t<s.size()-1 && s[t]=='0') ++t;
	res+=s.substr(t,s.size());
	return res;
}

string NoLeadZero(const char* str) {	//消除字符串的前导0
	string res="",s=str;
	int	t=0;
	if(s[t]=='-') ++t,res="-";
	while(t<s.size()-1 && s[t]=='0') ++t;
	res+=s.substr(t,s.size());
	return res;
}

int main()
{
   	//freopen("test.txt","r",stdin);
	//ios::sync_with_stdio(false);
	BigInt a;
	while(cin>>a){
		if(a<BigInt::BASE) printf("%d\n",(int)sqrt(a.s[0]));
		else cout<<a.sqrt()<<endl;
	}
	return 0;
}
