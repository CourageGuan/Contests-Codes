#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
using namespace std;


#define F(i,a,b) for(int i=a;i<=b;i++)
int n;

int deal(string s,string ss)
{
    int res=0;
    F(i,0,ss.size()-1)
    if(s[i]!=ss[i])
    {
    res++;
    if (res>n) return 100;
    }
    return res;
}

int main()
{
    //freopen("test","r",stdin);
    std::ios::sync_with_stdio(false);
    string s1,s2;
    int t=0;
    while(cin>>s1>>s2>>n)
    {
        if(t++) cout<<endl;
        int ans=0;
        if (s2.size()>s1.size()||n==0)  cout<<0;
        else{
            F(i,0,s1.size()-s2.size()) if(deal(s1.substr(i,s2.size()),s2)<=n) ans++;
            cout<<ans;
        }
    }
    return 0;
}
